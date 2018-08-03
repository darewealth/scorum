#include <scorum/chain/evaluators/post_game_results_evaluator.hpp>
#include <scorum/chain/data_service_factory.hpp>
#include <scorum/chain/services/account.hpp>
#include <scorum/chain/services/betting_service.hpp>
#include <scorum/chain/services/game.hpp>
#include <scorum/protocol/betting/wincase.hpp>
#include <scorum/protocol/betting/wincase_comparison.hpp>

#include <boost/algorithm/cxx11/any_of.hpp>
#include <boost/range/adaptor/filtered.hpp>

namespace scorum {
namespace chain {
post_game_results_evaluator::post_game_results_evaluator(data_service_factory_i& services)
    : evaluator_impl<data_service_factory_i, post_game_results_evaluator>(services)
    , _account_service(services.account_service())
    , _betting_service(services.betting_service())
    , _game_service(services.game_service())
{
}

void post_game_results_evaluator::do_apply(const operation_type& op)
{
    _account_service.check_account_existence(op.moderator);
    auto is_moder = _betting_service.is_betting_moderator(op.moderator);
    FC_ASSERT(is_moder, "User ${u} isn't a betting moderator", ("u", op.moderator));

    auto game_obj = _game_service.find(op.game_id);
    FC_ASSERT(game_obj, "Game with id '${g}' doesn't exist", ("g", op.game_id));

    FC_ASSERT(game_obj->status == game_status::started, "The game is not started yet");

    validate_winners(*game_obj, op.wincases);

    _game_service.finish(*game_obj, op.wincases);
}

void post_game_results_evaluator::validate_winners(const game_object& game,
                                                   const fc::flat_set<betting::wincase_type>& winners) const
{
    std::equal_to<betting::wincase_type> eq_cmp;

    for (const auto& market : game.markets)
    {
        auto two_state_wincases = boost::adaptors::filter(market.wincases, [](const auto& pair) {
            return pair.first.visit([](const auto& w) { return !w.has_trd_state(); });
        });
        for (const auto& pair : two_state_wincases)
        {
            auto exists = boost::algorithm::any_of(
                winners, [&](const auto& w) { return eq_cmp(pair.first, w) || eq_cmp(pair.second, w); });

            FC_ASSERT(exists, "Wincase winners list do not contain neither '${1}' nor '${2}'",
                      ("1", pair.first)("2", pair.second));
        }
    }
}
}
}

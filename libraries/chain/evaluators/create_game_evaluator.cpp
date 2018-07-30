#include <scorum/chain/evaluators/create_game_evaluator.hpp>
#include <scorum/chain/data_service_factory.hpp>
#include <scorum/chain/services/account.hpp>
#include <scorum/chain/services/dynamic_global_property.hpp>
#include <scorum/chain/services/betting_service.hpp>
#include <scorum/chain/services/game.hpp>

namespace scorum {
namespace chain {
create_game_evaluator::create_game_evaluator(data_service_factory_i& services)
    : evaluator_impl<data_service_factory_i, create_game_evaluator>(services)
    , _account_service(services.account_service())
    , _dprops_service(services.dynamic_global_property_service())
    , _betting_service(services.betting_service())
    , _game_service(services.game_service())
{
}

void create_game_evaluator::do_apply(const operation_type& op)
{
    FC_ASSERT(op.start > _dprops_service.head_block_time(), "Game should start after head block time");
    FC_ASSERT(!_game_service.find(op.name), "Game with name '${g}' already exists", ("g", op.name));

    _account_service.check_account_existence(op.moderator);
    auto is_moder = _betting_service.is_betting_moderator(op.moderator);
    FC_ASSERT(is_moder, "User ${u} isn't a betting moderator", ("u", op.moderator));

    _game_service.create(op.moderator, op.name, op.start, op.game, op.markets);
}
}
}
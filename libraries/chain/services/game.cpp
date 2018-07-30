#include <scorum/chain/services/game.hpp>
#include <scorum/chain/database/database.hpp>

namespace scorum {
namespace chain {

dbs_game::dbs_game(database& db)
    : base_service_type(db)
{
}

const game_object& dbs_game::create(const account_name_type& moderator,
                                    const std::string& game_name,
                                    fc::time_point_sec start,
                                    const betting::game_type& game,
                                    const std::vector<betting::market_type>& markets)
{
    return dbs_service_base<game_service_i>::create([&](game_object& obj) {
        obj.moderator = moderator;
        fc::from_string(obj.name, game_name);
        obj.start = start;
        obj.game = game;

        for (const auto& m : markets)
            obj.markets.emplace_back(m);
    });
}

const game_object* dbs_game::find(const std::string& game_name) const
{
    return find_by<by_name>(game_name);
}

} // namespace scorum
} // namespace chain

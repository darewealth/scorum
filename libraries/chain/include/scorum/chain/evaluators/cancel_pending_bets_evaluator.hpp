#pragma once
#include <scorum/protocol/scorum_operations.hpp>
#include <scorum/chain/evaluators/evaluator.hpp>

namespace scorum {
namespace chain {

struct account_service_i;
struct pending_bet_service_i;
struct betting_service_i;

class cancel_pending_bets_evaluator : public evaluator_impl<data_service_factory_i, cancel_pending_bets_evaluator>
{
public:
    using operation_type = scorum::protocol::cancel_pending_bets_operation;

    cancel_pending_bets_evaluator(data_service_factory_i& services, betting_service_i&);

    void do_apply(const operation_type& op);

private:
    account_service_i& _account_service;
    pending_bet_service_i& _pending_bet_svc;
    betting_service_i& _betting_svc;
};
}
}

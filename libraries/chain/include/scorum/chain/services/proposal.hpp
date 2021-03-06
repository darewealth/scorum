#pragma once

#include <scorum/chain/services/service_base.hpp>
#include <scorum/chain/schema/proposal_object.hpp>

namespace scorum {
namespace chain {

struct proposal_service_i : public base_service_i<proposal_object>
{
    using base_service_i<proposal_object>::get;
    using base_service_i<proposal_object>::is_exists;

    virtual const proposal_object& create_proposal(const account_name_type& creator,
                                                   const protocol::proposal_operation& operation,
                                                   const fc::time_point_sec& expiration,
                                                   uint64_t quorum)
        = 0;

    virtual bool is_exists(proposal_id_type proposal_id) = 0;

    virtual const proposal_object& get(proposal_id_type proposal_id) = 0;

    virtual void vote_for(const account_name_type& voter, const proposal_object& proposal) = 0;

    virtual size_t get_votes(const proposal_object& proposal) = 0;

    virtual bool is_expired(const proposal_object& proposal) = 0;

    virtual void clear_expired_proposals() = 0;

    virtual void for_all_proposals_remove_from_voting_list(const account_name_type& member) = 0;

    using proposal_refs_type = std::vector<proposal_object::cref_type>;

    virtual proposal_refs_type get_proposals() = 0;
};

class dbs_proposal : public dbs_service_base<proposal_service_i>
{
    friend class dbservice_dbs_factory;

protected:
    explicit dbs_proposal(database& db);

public:
    using base_service_i<proposal_object>::get;
    using base_service_i<proposal_object>::is_exists;

    virtual const proposal_object& create_proposal(const account_name_type& creator,
                                                   const protocol::proposal_operation& operation,
                                                   const fc::time_point_sec& expiration,
                                                   uint64_t quorum) override;

    bool is_exists(proposal_id_type proposal_id) override;

    const proposal_object& get(proposal_id_type proposal_id) override;

    void vote_for(const account_name_type& voter, const proposal_object& proposal) override;

    size_t get_votes(const proposal_object& proposal) override;

    bool is_expired(const proposal_object& proposal) override;

    void clear_expired_proposals() override;

    void for_all_proposals_remove_from_voting_list(const account_name_type& member) override;

    proposal_refs_type get_proposals() override;
};

} // namespace scorum
} // namespace chain

#pragma once

#include <scorum/chain/services/service_base.hpp>
#include <scorum/chain/schema/budget_objects.hpp>

#include <boost/lambda/lambda.hpp>
#include <boost/multi_index/detail/unbounded.hpp>

namespace scorum {
namespace chain {

struct fund_budget_service_i : public base_service_i<fund_budget_object>
{
};

using dbs_fund_budget = dbs_service_base<fund_budget_service_i>;

template <class ObjectType> struct owned_base_budget_service_i : public base_service_i<ObjectType>
{
    using budget_cref_type = typename base_service_i<ObjectType>::object_cref_type;

    using budgets_type = std::vector<budget_cref_type>;

    virtual const ObjectType& get(const typename ObjectType::id_type&) const = 0;
    virtual budgets_type get_budgets() const = 0;
    virtual budgets_type get_budgets_by_start_time(const fc::time_point_sec& until) const = 0;
    virtual std::set<std::string> lookup_budget_owners(const std::string& lower_bound_owner_name,
                                                       uint32_t limit) const = 0;
    virtual budgets_type get_budgets(const account_name_type& owner) const = 0;
};

template <class InterfaceType, class ObjectType> class dbs_owned_base_budget : public dbs_service_base<InterfaceType>
{
    friend class dbservice_dbs_factory;

protected:
    explicit dbs_owned_base_budget(database& db)
        : dbs_service_base<InterfaceType>(db)
    {
    }

public:
    const ObjectType& get(const typename ObjectType::id_type& id) const override
    {
        try
        {
            return this->get_by(id);
        }
        FC_CAPTURE_AND_RETHROW((id))
    }

    typename InterfaceType::budgets_type get_budgets() const override
    {
        typename InterfaceType::budgets_type ret;

        const auto& idx = this->db_impl().template get_index<budget_index<ObjectType>>().indices();

        for (auto it = idx.cbegin(), it_end = idx.cend(); it != it_end; ++it)
        {
            ret.push_back(std::cref(*it));
        }

        return ret;
    }

    typename InterfaceType::budgets_type get_budgets_by_start_time(const fc::time_point_sec& until) const override
    {
        try
        {
            return this->template get_range_by<by_start_time>(::boost::multi_index::unbounded,
                                                              ::boost::lambda::_1 <= std::make_tuple(until, ALL_IDS));
        }
        FC_CAPTURE_AND_RETHROW((until))
    }

    std::set<std::string> lookup_budget_owners(const std::string& lower_bound_owner_name, uint32_t limit) const override
    {
        try
        {
            std::set<std::string> result;

            const auto& budgets_by_owner_name = this->db_impl()
                                                    .template get_index<budget_index<ObjectType>>()
                                                    .indices()
                                                    .template get<by_owner_name>();

            // prepare output if limit > 0
            for (auto itr = budgets_by_owner_name.lower_bound(lower_bound_owner_name);
                 limit && itr != budgets_by_owner_name.end(); ++itr)
            {
                --limit;
                result.insert(itr->owner);
            }
            return result;
        }
        FC_CAPTURE_AND_RETHROW((lower_bound_owner_name)(limit))
    }

    typename InterfaceType::budgets_type get_budgets(const account_name_type& owner) const override
    {
        try
        {
            typename InterfaceType::budgets_type ret;

            auto it_pair = this->db_impl()
                               .template get_index<budget_index<ObjectType>>()
                               .indices()
                               .template get<by_owner_name>()
                               .equal_range(owner);

            for (auto it = it_pair.first, it_end = it_pair.second; it != it_end; ++it)
            {
                ret.push_back(std::cref(*it));
            }

            return ret;
        }
        FC_CAPTURE_AND_RETHROW((owner))
    }
};

struct banner_budget_service_i : public owned_base_budget_service_i<banner_budget_object>
{
};

using dbs_banner_budget = dbs_owned_base_budget<banner_budget_service_i, banner_budget_object>;

struct post_budget_service_i : public owned_base_budget_service_i<post_budget_object>
{
};

using dbs_post_budget = dbs_owned_base_budget<post_budget_service_i, post_budget_object>;

} // namespace chain
} // namespace scorum

#include <scorum/protocol/get_config.hpp>
#include <scorum/protocol/config.hpp>
#include <scorum/protocol/asset.hpp>
#include <scorum/protocol/types.hpp>
#include <scorum/protocol/version.hpp>

namespace scorum { namespace protocol {

fc::variant_object get_config()
{
   fc::mutable_variant_object result;

#ifdef IS_TEST_NET
   result[ "IS_TEST_NET" ] = true;
#else
   result[ "IS_TEST_NET" ] = false;
#endif

   result["SCORUM_100_PERCENT"] = SCORUM_100_PERCENT;
   result["SCORUM_1_PERCENT"] = SCORUM_1_PERCENT;
   result["SCORUM_1_TENTH_PERCENT"] = SCORUM_1_TENTH_PERCENT;
   result["SCORUM_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD"] = SCORUM_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD;
   result["SCORUM_ADDRESS_PREFIX"] = SCORUM_ADDRESS_PREFIX;
   result["SCORUM_APR_PERCENT_MULTIPLY_PER_BLOCK"] = SCORUM_APR_PERCENT_MULTIPLY_PER_BLOCK;
   result["SCORUM_APR_PERCENT_MULTIPLY_PER_HOUR"] = SCORUM_APR_PERCENT_MULTIPLY_PER_HOUR;
   result["SCORUM_APR_PERCENT_MULTIPLY_PER_ROUND"] = SCORUM_APR_PERCENT_MULTIPLY_PER_ROUND;
   result["SCORUM_APR_PERCENT_SHIFT_PER_BLOCK"] = SCORUM_APR_PERCENT_SHIFT_PER_BLOCK;
   result["SCORUM_APR_PERCENT_SHIFT_PER_HOUR"] = SCORUM_APR_PERCENT_SHIFT_PER_HOUR;
   result["SCORUM_APR_PERCENT_SHIFT_PER_ROUND"] = SCORUM_APR_PERCENT_SHIFT_PER_ROUND;
   result["SCORUM_BANDWIDTH_AVERAGE_WINDOW_SECONDS"] = SCORUM_BANDWIDTH_AVERAGE_WINDOW_SECONDS;
   result["SCORUM_BANDWIDTH_PRECISION"] = SCORUM_BANDWIDTH_PRECISION;
   result["SCORUM_BLOCKCHAIN_PRECISION"] = SCORUM_BLOCKCHAIN_PRECISION;
   result["SCORUM_BLOCKCHAIN_PRECISION_DIGITS"] = SCORUM_BLOCKCHAIN_PRECISION_DIGITS;
   result["SCORUM_BLOCKCHAIN_HARDFORK_VERSION"] = SCORUM_BLOCKCHAIN_HARDFORK_VERSION;
   result["SCORUM_BLOCKCHAIN_VERSION"] = SCORUM_BLOCKCHAIN_VERSION;
   result["SCORUM_BLOCK_INTERVAL"] = SCORUM_BLOCK_INTERVAL;
   result["SCORUM_BLOCKS_PER_DAY"] = SCORUM_BLOCKS_PER_DAY;
   result["SCORUM_BLOCKS_PER_HOUR"] = SCORUM_BLOCKS_PER_HOUR;
   result["SCORUM_BLOCKS_PER_YEAR"] = SCORUM_BLOCKS_PER_YEAR;
   result["SCORUM_CASHOUT_WINDOW_SECONDS"] = SCORUM_CASHOUT_WINDOW_SECONDS;
   result["SCORUM_CHAIN_ID"] = SCORUM_CHAIN_ID;
   result["SCORUM_COMMENT_REWARD_FUND_NAME"] = SCORUM_COMMENT_REWARD_FUND_NAME;
   result["SCORUM_CONTENT_APR_PERCENT"] = SCORUM_CONTENT_APR_PERCENT;
   result["SCORUM_CONTENT_REWARD_PERCENT"] = SCORUM_CONTENT_REWARD_PERCENT;
   result["SCORUM_CONVERSION_DELAY"] = SCORUM_CONVERSION_DELAY;
   result["SCORUM_CREATE_ACCOUNT_DELEGATION_RATIO"] = SCORUM_CREATE_ACCOUNT_DELEGATION_RATIO;
   result["SCORUM_CREATE_ACCOUNT_DELEGATION_TIME"] = SCORUM_CREATE_ACCOUNT_DELEGATION_TIME;
   result["SCORUM_CREATE_ACCOUNT_WITH_SCORUM_MODIFIER"] = SCORUM_CREATE_ACCOUNT_WITH_SCORUM_MODIFIER;
   result["SCORUM_GENESIS_TIME"] = SCORUM_GENESIS_TIME;
   result["SCORUM_HARDFORK_REQUIRED_WITNESSES"] = SCORUM_HARDFORK_REQUIRED_WITNESSES;
   result["SCORUM_INFLATION_NARROWING_PERIOD"] = SCORUM_INFLATION_NARROWING_PERIOD;
   result["SCORUM_INFLATION_RATE_START_PERCENT"] = SCORUM_INFLATION_RATE_START_PERCENT;
   result["SCORUM_INFLATION_RATE_STOP_PERCENT"] = SCORUM_INFLATION_RATE_STOP_PERCENT;
   result["SCORUM_INIT_DELEGATE_NAME"] = SCORUM_INIT_DELEGATE_NAME;
   result["SCORUM_INIT_PUBLIC_KEY_STR"] = SCORUM_INIT_PUBLIC_KEY_STR;
#if 0
   // do not expose private key, period.
   // we need this line present but inactivated so CI check for all constants in config.hpp doesn't complain.
   result["SCORUM_INIT_PRIVATE_KEY"] = SCORUM_INIT_PRIVATE_KEY;
#endif
   result["SCORUM_INIT_TIME"] = SCORUM_INIT_TIME;
   result["SCORUM_IRREVERSIBLE_THRESHOLD"] = SCORUM_IRREVERSIBLE_THRESHOLD;
   result["SCORUM_MAX_ACCOUNT_NAME_LENGTH"] = SCORUM_MAX_ACCOUNT_NAME_LENGTH;
   result["SCORUM_MAX_ACCOUNT_WITNESS_VOTES"] = SCORUM_MAX_ACCOUNT_WITNESS_VOTES;
   result["SCORUM_MAX_ASSET_WHITELIST_AUTHORITIES"] = SCORUM_MAX_ASSET_WHITELIST_AUTHORITIES;
   result["SCORUM_MAX_AUTHORITY_MEMBERSHIP"] = SCORUM_MAX_AUTHORITY_MEMBERSHIP;
   result["SCORUM_MAX_BLOCK_SIZE"] = SCORUM_MAX_BLOCK_SIZE;
   result["SCORUM_MAX_COMMENT_DEPTH"] = SCORUM_MAX_COMMENT_DEPTH;
   result["SCORUM_MAX_FEED_AGE_SECONDS"] = SCORUM_MAX_FEED_AGE_SECONDS;
   result["SCORUM_MAX_INSTANCE_ID"] = SCORUM_MAX_INSTANCE_ID;
   result["SCORUM_MAX_MEMO_SIZE"] = SCORUM_MAX_MEMO_SIZE;
   result["SCORUM_MAX_WITNESSES"] = SCORUM_MAX_WITNESSES;
   result["SCORUM_MAX_PERMLINK_LENGTH"] = SCORUM_MAX_PERMLINK_LENGTH;
   result["SCORUM_MAX_PROXY_RECURSION_DEPTH"] = SCORUM_MAX_PROXY_RECURSION_DEPTH;
   result["SCORUM_MAX_RESERVE_RATIO"] = SCORUM_MAX_RESERVE_RATIO;
   result["SCORUM_MAX_RUNNER_WITNESSES"] = SCORUM_MAX_RUNNER_WITNESSES;
   result["SCORUM_MAX_SHARE_SUPPLY"] = SCORUM_MAX_SHARE_SUPPLY;
   result["SCORUM_MAX_SIG_CHECK_DEPTH"] = SCORUM_MAX_SIG_CHECK_DEPTH;
   result["SCORUM_MAX_TIME_UNTIL_EXPIRATION"] = SCORUM_MAX_TIME_UNTIL_EXPIRATION;
   result["SCORUM_MAX_TRANSACTION_SIZE"] = SCORUM_MAX_TRANSACTION_SIZE;
   result["SCORUM_MAX_UNDO_HISTORY"] = SCORUM_MAX_UNDO_HISTORY;
   result["SCORUM_MAX_URL_LENGTH"] = SCORUM_MAX_URL_LENGTH;
   result["SCORUM_MAX_VOTE_CHANGES"] = SCORUM_MAX_VOTE_CHANGES;
   result["SCORUM_MAX_VOTED_WITNESSES"] = SCORUM_MAX_VOTED_WITNESSES;
   result["SCORUM_MAX_WITHDRAW_ROUTES"] = SCORUM_MAX_WITHDRAW_ROUTES;
   result["SCORUM_MAX_WITNESS_URL_LENGTH"] = SCORUM_MAX_WITNESS_URL_LENGTH;
   result["SCORUM_MIN_ACCOUNT_CREATION_FEE"] = SCORUM_MIN_ACCOUNT_CREATION_FEE;
   result["SCORUM_MIN_ACCOUNT_NAME_LENGTH"] = SCORUM_MIN_ACCOUNT_NAME_LENGTH;
   result["SCORUM_MIN_BLOCK_SIZE_LIMIT"] = SCORUM_MIN_BLOCK_SIZE_LIMIT;
   result["SCORUM_MIN_CONTENT_REWARD"] = SCORUM_MIN_CONTENT_REWARD;
   result["SCORUM_MIN_CURATE_REWARD"] = SCORUM_MIN_CURATE_REWARD;
   result["SCORUM_MIN_PERMLINK_LENGTH"] = SCORUM_MIN_PERMLINK_LENGTH;
   result["SCORUM_MIN_REPLY_INTERVAL"] = SCORUM_MIN_REPLY_INTERVAL;
   result["SCORUM_MIN_ROOT_COMMENT_INTERVAL"] = SCORUM_MIN_ROOT_COMMENT_INTERVAL;
   result["SCORUM_MIN_VOTE_INTERVAL_SEC"] = SCORUM_MIN_VOTE_INTERVAL_SEC;
   result["SCORUM_MIN_FEEDS"] = SCORUM_MIN_FEEDS;
   result["SCORUM_MINING_REWARD"] = SCORUM_MINING_REWARD;
   result["SCORUM_MIN_PAYOUT"] = SCORUM_MIN_PAYOUT;
   result["SCORUM_MIN_POW_REWARD"] = SCORUM_MIN_POW_REWARD;
   result["SCORUM_MIN_PRODUCER_REWARD"] = SCORUM_MIN_PRODUCER_REWARD;
   result["SCORUM_MIN_TRANSACTION_EXPIRATION_LIMIT"] = SCORUM_MIN_TRANSACTION_EXPIRATION_LIMIT;
   result["SCORUM_MIN_UNDO_HISTORY"] = SCORUM_MIN_UNDO_HISTORY;
   result["SCORUM_NULL_ACCOUNT"] = SCORUM_NULL_ACCOUNT;
   result["SCORUM_NUM_INIT_DELEGATES"] = SCORUM_NUM_INIT_DELEGATES;
   result["SCORUM_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM"] = SCORUM_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM;
   result["SCORUM_OWNER_AUTH_RECOVERY_PERIOD"] = SCORUM_OWNER_AUTH_RECOVERY_PERIOD;
   result["SCORUM_OWNER_UPDATE_LIMIT"] = SCORUM_OWNER_UPDATE_LIMIT;
   result["SCORUM_POST_REWARD_FUND_NAME"] = SCORUM_POST_REWARD_FUND_NAME;
   result["SCORUM_POW_APR_PERCENT"] = SCORUM_POW_APR_PERCENT;
   result["SCORUM_PRODUCER_APR_PERCENT"] = SCORUM_PRODUCER_APR_PERCENT;
   result["SCORUM_PROXY_TO_SELF_ACCOUNT"] = SCORUM_PROXY_TO_SELF_ACCOUNT;
   result["SCORUM_SECONDS_PER_YEAR"] = SCORUM_SECONDS_PER_YEAR;
   result["SCORUM_RECENT_RSHARES_DECAY_RATE"] = SCORUM_RECENT_RSHARES_DECAY_RATE;
   result["SCORUM_REVERSE_AUCTION_WINDOW_SECONDS"] = SCORUM_REVERSE_AUCTION_WINDOW_SECONDS;
   result["SCORUM_ROOT_POST_PARENT"] = SCORUM_ROOT_POST_PARENT;
   result["SCORUM_SAVINGS_WITHDRAW_REQUEST_LIMIT"] = SCORUM_SAVINGS_WITHDRAW_REQUEST_LIMIT;
   result["SCORUM_SAVINGS_WITHDRAW_TIME"] = SCORUM_SAVINGS_WITHDRAW_TIME;
   result["SCORUM_SECOND_CASHOUT_WINDOW"] = SCORUM_SECOND_CASHOUT_WINDOW;
   result["SCORUM_SOFT_MAX_COMMENT_DEPTH"] = SCORUM_SOFT_MAX_COMMENT_DEPTH;
   result["SCORUM_START_MINER_VOTING_BLOCK"] = SCORUM_START_MINER_VOTING_BLOCK;
   result["SCORUM_START_VESTING_BLOCK"] = SCORUM_START_VESTING_BLOCK;
   result["SCORUM_TEMP_ACCOUNT"] = SCORUM_TEMP_ACCOUNT;
   result["SCORUM_UPVOTE_LOCKOUT"] = SCORUM_UPVOTE_LOCKOUT;
   result["SCORUM_VESTING_FUND_PERCENT"] = SCORUM_VESTING_FUND_PERCENT;
   result["SCORUM_VESTING_WITHDRAW_INTERVALS"] = SCORUM_VESTING_WITHDRAW_INTERVALS;
   result["SCORUM_VESTING_WITHDRAW_INTERVALS_PRE_HF_16"] = SCORUM_VESTING_WITHDRAW_INTERVALS_PRE_HF_16;
   result["SCORUM_VESTING_WITHDRAW_INTERVAL_SECONDS"] = SCORUM_VESTING_WITHDRAW_INTERVAL_SECONDS;
   result["SCORUM_VOTE_DUST_THRESHOLD"] = SCORUM_VOTE_DUST_THRESHOLD;
   result["SCORUM_VOTE_REGENERATION_SECONDS"] = SCORUM_VOTE_REGENERATION_SECONDS;
   result["SCORUM_SYMBOL"] = SCORUM_SYMBOL;
   result["VESTS_SYMBOL"] = VESTS_SYMBOL;
   result["VIRTUAL_SCHEDULE_LAP_LENGTH"] = VIRTUAL_SCHEDULE_LAP_LENGTH;
   result["VIRTUAL_SCHEDULE_LAP_LENGTH2"] = VIRTUAL_SCHEDULE_LAP_LENGTH2;

   return result;
}

} } // scorum::protocol

/**
*  @file
*  @copyright defined in xmax/LICENSE
*/
#pragma once
#include <tables/tablebase.hpp>

namespace chain
{
	DBOBJ_CLASS(Account, ChainObject::AccountObject)
	{
		DBOBJ_BODY(Account,
			(DB_SFIELD(AccountName, name))
		)
	};

	struct ByName;
	using AccountIndex = IndexedBy<Account,
		indexed::ordered_unique<indexed::tag<ByName>, indexed::member<Account, AccountName, &Account::name>>

	>;

	using AccountTable = Table<AccountIndex>;
}
#include "dci_ico.hpp"

// --------------------------------------------------------------------------------------------------------------------
void dciico::deposit( const name& buyer_ac, 
						const name& contract_ac, 
						const asset& quantity, 
						const string& memo ) {

	// check for conditions if either or both of these are true for `from` & `to`
	if(contract_ac != get_self() ||  buyer_ac == get_self()) {		// atleast one of the condition is true
		print("Either money is not sent to the contract or contract itself is the buyer.");
		return;
	}

	// Although this is checked in "toetoken::transfer" action, but fund_token_symbol check is pending. 
	// So, in addition the entire asset check is done using static func defined in "dciico.hpp" file.
	// check quantity is valid for all conditions as 'asset'
	check_quantity(quantity);

	// instantiate the `fund` table
	fund_index fund_table(get_self(), buyer_ac.value);
	auto fund_it = fund_table.find(ride_token_symbol.raw());

	// update (add/modify) the balance
	if(fund_it == fund_table.end()) {
		fund_table.emplace(get_self(), [&](auto& row) {
			row.balance = quantity;
			row.status = "deposited"_n;
		});
	} else {
		fund_table.modify(fund_it, get_self(), [&](auto& row) {
			row.balance += quantity;
			row.status = "deposited"_n;
		});
	}
	
}


// --------------------------------------------------------------------------------------------------------------------
void dciico::seticorate( const name& phase,
						float price_pereos )
{
	require_auth(get_self());

	check((phase == "a"_n) || (phase == "b") || (phase == "c"), "Phases can either be \'a\' or \'b\' or \'c\'.");

	icorate_index
}

// --------------------------------------------------------------------------------------------------------------------
void dciico::disburse(const name& receiver_ac,
								const name& phase,
								const asset& quantity,
								const string& memo )
{
	require_auth(get_self());

	check(is_account(receiver_ac), "receiver account doesn't exist");
	check( receiver_ac != get_self(), "amount can't be disbursed to contract itself");

	check((phase == "a"_n) || (phase == "b") || (phase == "c"), "Phases can either be \'a\' or \'b\' or \'c\'.");

	// check quantity is valid for all conditions as 'asset'
	check_quantity(quantity);

	check(memo.size() <= 256, "memo has more than 256 bytes");

	// instantiate the `fund` table
	fund_index fund_table(get_self(), receiver_ac.value);
	auto fund_it = fund_table.find(ride_token_symbol.raw());

	// Make sure that the receiver_ac has deposited in the table
	check( fund_it != fund_table.end(), "Sorry! There is no amount deposited by " + receiver_ac.to_string() + "in the ride wallet.");



}
// --------------------------------------------------------------------------------------------------------------------
void toeridewallet::sendalert(const name& user,
							const string& message) {
	require_auth(get_self());

	require_recipient(user);
}

void toeridewallet::send_alert(const name& user, 
							const string& message) {
	check(message.size() <= 256, "message has more than 256 bytes");
	
	action(
		permission_level(get_self(), "active"_n),
		get_self(),
		"sendalert"_n,
		std::make_tuple(user, message)
		).send();
}

// --------------------------------------------------------------------------------------------------------------------
void toeridewallet::sendreceipt(const name& user,
							const string& message) {
	require_auth(get_self());

	require_recipient(user);
}

void toeridewallet::send_receipt(const name& user, 
								const string& message) {
	check(message.size() <= 256, "message has more than 256 bytes");

	action(
		permission_level(get_self(), "active"_n),
		get_self(),
		"sendreceipt"_n,
		std::make_tuple(user, message)
		).send();
}

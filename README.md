# DCI Contracts
Suite of contracts for ICO on EOSIO Blockchain in 3 phases - A, B, C 

## Contracts
### [Token](./dcitoken)
A token contract for transferring token (as per the ICO rates) during ICO on EOSIO Blockchains.

#### Action
* `create`
* `issue`
* `transfer`

#### Table
* `accounts`
* `stat`


### [ICO](./dciico)

#### Action
* `deposit` (payable action)
* `disburse`

#### Table
* `fund`
* `rates`


## NOTES
* __Fund__ vs __Wallet__
	- Fund is where the amount gets added up in the stored value of table. E.g. used in "DCI" ICO contract.
	- Wallet is where the amount has to be deducted from the stored value in the table. E.g. used in "TOE" Wallet contract.
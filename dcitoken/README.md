# Token contract
## Brief
* It is a token contract which is to 
	- [x] create tokens with issuer & max_supply
	- [x] issue tokens to issuer only
	- [x] retire tokens from supply
	- [x] transfer tokens from one account to another
	- [x] open account with even zero balance
	- [x] close account with zero balance

## About
* contract name - `toetoken`
* contract's account name - `toe1111token`
* action
	- `create`
	- `issue`
	- `retire`
	- `transfer`
	- `open`
	- `close`
* table
	- `stats`
	- `accounts`

## Compile
```console
$ eosio-cpp dcitoken.cpp -o dcitoken.wasm
Warning, empty ricardian clause file
Warning, empty ricardian clause file
Warning, action <create> does not have a ricardian contract
Warning, action <issue> does not have a ricardian contract
Warning, action <retire> does not have a ricardian contract
Warning, action <transfer> does not have a ricardian contract
Warning, action <open> does not have a ricardian contract
Warning, action <close> does not have a ricardian contract
Warning, action <create> does not have a ricardian contract
Warning, action <issue> does not have a ricardian contract
Warning, action <retire> does not have a ricardian contract
Warning, action <transfer> does not have a ricardian contract
Warning, action <open> does not have a ricardian contract
Warning, action <close> does not have a ricardian contract
```

## Deploy
* deploy contract
```console
$ cleost set contract dci1111token ./
Reading WASM from /mnt/f/Coding/github_repos/dci_contracts/dcitoken/dcitoken.wasm...
Publishing contract...
executed transaction: 0a4faba455d7235ee2a0465fcaee7fa86eaa6ecec57fd86b4a87b1fb95d3ba8a  7016 bytes  697 us
#         eosio <= eosio::setcode               {"account":"dci1111token","vmtype":0,"vmversion":0,"code":"0061736d0100000001a0011b60000060017e00600...
#         eosio <= eosio::setabi                {"account":"dci1111token","abi":"0e656f73696f3a3a6162692f312e310008076163636f756e7400010762616c616e6...
warning: transaction executed locally, but may not be confirmed by the network yet         ]
```
* Adding eosio.code to permissions (for inline actions)
```console
$ cleost set account permission dci1111token active --add-code
executed transaction: 67653e4fdc6dc3ce93f47efd8e6180049c28352240e6eb08b235c4e13045bffb  184 bytes  160 us
#         eosio <= eosio::updateauth            {"account":"dci1111token","permission":"active","parent":"owner","auth":{"threshold":1,"keys":[{"key...
warning: transaction executed locally, but may not be confirmed by the network yet         ]
```

## Testing
### Action - `create`
* create the token 1 M tokens for 10 years. Total 10 M tokens
```console
$ cleost push action dci1111token create '["dcieosissuer", "10000000.0000 DCI"]' -p dci1111token@active
executed transaction: fdbc725d043008e6f38081d456df0c5532ccb461c0951511ce235da43b2fb9d9  120 bytes  271 us
#  dci1111token <= dci1111token::create         {"issuer":"dcieosissuer","maximum_supply":"10000000.0000 DCI"}
warning: transaction executed locally, but may not be confirmed by the network yet         ]
```

### Action - `issue`
* issue 1 M to issuer - `dcieosissuer`
```console
$ cleost push action dci1111token issue '["dcieosissuer", "1000000.0000 DCI", "issue 1M tokens"]' -p dcieosissuer@active
executed transaction: 84afb7eaa0a768420ed0c3864a6f6855a5240e0d969d7a640473f30a157671b0  136 bytes  279 us
#  dci1111token <= dci1111token::issue          {"to":"dcieosissuer","quantity":"1000000.0000 DCI","memo":"issue 1M tokens"}
warning: transaction executed locally, but may not be confirmed by the network yet         ]
```

### Action - `transfer`
* issuer - `dcieosissuer` transfer some 10% of total 1M tokens i.e. 1,00,000 for ICO phase A
```console
$ cleost push action dci1111token transfer '["dcieosissuer", "dci111111ico", "100000.0000 DCI", "transfer DC
I tokens for ICO phase A"]' -p dcieosissuer@active
executed transaction: e4334c81c4f2894c8de88c8e7561ebcb6e7be4705156e1e71a0d0483cb58686d  160 bytes  214 us
#  dci1111token <= dci1111token::transfer       {"from":"dcieosissuer","to":"dci111111ico","quantity":"100000.0000 DCI","memo":"transfer DCI tokens ...
#  dcieosissuer <= dci1111token::transfer       {"from":"dcieosissuer","to":"dci111111ico","quantity":"100000.0000 DCI","memo":"transfer DCI tokens ...
#  dci111111ico <= dci1111token::transfer       {"from":"dcieosissuer","to":"dci111111ico","quantity":"100000.0000 DCI","memo":"transfer DCI tokens ...
warning: transaction executed locally, but may not be confirmed by the network yet         ]
```

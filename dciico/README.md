## Compile
```console
$ eosio-cpp dciico.cpp -o dciico.wasm
Warning, empty ricardian clause file
Warning, empty ricardian clause file
Warning, action <seticorate> does not have a ricardian contract
Warning, action <disburse> does not have a ricardian contract
Warning, action <sendalert> does not have a ricardian contract
Warning, action <seticorate> does not have a ricardian contract
Warning, action <disburse> does not have a ricardian contract
Warning, action <sendalert> does not have a ricardian contract
```

## Deploy
* Deploy contract
```console
$ cleost set contract dci111111ico ./
Reading WASM from /mnt/f/Coding/github_repos/dci_contracts/dciico/dciico.wasm...
Publishing contract...
executed transaction: 72bec18c573f24d6285365e0652adb940f4ff5d4aac35ab0678498eb7c23c058  9344 bytes  868 us
#         eosio <= eosio::setcode               {"account":"dci111111ico","vmtype":0,"vmversion":0,"code":"0061736d0100000001d3012160000060017f00600...
#         eosio <= eosio::setabi                {"account":"dci111111ico","abi":"0e656f73696f3a3a6162692f312e31000508646973627572736500040b726563656...
warning: transaction executed locally, but may not be confirmed by the network yet         ]
```
* Adding eosio.code to permissions (for inline actions)
```console
$ cleost set account permission dci111111ico active --add-code
executed transaction: c7ac45aad98c352d3b7f99128d474771620654cb4ba40359a5cf25ef697346eb  184 bytes  194 us
#         eosio <= eosio::updateauth            {"account":"dci111111ico","permission":"active","parent":"owner","auth":{"threshold":1,"keys":[{"key...
warning: transaction executed locally, but may not be confirmed by the network yet         ]
```

## TODO
* [ ] Store all the fund record into different scope of same table as per phases. As of now, all the fund_transferred are added up & cumulative is shown.
#include<eosio/eosio.hpp>
#include<eosio/asset.hpp>

using namespace eosio;

CONTRACT geteos: public contract {
    public:
        using contract::contract;

        ACTION getbalance(name user, asset token){
            accounts mytoken("eosio.token"_n, user.value); //잔액은 eosio.token이 가지고 있음
            symbol sym = token.symbol;
            auto itr = mytoken.require_find(sym.code().raw(), "no balance");

            print(itr->balance);


        }
    
    private:
        TABLE account {
            asset    balance;  //숫자로된 잔액, 심볼 확인 가능 asset = token type

            //balance.acoout; 잔액확인 .symbol; 심볼확인

            uint64_t primary_key()const { return balance.symbol.code().raw(); }
         };

        TABLE currency_stats {
            asset    supply;
            asset    max_supply;
            name     issuer;

            uint64_t primary_key()const { return supply.symbol.code().raw(); }
         };

         typedef multi_index< "accounts"_n, account > accounts;
         typedef multi_index< "stat"_n, currency_stats > stats;
//eos.io.token 테이블 조회
};
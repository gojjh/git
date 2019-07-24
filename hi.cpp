#include <eosio/eosio.hpp>

using namespace eosio;

CONTRACT hi: public contract {
    public:
        using contract::contract;

        ACTION hi (name user) {
            require_auth(user);
            allowance forAllowance
            check( has_auth(user), "no account");
            print("hi, ", user);
        }

        ACTION insert(name user){
            
            require_auth(get_self());
            
            address_index forInser(get_self(), get_self().value);
            auto itr = forInsert.find(user.value);                
            
            check( itr == forInsert.end(), "already exists");

            forInsert.emplace( get_self(), [&](auto& row){
                row.user = user;
            });
            print("Insert sucess");
            }
        
        ACTION remove(name user){
            check( has_auth( get_self()), "you are not Contracer");


            address_index forRemove(get_self(), get_self().value);
            auto itr = forInsert.fint(user.value);
            forRemove.remove(itr);

            print("remove success");
        }
    private:
        TABLE allowance{
            name user;

            uint64_t primary_ket() const { return user.value;}

        };
    typedef multi_index<"allowance"_n, allowance> address_index;
};
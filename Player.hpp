#pragma once
#include "Game.hpp"
#include <string>
#include <stdexcept>
#include <cstring>  

namespace coup{
    
    class Player{
    
        public:
        int kill_num = 7;
        std::string my_name;
        coup::Game *my_game;
        int coin_number;
        std::string last_act;
        
        Player(coup::Game &temp_game, std::string &temp_name);

        void income();
        
        void foreign_aid();
        
        virtual void coup(Player &coup_player);
        
        virtual void cancel_act();

        int coins() const;
        
        bool die() const;

        virtual std::string role()=0;


    };
    
}
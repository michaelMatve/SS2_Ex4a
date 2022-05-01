#include "Player.hpp"

namespace coup{

    class Assassin : public coup::Player{
        public:
        int ass_num_kill = 3;
        int player_coup_place;
        std::string player_coup;

        Assassin(coup::Game &temp_game, std::string temp_name);
        void coup(Player &coup_player);
        std::string role();
        void cancel_act();
        
    };
    
}
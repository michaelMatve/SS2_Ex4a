#include "Player.hpp"

namespace coup{

    class Ambassador : public coup::Player{

        public:
        Ambassador(coup::Game &temp_game, std::string temp_name);
        std::string role();
        void transfer(Player &from_p, Player &to_p);
        void block(Player &block_player);
    };
    
}
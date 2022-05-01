#include "Player.hpp"

namespace coup{

    class Duke : public coup::Player{
        public:
        Duke(coup::Game &temp_game, std::string temp_name);
        std::string role();
        void tax();
        void block(Player &block_player);

    };
    
}
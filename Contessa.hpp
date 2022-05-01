#include "Player.hpp"

namespace coup{

    class Contessa : public coup::Player{
        public:
        
        Contessa(coup::Game &temp_game, std::string temp_name);
        std::string role();
        void block(Player &block_player);
        
    };
    
}
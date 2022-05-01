#include "Contessa.hpp"

coup::Contessa::Contessa(coup::Game &temp_game, std::string temp_name) : coup::Player(temp_game , temp_name){};

std::string coup::Contessa::role()
{
    return "Contessa";
}
void coup::Contessa::block(Player &block_player)
{
    if(!this->my_game->check_live(block_player.my_name))
    {
        throw std::invalid_argument("cant blook2");
    }
    if(block_player.last_act!= "scoup")
    {
        throw std::invalid_argument("cant blook");
    }
    block_player.cancel_act();
}
#include "Ambassador.hpp"

coup::Ambassador::Ambassador(coup::Game &temp_game, std::string temp_name) : coup::Player(temp_game , temp_name){};

std::string coup::Ambassador::role()
{
    return "Ambassador";
}

void coup::Ambassador::transfer(Player &from_p, Player &to_p)
{
    if(this->my_game->turn() != this->my_name)
    {
        throw std::invalid_argument("not your turn");
    }
    if(from_p.die()||to_p.die())
    {
        throw std::invalid_argument("players are not exist");
    }
    if(from_p.coins()==0)
    {
        throw std::invalid_argument("has no coin to take");
    }
    from_p.coin_number-=1;
    to_p.coin_number+=1;
    this->my_game->change_turn();
}

void coup::Ambassador::block(Player &block_player)
{
    if(!this->my_game->check_live(block_player.my_name))
    {
        throw std::invalid_argument("cant blook");
    }
    if(block_player.last_act!= "steal")
    {
        throw std::invalid_argument("cant blook");
    }
    block_player.cancel_act();
}

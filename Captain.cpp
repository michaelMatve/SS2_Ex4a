#include "Captain.hpp"

coup::Captain::Captain(coup::Game &temp_game, std::string temp_name): coup::Player(temp_game , temp_name){this->from_player_steal = NULL;};

std::string coup::Captain::role()
{
    return "Captain";
}
        
void coup::Captain::steal(Player &from_p)
{
    if(this->my_game->turn() != this->my_name)
    {
        throw std::invalid_argument("not your turn");
    }
    if(from_p.die())
    {
        throw std::invalid_argument("players are not exist");
    }
    if(from_p.coins()<2)
    {
        throw std::invalid_argument("doesnt have coins to steal");
    }
    from_p.coin_number-=2;
    this->coin_number+=2;
    this->from_player_steal = &from_p;
    this->my_game->change_turn();
}

void coup::Captain::cancel_act()
{
    this->from_player_steal->coin_number +=2;
    this->coin_number-=2;
}       
void coup::Captain::block(Player &block_player)
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

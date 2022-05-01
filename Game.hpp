#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace coup {

    class Game {
        private:
        std::vector<std::string> my_players;
        int curr_player;
        
        public:
        Game();
        std::string turn();
        std::vector<std::string> players();
        std::string winner();
        void add(std::string const &player_name);
        void add(std::string const &player_name,int place);
        int remove( std::string const &player_name);
        void change_turn();
        bool check_live(std::string const &player_name);

    };
    
}
#include "doctest.h"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include <string>

TEST_CASE("good inputs"){
            
    //check duke
    coup::Game my_game{};
    coup::Duke my_duke{my_game, "michael"};
    CHECK(my_game.turn()=="michael");
    CHECK(my_game.players().size()==1);
    CHECK(my_duke.coins() == 0);
    my_duke.income();
    CHECK(my_duke.coins() == 1);
    my_duke.foreign_aid();
    CHECK(my_duke.coins() == 3);

    //spacial duke
    my_duke.tax();
    CHECK(my_duke.coins() == 6);

    //coup
    my_duke.foreign_aid();
    my_duke.coup(my_duke);
    CHECK(my_game.players().size()==0);


    coup::Duke my_Ambassador{my_game, "yossi"};

    //check Ambasador
    CHECK(my_game.turn()=="yossi");
    CHECK(my_game.players().size()==1);
    CHECK(my_Ambassador.coins() == 0);
    my_Ambassador.income();
    CHECK(my_Ambassador.coins() == 1);
    my_Ambassador.foreign_aid();
    CHECK(my_Ambassador.coins() == 3);
    my_Ambassador.foreign_aid();
    my_Ambassador.foreign_aid();
    my_Ambassador.foreign_aid();
    my_Ambassador.coup(my_Ambassador);
    CHECK(my_game.players().size()==0);

    coup::Assassin my_assassin{my_game, "haim"};
    //check assassin
    CHECK(my_game.turn()=="haim");
    CHECK(my_game.players().size()==1);
    CHECK(my_assassin.coins() == 0);
    my_assassin.income();
    CHECK(my_assassin.coins() == 1);
    my_assassin.foreign_aid();
    CHECK(my_assassin.coins() == 3);
    my_assassin.foreign_aid();
    my_assassin.foreign_aid();
    my_assassin.foreign_aid();
    my_assassin.coup(my_assassin);
    CHECK(my_game.players().size()==0);

    coup::Captain my_captain{my_game, "yoni"};
    //check Ambasador
    CHECK(my_game.turn()=="yoni");
    CHECK(my_game.players().size()==1);
    CHECK(my_captain.coins() == 0);
    my_captain.income();
    CHECK(my_captain.coins() == 1);
    my_captain.foreign_aid();
    CHECK(my_captain.coins() == 3);
    my_captain.foreign_aid();
    my_captain.foreign_aid();
    my_captain.foreign_aid();
    my_captain.coup(my_captain);
    CHECK(my_game.players().size()==0);
	
    
    coup::Contessa my_contessa{my_game, "yossi"};
    //check Ambasador
    CHECK(my_game.turn()=="yossi");
    CHECK(my_game.players().size()==1);
    CHECK(my_contessa.coins() == 0);
    my_contessa.income();
    CHECK(my_contessa.coins() == 1);
    my_contessa.foreign_aid();
    CHECK(my_contessa.coins() == 3);
    my_contessa.foreign_aid();
    my_contessa.foreign_aid();
    my_contessa.foreign_aid();
    my_contessa.coup(my_contessa);
    CHECK(my_game.players().size()==0);

    //spacial func
        coup::Duke my_duke1{my_game, "michael1"};
        coup::Ambassador my_ambassador1{my_game, "tom1"};
        coup::Assassin my_assassin1{my_game, "haim1"};
        coup::Captain my_captain1{my_game, "yoni1"};
        coup::Contessa my_contessa1{my_game, "yossi1"};

    CHECK(my_game.players().size()==5);
    my_duke1.tax();
    CHECK(my_duke1.coins() == 3);
    my_ambassador1.transfer(my_duke1,my_assassin1);
    CHECK(my_duke1.coins() == 2);
    CHECK(my_assassin1.coins() == 1);
    my_assassin1.foreign_aid();
    my_captain1.steal(my_duke1);
    CHECK(my_duke1.coins() == 0);
    CHECK(my_captain1.coins() == 2);
    my_contessa1.income();
    my_duke1.income();
    my_ambassador1.income();
    CHECK(my_game.players().size()==5);
    my_assassin1.coup(my_duke1);
    CHECK(my_game.players().size()==4);
    my_captain1.income();
    // my_contessa1.block(my_assassin1);
    // CHECK(my_game.players().size()==5);

    
}

TEST_CASE("bad inputs"){
     coup::Game my_game{};
        //check start game
        CHECK_THROWS(my_game.winner());
        CHECK_THROWS(my_game.turn());
        coup::Duke my_duke{my_game, "michael"};
	coup::Assassin my_assassin{my_game, "haim"};
	coup::Ambassador my_ambassador{my_game, "tom"};
	coup::Captain my_captain{my_game, "yoni"};
	coup::Contessa my_contessa{my_game, "yossi"};
        
        //chec kfunctions throws
        CHECK_THROWS(my_game.winner());
        CHECK_THROWS(my_captain.foreign_aid());
        CHECK_THROWS(my_contessa.income());
        CHECK_THROWS(my_assassin.coup(my_contessa));
        CHECK_THROWS(my_duke.coup(my_ambassador));

        my_duke.coin_number+=7;
        my_duke.coup(my_ambassador);
        my_captain.coin_number+=7;
        
        CHECK_THROWS(my_captain.coup(my_ambassador));
        my_assassin.income();
        my_assassin.coin_number+=3;

        CHECK_THROWS(my_contessa.block(my_assassin));
        coup::Ambassador my_ambassador1{my_game, "john"};
        
        
        //check spacial 
        CHECK_THROWS(my_ambassador1.transfer(my_captain,my_duke));
        
        
        
}
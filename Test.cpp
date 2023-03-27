#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace std;
using namespace ariel;


TEST_CASE("Test 1 - Initialization") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    game.playTurn();
    CHECK((p1.cardesTaken()==0 ||p1.cardesTaken()==1 || p1.cardesTaken()==20)); // lost,won or draw
    CHECK_NOTHROW(game.playAll());

    CHECK((p1.stacksize() == 0 || p2.stacksize() == 0 )); // one of them should be 0 so the game will stop
}

TEST_CASE("check Player constructor"){
    Player p1("Alice");
    CHECK_THROWS(Player("Alice")); // can't create another player with the same name
}

TEST_CASE("check Game constructor"){

    Player p1("Alice");
    Player p2("Bob");

    CHECK_NOTHROW(Game(p1,p2)); // create a new game - shouldn't be any errors

    CHECK_THROWS(Game(p1,p2)); // can't create another game with same players

    CHECK_THROWS(Game(p1,p1));

    //game.playAll();

}

TEST_CASE("check playAll,printWiner functions "){ // exceptions?
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    CHECK_THROWS(game.playTurn());
    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printWiner());
    // if(p1.cardesTaken()==p2.cardesTaken())
    // {
    //     return (void)"Doesn't Print";
    // }


}


TEST_CASE("check printTurn function "){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    game.playAll();
    // if(p1.stacksize()!=0 && p2.stacksize()!=0){
    //     throw "the game isn't over!";
    // }
   // bool p1_stack=p1.stacksize() ==0;
   // bool p2_stack=p2.stacksize()==0;
    //CHECK( (p1_stack) && (p2_stack) ); // when the game is over , both players don't have any cards left.
    CHECK((p1.stacksize() ==0 &&p2.stacksize()==0));
    CHECK_THROWS(game.playTurn());// the game is over, can't do another turn
    

}


//     Player p1("Alice");
//     Player p2("Bob");
//     for (int i=0;i<20;i++) {
//      CHECK(p1.stacksize() == 26);
//    }
    
TEST_CASE("play a game "){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_THROWS(game.printStats());// there are no stats until the first turn!
    CHECK_THROWS(game.printLog());//there is nothing to print here until the first turn!
    CHECK_THROWS(game.printWiner()); // there is no winner at that point!
    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(game.printStats()); // after first turn there are stats
    CHECK_NOTHROW(game.printLog()); //  after first turn there is log
    CHECK_THROWS(game.printWiner());  // there is no winner at that point!
    for(int i=0;i<5;i++){
        CHECK_NOTHROW( game.playTurn());
    }
    CHECK_THROWS(game.printWiner());
    game.playAll();
    CHECK_NOTHROW(game.printWiner());



    // here i can do more   CHECK_NOTHROW
}
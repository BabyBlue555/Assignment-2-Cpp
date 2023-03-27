#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace std;
using namespace ariel;


TEST_CASE("Test 1 - check stacksize and cardesTaken ") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    game.playTurn();
    // after playing one turn:
    CHECK((p1.cardesTaken()==0 ||p1.cardesTaken()==2 || p1.cardesTaken()==6)); // lost,won or draw and won
    CHECK((p2.cardesTaken()==0 ||p2.cardesTaken()==2 || p1.cardesTaken()==6)); // lost,won or draw and won
    CHECK((p1.stacksize()== 25 || p1.stacksize()== 23)); // regular turn or a draw turn
    CHECK((p2.stacksize()== 25 || p2.stacksize()== 23)); // regular turn or a draw turn
    
    CHECK_NOTHROW(game.playAll());
    // when the game is over , both players don't have any cards left.
    CHECK((p1.stacksize() ==0 &&p2.stacksize()==0));
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

TEST_CASE("check print functions when game didn't start "){ 
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    //CHECK_THROWS(game.playTurn());
    // no turn was played - the game didn't start - throw exceptions
    CHECK_THROWS(game.printLastTurn());
    CHECK_THROWS(game.printStats());
    CHECK_THROWS(game.printLog());
    CHECK_THROWS(game.printWiner());

}


TEST_CASE("check printTurn function when game is over "){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    game.playAll();
  

    CHECK_THROWS(game.playTurn());// the game is over, can't do another turn
    

}


TEST_CASE("check print functions after game starts"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    // CHECK_THROWS(game.printStats());// there are no stats until the first turn!
    // CHECK_THROWS(game.printLog());//there is nothing to print here until the first turn!
    // CHECK_THROWS(game.printWiner()); // there is no winner at that point!
    CHECK_NOTHROW(game.playTurn()); 
    CHECK_NOTHROW(game.printLastTurn()); 
    CHECK_NOTHROW(game.printStats()); // after first turn there are stats
    CHECK_NOTHROW(game.printLog()); //  after first turn there is log
    CHECK_THROWS(game.printWiner());  // there is no winner at that point!
    for(int i=0;i<5;i++){
        CHECK_NOTHROW( game.playTurn());
    }
    CHECK_THROWS(game.printWiner()); // the game isn't over yet
    game.playAll();
    CHECK_NOTHROW(game.printWiner());



    // here i can do more   CHECK_NOTHROW
}
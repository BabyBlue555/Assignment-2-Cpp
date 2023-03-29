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
    CHECK_NOTHROW(game.playTurn());
    //game.playTurn();
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
    CHECK_NOTHROW(Player p1("Alice")); // okay
   // Player p1("Alice");
    CHECK_THROWS(Player("")); // shouln't create a player without a name
    CHECK_THROWS(Player("Alice")); // can't create another player with the same name
}

TEST_CASE("check Game constructor"){

    Player p1("Alice");
    Player p2("Bob");
    Player p3("Shimi");

    CHECK_NOTHROW(Game game(p1,p2)); // create a new game - shouldn't be any errors
    //Game game(p1,p2);
    CHECK_THROWS(Game(p1,p2)); // can't create another game with same players that currently play another game

    CHECK_THROWS(Game(p1,p3)); // can't create another game when one of the players currently plays in another game 

    CHECK_THROWS(Game (p1,p1)); // can't create game with same player


    //game.playAll();

}

TEST_CASE("check print functions when game didn't start "){ 
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    // no turn was played - the game didn't start - throw exceptions
    CHECK_THROWS(game.printLastTurn()); 
    CHECK_THROWS(game.printStats()); // there are no stats until the first turn!
    CHECK_THROWS(game.printLog()); //there is nothing to print here until the first turn!
    CHECK_THROWS(game.printWiner());// there is no winner at that point!

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
    CHECK_NOTHROW(game.playTurn()); 
    // game.playTurn();
    CHECK_NOTHROW(game.printLastTurn()); 
    CHECK_NOTHROW(game.printStats()); // after first turn there are stats
    CHECK_NOTHROW(game.printLog()); //  after first turn there is log
    CHECK_THROWS(game.printWiner());  // there is no winner at that point!
    for(int i=0;i<5;i++){
        CHECK_NOTHROW( game.playTurn());
    }
    CHECK(p1.stacksize()<=21);
    CHECK(p2.stacksize()<=21);
    CHECK_THROWS(game.printWiner()); // the game isn't over yet
    // game.playAll();
    // CHECK_NOTHROW(game.printWiner()); // one of the players won

}


// end game has two cases - one of them wins / tie 
// all the case tests before threw exception when calling printwiner(), this is the only case 
// when it doesn't throw because the game is over - either in a win or a tie 
TEST_CASE("one of the players wins"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playAll();
    CHECK_NOTHROW(game.printWiner()); // one of the players won, or it is a tie
    // if there is a tie, it should print and not throw.
}
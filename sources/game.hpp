
#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include <iostream>
using namespace std;

//#include "namespace.hpp"
namespace ariel{

};



class Game{
    Player& p1;
    Player& p2;
    public: // in order to access it in Demo.cpp
    
    //inline 
    Game(Player& plr1,Player& plr2);
    
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
    void playTurn();


};
#endif
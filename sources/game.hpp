
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
   // Game(){}; // inline
   // by reference 
    Game(Player& plr1,Player& plr2)
     :  p1(plr1), p2(plr2) {
        this->p1 = plr1;
        this->p2 = plr2;;
     }//outline 
    
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
    void playTurn();


};
#endif
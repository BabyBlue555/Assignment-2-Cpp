
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "game.hpp"
#include "player.hpp"
using namespace std;
using namespace ariel;




// "outline" constructor implementation:
//  A(std::string& str_)
   //  :    str(str_) {}
   

// "outline" method implementation:
void Game::printLastTurn(){
    cout<<"printLastTurn"<<endl;
};

void Game::playTurn(){
    cout<<"playTurn"<<endl;
};


void Game::playAll(){
    cout<<"playAll"<<endl;
};

void Game::printWiner(){
    cout<<"printWiner"<<endl;
    // if(p1.cardesTaken()>p2.cardesTaken()){
    //     return (void)"player 1 is the winner";
    // }
    // else{

    // }

};

void Game::printLog(){
    cout<<"printLog"<<endl;
};

void Game::printStats(){
    cout<<"printStats"<<endl;
};



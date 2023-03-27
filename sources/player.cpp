#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "player.hpp"
using namespace std;
using namespace ariel;

// "outline" constructor implementation:

Player:: Player(string str){
    this->name=str;
    this->stackSize=26;
    this->cardsTaken=0;
}


string Player::getName(){
    return this->name;
}

// "outline" method implementation:
int Player::stacksize(){
    return 1;
};
int Player::cardesTaken(){
    return 1;
};
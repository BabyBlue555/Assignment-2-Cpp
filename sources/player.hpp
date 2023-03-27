#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
using namespace std;



namespace ariel{

};

class Player{
    // it is recommended that the fields of a class would be private
    private:
    string name;
    int stackSize; // according to function stacksize()
    int cardsTaken;// according to function cardesTaken()
      // since each player can only play one game at a time , there should be an indicator to tell us 
     // if the he/she is playing right now , in order to throw exceptions in response
    bool isPlaying;
   


    // according to Demo.cpp, these are the functions that should be public:
    public:
    Player(string); // OUTLINE
    std::string getName(); // "outline" method
    int stacksize(); // "outline" method
    int cardesTaken(); // "outline" method

};

#endif
#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include<iostream>
using namespace std;
class Player{
private:
    string playername;
    int score;
public:
    void setPlayerName(string n);
    string getPlayerName();
    void setScore(int s);
    int getScore();
    Player();
    Player(string name);
    ~Player();
    void displayScore();
    void increaseScore(int n);
    void decreaseScore(int n);
};


#endif // PLAYER_H_INCLUDED

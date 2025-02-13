#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include<iostream>
using namespace std;
class Game{
        Deck* d;
        Player* player1;
        Player* player2;
        bool isPlayer1;
        int count;
public:
    Game(Deck* d,string player1Name,string player2Name);
    Game();
    ~Game();
    void initializeGame();
    Deck* getDeck();
    Player* getPlayer1();
    Player* getPlayer2();
    void setPlayer1(Player* p);
    void setPlayer2(Player* p);
    void setDeck(Deck* d);

    void displayPlayers();
    void cardFlipping();
    bool isGameOver();

    int getCount();
    void addToCount(int x);
    void winnerMSG();

    /*
    void notSame();
    void StandardSame();
    void BonusStandard();
    void doubleBounus();
    void penaltyStandard();
    void doublePenalty();
    void bonusPenalty();

*/

};

#endif // GAME_H_INCLUDED

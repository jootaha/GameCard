#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED
#include<iostream>
using namespace std;
class Deck{
private:
    Card* cards[4][4];
public:

    Deck();
    Deck(Card* c[4][4]);
    ~Deck();
    Card** getCards();

    void setCards(Card* c[4][4]);
    void displayGrid();
    void shuffle();
    void removeCard(int x,int y);
    void reset();
    void test();
    Card* getOneCard(int x,int y );
};

#endif // DECK_H_INCLUDED

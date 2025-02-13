#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
#include<iostream>
using namespace std;
class Card{
private:
    int cardNum;
    bool faceup;

public:
     Card(int cardNum);
     Card();
   virtual ~Card();
   virtual void setCardNum(int s);
   virtual int getCardNum();
   virtual void display();
    bool getFace();
    void setFace(bool f);
    void reveal();
    void hide();
    void removeCard();
     bool isRemoved();


};


#endif // CARD_H_INCLUDED

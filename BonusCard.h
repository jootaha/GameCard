#ifndef BONUSCARD_H_INCLUDED
#define BONUSCARD_H_INCLUDED
#include<iostream>
using namespace std;
class BonusCard:public Card{
private:
    int addedBonus;
public:
    BonusCard(int cardNum,int addedBonus);
    BonusCard();
    ~BonusCard();
    void setBonus(int n);
   int getBonus();

};
#endif // BONUSCARD_H_INCLUDED

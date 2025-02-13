#ifndef PENALTYCARD_H_INCLUDED
#define PENALTYCARD_H_INCLUDED
#include<iostream>
using namespace std;
class PenaltyCard:public Card{
private:
    int deductedBonus;
public:
    PenaltyCard(int cardNum,int deductedBonus);
    PenaltyCard();
    ~PenaltyCard();
    void setDeductedBonus(int b);
    int getDeduction();

};

#endif // PENALTYCARD_H_INCLUDED

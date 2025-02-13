#include"Card.h"
#include"BonusCard.h"
#include"PenaltyCard.h"
#include"StandardCard.h"
#include"Deck.h"
#include"Player.h"
#include"Game.h"
#include<iostream>
#include<cstdlib>
#include <cstdlib>
#include<ctime>
using namespace std;

Card::Card(int cardNum){
this->cardNum=cardNum;
this->faceup=false;
}
Card::Card(){
this->cardNum=0;
this->faceup=false;

}
Card::~Card(){
}
bool Card:: getFace(){
    return faceup;
}
bool Card::isRemoved(){
return cardNum==0;
}
void Card::setFace(bool f ){
    faceup=f;
}
int Card:: getCardNum(){
return this->cardNum;
}
void Card::setCardNum(int cardNum){
this->cardNum=cardNum;
}

 void Card::display(){
     if(cardNum==0){
        cout<<"  ";
        return;
     }
if(faceup)
    cout<<this->cardNum<<" ";
else cout<<"* ";
}
void Card::reveal(){
setFace(true);
display();
}
void Card::hide(){
setFace(false);
display();
}
void Card::removeCard(){
cardNum=0;
}




BonusCard::BonusCard(int cardNum,int addedBonus) : Card(cardNum) {
    this->addedBonus = addedBonus;
}


BonusCard::BonusCard() : Card() {
    this->addedBonus = 1;
}

BonusCard::~BonusCard(){
}
void BonusCard::setBonus(int n){
addedBonus=n;
}
int BonusCard::getBonus(){
return addedBonus;
}


PenaltyCard::PenaltyCard(int cardNum,int deductedBonus) : Card(cardNum) {
    this->deductedBonus = deductedBonus;
}

PenaltyCard::PenaltyCard() : Card() {
    this->deductedBonus = 1;
}


PenaltyCard::~PenaltyCard(){
}
void PenaltyCard::setDeductedBonus(int n){
deductedBonus=n;
}
int PenaltyCard::getDeduction(){
return deductedBonus;
}



StandardCard::StandardCard(int cardNum) : Card(cardNum) {

}

StandardCard::StandardCard() : Card() {

}

StandardCard::~StandardCard(){
}





Deck::Deck(Card* c[4][4]){
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++)
        cards[i][j]=c[i][j];
}
}

void Deck::reset(){
 for(int i=0;i<4;i++){
    for(int j=0;j<4;j++)
        cards[i][j]->setFace(false);
}
}


void Deck::test(){
 for(int i=0;i<4;i++){
    for(int j=0;j<4;j++)
        cards[i][j]->setFace(true);
}
}


Deck::Deck(){
    cards[3][1]=new BonusCard(7,1);
    cards[0][0]=new StandardCard(1);
    cards[0][1]=new StandardCard(1);
    cards[0][2]=new StandardCard(2);
    cards[0][3]=new StandardCard(2);
    cards[1][0]=new StandardCard(3);
    cards[1][1]=new StandardCard(3);
    cards[1][2]=new StandardCard(4);
    cards[1][3]=new StandardCard(4);
    cards[3][2]=new PenaltyCard(8,2);
    cards[2][0]=new StandardCard(5);
    cards[2][1]=new StandardCard(5);
    cards[2][2]=new StandardCard(6);
    cards[2][3]=new StandardCard(6);
    cards[3][0]=new BonusCard(7,1);
    cards[3][3]=new PenaltyCard(8,2);

}
Deck::~Deck(){
for(int i=0;i<4;++i) {
            delete[] cards[i]; // Free memory for each row
        }
        delete[] cards;
}
void Deck::setCards(Card* c[4][4]){
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++)
        cards[i][j]=c[i][j];
}
}
Card** Deck:: getCards(){
return &cards[0][0];

}

void Deck::shuffle(){
Card* temp[16];
int i=0;
    for(int j=0;j<4;j++){
        for(int k=0;k<4;k++){
            temp[i]=cards[j][k];
            i++;
        }
    }
    srand(time(0));
    for(int a=0;a<16;a++){

        int random=rand()%16;
        Card* t=temp[a];
        temp[a]=temp[random];
        temp[random]=t;
    }
    int z=0;
    for(int b=0;b<4;b++){
        for(int c=0;c<4;c++){
            cards[b][c]=temp[z];
            z++;
        }
    }
}
void Deck::displayGrid(){
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++)
        cards[i][j]->display();
        cout<<endl;
}
}
void Deck::removeCard(int x,int y){
 cards[x][y]->setCardNum(0);
}

Card* Deck::getOneCard(int x,int y){
return cards[x][y];
}


Player::Player(string name){
playername=name;
score=0;
}
Player::Player(){
    score=0;
}
Player::~Player(){
}
string Player::getPlayerName(){
return playername;
}
void Player::setPlayerName(string n){
    playername=n;
}
void Player::setScore(int n){
score=n;
}
int Player::getScore(){
return score;
}
void Player::displayScore(){
cout<<score<<endl;
}

void Player::increaseScore(int n){
score+=n;
}
void Player::decreaseScore(int n ){
score-=n;
}



Game::Game(Deck* d,string player1Name,string player2Name){
this->d=d;
this->player1=new Player(player1Name);
this->player2=new Player(player2Name);
isPlayer1=true;
}
Game::Game(){

    this->d =new Deck();
    this->player1=new Player();
    this->player2=new Player();
    this->isPlayer1=true;
    this->count=0;
}

Game::~Game(){
    delete d;
    delete player1;
    delete player2;
}
void Game::initializeGame(){
d->shuffle();
d->displayGrid();
string name1;
string name2;

   cout<<"Enter first player name: "<<endl;
    cin>>name1;
   cout<<"Enter second player name: "<<endl;
   cin>>name2;
   player1->setPlayerName(name1);
   player2->setPlayerName(name2);
   system("cls");

}
int Game::getCount(){
return count;
}

void Game::addToCount(int x ){
count+=x;
}

 Deck* Game::getDeck(){
     return d ;
 }
    void Game::setDeck(Deck* d){
        this->d=d;
    }
    Player* Game::getPlayer1(){
    return player1;
    }
    Player* Game::getPlayer2(){
    return player2;
    }
    void Game::setPlayer1(Player* p){
    this->player1=p;
    }
    void Game::setPlayer2(Player* p){
    this->player2=p;
    }
    void Game::displayPlayers(){
    cout<<this->player1->getPlayerName()<<"'s"<<" score:"<<this->player1->getScore()<<endl;
    cout<<this->player2->getPlayerName()<<"'s"<<" score:"<<this->player2->getScore()<<endl;
    }

    bool Game::isGameOver(){
    if(count==16||count==15)
        return true;
    return false;
    }

    void Game::cardFlipping(){

       if(isPlayer1) cout<<player1->getPlayerName()<< "'s turn "<<endl;
       else cout<<player2->getPlayerName()<< "'s turn "<<endl;
        int x1;
        int x2;
        int y1;
        int y2;

        do{
        do{
        cout<<"enter the row of the first card you choose "<<endl;
        cin>>x1;
        if(x1>=4||x1<0){
            cout<<"invalid input ,try again"<<endl;
        }
        }while(x1>=4||x1<0);

         do{
        cout<<"enter the column of the first card you choose "<<endl;
        cin>>y1;
        if(y1>=4||y1<0){
            cout<<"invalid input ,try again"<<endl;
        }

        }while(y1>=4||y1<0);
        if(d->getOneCard(x1,y1)->isRemoved()) cout<<"card is removed"<<endl;
        }while(d->getOneCard(x1,y1)->isRemoved());

        //second card
        do{
         do{
        cout<<"enter the row of the second card you choose "<<endl;
        cin>>x2;
        if(x2>=4||x2<0){
            cout<<"invalid input ,try again"<<endl;
        }
        }while(x2>=4||x2<0);

         do{
        cout<<"enter the column of the second card you choose "<<endl;
        cin>>y2;
        if(y2>=4||y2<0){
            cout<<"invalid input ,try again"<<endl;
        }
        }while(y2>=4||y2<0);

        if(d->getOneCard(x2,y2)->isRemoved()) cout<<"card is removed, try again!"<<endl;
        if(x1==x2&&y1==y2)cout<<"you can't flip the same card"<<endl;
        }while(x1==x2&&y1==y2||(d->getOneCard(x2,y2)->isRemoved()));

        d->getOneCard(x1,y1)->setFace(true);
        d->getOneCard(x2,y2)->setFace(true);
        d->displayGrid();
        int card1= d->getOneCard(x1,y1)->getCardNum();
        int card2= d->getOneCard(x2,y2)->getCardNum();

       //two standard equal
        if(card1<7&&card2<7&&card1==card2){

            d->getOneCard(x1,y1)->removeCard();
            d->getOneCard(x2,y2)->removeCard();
            addToCount(2);
            if(isPlayer1){
                cout<<player1->getPlayerName()<<" won 1 point!"<<endl;
                player1->increaseScore(1);
                         }
            else{
                cout<<player2->getPlayerName()<<" won 1 point!"<<endl;
                player2->increaseScore(1);
                }
        }
        //one standard one bonus

          if((card1<7&&card2==7)||(card2<7&&card1==7)){
            addToCount(1);
            if(card1==7)
                d->getOneCard(x1,y1)->removeCard();

            if(card2==7)
                d->getOneCard(x2,y2)->removeCard();

             if(isPlayer1){
                cout<<player1->getPlayerName()<<" won 1 point!"<<endl;
                player1->increaseScore(1);
             }
            else {
                cout<<player2->getPlayerName()<<" won 1 point!"<<endl;
                player2->increaseScore(1);
          }
          }

          //one standard one penalty
          if((card1<7&&card2==8)||(card2<7&&card1==8)){
                addToCount(1);
            if(card1==8)
                d->getOneCard(x1,y1)->removeCard();
            if(card2==8)
                d->getOneCard(x2,y2)->removeCard();

             if(isPlayer1){
                cout<<player1->getPlayerName()<<" lost 1 point!"<<endl;
                player1->decreaseScore(1);
             }
            else {
                cout<<player2->getPlayerName()<<" lost 1 point!"<<endl;
                player2->decreaseScore(1);
          }
          }

          //one bonus one penalty
           if((card1==7&&card2==8)||(card2==7&&card1==8)){
                addToCount(2);
            d->getOneCard(x1,y1)->removeCard();
            d->getOneCard(x2,y2)->removeCard();

                cout<<" nothing happen for you they both cancel each other!"<<endl;
           }


           //both bonus
           if(card1==7&&card2==7){
                addToCount(2);
                d->getOneCard(x1,y1)->removeCard();
                d->getOneCard(x2,y2)->removeCard();
                int descision;
                cout<<"Enter 1 to earn two point and other play or enter 2 to earn one point and play another turn"<<endl;
                cin>>descision;
                if(descision==1){

                     if(isPlayer1){
                cout<<player1->getPlayerName()<<" won 2 points!"<<endl;
                player1->increaseScore(2);
             }
            else {
                cout<<player2->getPlayerName()<<" won 2 points!"<<endl;
                player2->increaseScore(2);
          }

                }

                if(descision==2){

             if(isPlayer1){
                cout<<player1->getPlayerName()<<" won 1 point and will play again!"<<endl;
                player1->increaseScore(1);
             }
            else {
                cout<<player2->getPlayerName()<<" won 1 point and will play again!"<<endl;
                player2->increaseScore(1);
          }
          string con;
          cout<<"press c to resume"<<endl;
          cin>>con;

          system("cls");
          d->reset();
          displayPlayers();
           d->displayGrid();
          cardFlipping();
          isPlayer1=!isPlayer1;  //this make the player play two turns


           }
           }

           if(card1==8&&card2==8){
                addToCount(2);
                d->getOneCard(x1,y1)->removeCard();
                d->getOneCard(x2,y2)->removeCard();
                int descision;
                cout<<"Enter 1 to lose two points or enter 2 to lose 1 point and skip a turn"<<endl;
                cin>>descision;
                if(descision==1){

                     if(isPlayer1){
                cout<<player1->getPlayerName()<<" lost 2 points!"<<endl;
                player1->decreaseScore(2);
             }
            else {
                cout<<player2->getPlayerName()<<" lost 2 points!"<<endl;
                player2->decreaseScore(2);
          }

                }

                if(descision==2){

             if(isPlayer1){
                cout<<player1->getPlayerName()<<" Lost 1 point and will skip a turn!"<<endl;
                player1->decreaseScore(1);
             }
            else {
                cout<<player2->getPlayerName()<<" Lost 1 point and will skip a turn!"<<endl;
                player2->decreaseScore(1);
          }
          string con;
          cout<<"press c to resume"<<endl;
          cin>>con;
         isPlayer1=!isPlayer1; //this make the player skip his next turn
          system("cls");
          d->reset();
          displayPlayers();
           d->displayGrid();
          cardFlipping();



           }
           }



    isPlayer1=!isPlayer1;

    }
    void Game::winnerMSG(){

    if(player1->getScore()>player2->getScore()){
        cout<<player1->getPlayerName()<<" WON!!"<<endl;
        return;
    }
     if(player2->getScore()>player1->getScore()){
        cout<<player2->getPlayerName()<<" WON!!"<<endl;
        return;
    }
    cout<<"The game ended in  tie!"<<endl;

    }



int main(){

   Game* g = new Game();
   g->initializeGame();


    string con;
    while(!(g->isGameOver())){  //till all cards are removed
    system("cls");
   g->displayPlayers();
   g->getDeck()->displayGrid();
   g->cardFlipping();
   g->getDeck()->reset();
    cout<<"press c to resume"<<endl;
   cin>>con;
    }
     system("cls");  // clear the screen
     cout<<"final score"<<endl;
    g->displayPlayers();
    g->winnerMSG();

    delete g;



return 0;
}

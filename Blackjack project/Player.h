#include "Cards.h"
#include "Hand.h"
#pragma once
class Player
{
public:
	Player();
	~Player();
	void InitPlayer(Deck);
	void ShowHand();
protected:
	Hand PlayerHand;



private:
	int bet;
	int cash;

	void MakeBet();
	void Hit();
	

};


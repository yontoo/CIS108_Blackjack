#include "Cards.h"
#include "Hand.h"
#pragma once
class Player
{
public:
	Player();
	~Player();



private:
	int bet;
	int cash;

	void MakeBet();
	void Hit();
	

};


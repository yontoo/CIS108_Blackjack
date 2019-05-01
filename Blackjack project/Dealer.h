#include "Cards.h"
#include "Player.h"
#pragma once
class Dealer : public Player
{
public:
	Dealer();
	~Dealer();

	void AddCard();
	void FillHand();
	void CheckVicOrLose();
	void CheckVicOrLose(int);
	void FlipCard();
	void GetDeck(Deck *);
	void Dealerflow();

private:
	Hand DealerHand;
	int card_to_flip = 0;



};


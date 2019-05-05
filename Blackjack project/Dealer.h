#include "Cards.h"
#include "Player.h"
#include <Windows.h>
#pragma once
class Dealer : public Player
{
public:
	Dealer();
	~Dealer();

	void AddCard();
	void FillHand();
	void FlipCard();
	void GetDeck(Deck *);
	void Dealerflow(Player *);
	void SetC2F(int n) { card_to_flip = n; }		//C2F == card_to_flip
private:
	int card_to_flip = 0;




};


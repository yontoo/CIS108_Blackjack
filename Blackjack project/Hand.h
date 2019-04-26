#include "Cards.h"
#include "Deck.h"
#include <vector>

#pragma once
class Hand
{
public:
	std::vector<std::shared_ptr<Card>> curr_hand;
	Hand();
	~Hand();
	void GetCard(Deck);
	void GetCard(int, Deck);
};


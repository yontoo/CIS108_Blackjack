#include "Cards.h"
#include "Deck.h"
#include <vector>
#include <assert.h>
#include <functional>

#pragma once
class Hand
{
public:
	std::vector<Card> curr_hand;
	Hand();
	virtual ~Hand() = default;
	void GetCard(Deck *);
	int NumOfCards();
};


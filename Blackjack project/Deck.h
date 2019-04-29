#include <vector>
#include <algorithm>
#include "Cards.h"
#pragma once
class Deck
{
public:
	std::vector<std::shared_ptr<Card>> deck;
	void FillDeck();
	void ShuffleDeck();
	Card GiveCard();
	Deck();
	virtual ~Deck() = default;
};


#include <vector>
#include "Cards.h"
#pragma once
class Deck
{
public:
	std::vector<std::unique_ptr<Card>> deck;
	void FillDeck();
	void ShuffleDeck();
	Deck();
	~Deck();
};


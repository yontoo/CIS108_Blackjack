#include <vector>
#include <algorithm>
#include <random>
#include <time.h>
#include "Cards.h"
#pragma once
class Deck
{
public:
	std::vector<std::shared_ptr<Card>> deck;
	void InitDeck();
	void FillDeck();
	void ShuffleDeck();
	void RefillDeck();
	Card GiveCard();
	Deck();
	virtual ~Deck() = default;
};


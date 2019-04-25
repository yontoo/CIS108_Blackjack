#include "Cards.h"
#include <vector>

#pragma once
class Hand
{
public:
	std::vector<std::unique_ptr<Card>> curr_hand;
	Hand();
	~Hand();
};


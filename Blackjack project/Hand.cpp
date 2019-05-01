#include "Hand.h"

void Hand::GetCard(Deck * DeckIn)
{
	curr_hand.push_back(std::move(DeckIn->GiveCard()));
}

Hand::Hand()
{
}



#include "Hand.h"

void Hand::GetCard(Deck * DeckIn)
{
	curr_hand.push_back(std::move(DeckIn->GiveCard()));
}

int Hand::NumOfCards()
{
	return curr_hand.size();
}
Hand::Hand()
{
}



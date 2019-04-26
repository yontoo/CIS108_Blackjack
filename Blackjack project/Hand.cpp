#include "Hand.h"

void Hand::GetCard(Deck DeckIn)
{
	std::move(DeckIn.deck.begin(), DeckIn.deck.begin() + 1, curr_hand.begin());
	DeckIn.deck.erase(DeckIn.deck.begin(), DeckIn.deck.begin() + 1);
}

Hand::Hand()
{
}


Hand::~Hand()
{
}

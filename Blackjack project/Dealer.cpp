#include "Dealer.h"

void Dealer::AddCard()
{
	PlayerHand.GetCard(deck_ptr);
	deck_ptr->deck.erase(deck_ptr->deck.begin());
}

void Dealer::FillHand()
{
	for (int x = 0; x < 2; x++)
	{
		PlayerHand.GetCard(deck_ptr);
		deck_ptr->deck.erase(deck_ptr->deck.begin());
	}
}

void Dealer::FlipCard()
{
	hand_value = 0;
	std::cout << "Dealer's hand" << std::endl;
	for(int x = 0; x < card_to_flip + 1; x++)
	{
		PlayerHand.curr_hand[x].FullCard();
		hand_value += PlayerHand.curr_hand[x].GetVal();
	}
	card_to_flip++;

	std::cout << "______________________________" << std::endl;
	std::cout << "Dealer's hand value: " << hand_value << std::endl << std::endl;
}
void Dealer::GetDeck(Deck * DeckIn)
{
	deck_ptr = DeckIn;
}

void Dealer::Dealerflow(Player PlayerIn)
{
	while (hand_value <= 17)
	{
		FlipCard();
		if (hand_value > PlayerIn.GetHandVal() && hand_value <= 21)
		{
			std::cout << "Dealer value higher than Player, Dealer wins." << std::endl;
			return;
		}
		if (hand_value == PlayerIn.GetHandVal())
		{
			std::cout << "Push." << std::endl;
			return;
		}
		AddCard();
		Sleep(1000);
	}
	if (hand_value > 21)
	{
		std::cout << "Dealer bust." << std::endl;
		return;
	}
}

Dealer::Dealer()
{
}


Dealer::~Dealer()
{
}

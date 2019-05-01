#include "Dealer.h"

void Dealer::AddCard()
{
	DealerHand.GetCard(deck_ptr);
	deck_ptr->deck.erase(deck_ptr->deck.begin());
}

void Dealer::FillHand()
{
	for (int x = 0; x < 2; x++)
	{
		DealerHand.GetCard(deck_ptr);
		deck_ptr->deck.erase(deck_ptr->deck.begin());
	}
}

void Dealer::CheckVicOrLose()
{
	if (hand_value > 21)
	{
		std::cout << "Dealer bust, the Player wins." << std::endl;
		win = true;
	}
	else if (hand_value == 21)
	{
		std::cout << "Dealer blackjack, the Player loses." << std::endl;
		lose = true;
	}

	hand_value = 0;
}
void Dealer::CheckVicOrLose(int player_hand_val)
{
	if (hand_value < player_hand_val)
	{
	std::cout << "Dealer value lower than Player, Player wins." << std::endl;
	win = true;
	}
	else if (hand_value == player_hand_val)
	{
		std::cout << "PUSH: Dealer and Player values equal." << std::endl;
		push = true;
	}
	else if (player_hand_val == 21)
	{
		std::cout << "Player blackjack." << std::endl;
		win = true;
	}
	else if (hand_value < player_hand_val)
	{
		std::cout << "Dealer value higher than Player, Dealer wins." << std::endl;
		lose = true;
	}
	else
	{
		hand_value = 0;
	}
}
void Dealer::FlipCard()
{
	std::cout << "Dealer's hand" << std::endl;
	for(int x = 0; x < card_to_flip + 1; x++)
	{
		DealerHand.curr_hand[x].FullCard();
		hand_value += DealerHand.curr_hand[x].GetVal();
	}
	card_to_flip++;

	std::cout << "______________________________" << std::endl;
	std::cout << "Dealer's hand value: " << hand_value << std::endl << std::endl;
		//DealerHand.curr_hand[card_to_flip].FullCard();
		//hand_value += DealerHand.curr_hand[card_to_flip].GetVal();
		//card_to_flip++;
}
void Dealer::GetDeck(Deck * DeckIn)
{
	deck_ptr = DeckIn;
}

void Dealer::Dealerflow()
{
	if (hand_value < 17)
	{
		do
		{
			AddCard();
			FlipCard();
		} while (hand_value < 17);
	}

	else
	{
		CheckVicOrLose();
	}
}

Dealer::Dealer()
{
}


Dealer::~Dealer()
{
}

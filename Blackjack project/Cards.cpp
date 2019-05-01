#include "Cards.h"
#include <iostream>


int Card::GiveValue()
{
	if (card_rank == 'A')
	{
		return ACE;
	}
	else if (card_rank == 'K' || card_rank == 'Q' || card_rank == 'J' || card_rank == '0')
	{
		return TEN;
	}
	else
	{
		return card_rank - '0'; //Easy way to convert a character to a int since ASCII values of 0-9 start at 48 and end at 57.
	}

}


/*
Outputs a cards rank and suit to the player.
*/
void Card::FullCard()
{
	Suit SuitSwitch;
	SuitSwitch = static_cast<Suit>(card_suit);		//Can't implicitly cast to enum from int.
	switch (SuitSwitch)
	{
	case SPADES:
	{
		full_card = "spades";
		break;
	}
	case HEARTS:
	{
		full_card = "hearts";
		break;
	}
	case DIAMONDS:
	{
		full_card = "diamonds";
		break;
	}
	case CLUBS:
	{
		full_card = "clubs";
	}
	}
	
	if (card_rank == 'A')
	{
		std::cout << "Ace";
	}
	else if (card_rank == '0')
	{
		std::cout << "10";
	}
	else if (card_rank == 'K')
	{
		std::cout << "King";
	}
	else if (card_rank == 'Q')
	{
		std::cout << "Queen";
	}
	else if (card_rank == 'J')
	{
		std::cout << "Jack";
	}
	else
	{
		std::cout << card_rank;
	}

	std::cout << " of " << full_card << std::endl;
}

int Card::GetVal()
{
	return card_val;
}

Card::Card(int suit, char card_rank_in)
{
	card_rank = card_rank_in;
	card_val = GiveValue();
	card_suit = suit;
}

Card::Card(const Card & old_card)
{
	card_rank = old_card.card_rank;
	card_val = old_card.card_val;
	card_suit = old_card.card_suit;
	
}


Card::~Card()
{
}

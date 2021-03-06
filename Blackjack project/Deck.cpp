#include "Deck.h"



Deck::Deck()
{
}

void Deck::FillDeck()
{
	for (int x = 1; x <= 13; x++)
	{
		char rank;
		switch (x)
		{
		case 1: 
		{
			rank = 'A';
			break;
		}
		case 2:
		{
			rank = '2';
			break;
		}
		case 3:
		{
			rank = '3';
			break;
		}
		case 4:
		{
			rank = '4';
			break;
		}
		case 5:
		{
			rank = '5';
			break;
		}
		case 6:
		{
			rank = '6';
			break;
		}
		case 7:
		{
			rank = '7';
			break;
		}
		case 8:
		{
			rank = '8';
			break;
		}
		case 9:
		{
			rank = '9';
			break;
		}
		case 10:
		{
			rank = '0';
			break;
		}
		case 11:
		{
			rank = 'J';
			break;
		}
		case 12:
		{
			rank = 'Q';
			break;
		}
		case 13:
		{
			rank = 'K';
		}
		}
		for (int suit = 0; suit <= 3; suit++)
		{
			deck.push_back(std::make_shared<Card>(suit, rank));
		}
	}

}

void Deck::ShuffleDeck()
{
	auto rng = std::default_random_engine{static_cast<unsigned int>(time(NULL))};
	std::shuffle(std::begin(deck), std::end(deck), rng);
}

void Deck::RefillDeck()
{
	while (!deck.empty())
	{
		deck.pop_back();
	}
	FillDeck();
	ShuffleDeck();
	
}

void Deck::InitDeck()
{
	FillDeck();
	ShuffleDeck();
}

Card Deck::GiveCard()
{

	return(*deck[0]);
}




#include <iostream>
#include <conio.h>
#include "Cards.h"
#include "Deck.h"
#include "Hand.h"


int main()
{
	std::cout << "Press space to play." << std::endl;
	char begin = _getch();
	bool game_started = false;
	Deck deckone;
	deckone.FillDeck();
	while (game_started = false);
	{
		if (begin == ' ')
		{
			game_started = true;
			Hand Player;
			Player.GetCard(deckone);
			for (int x = 0; x < 2; x++)
			{
				Player.curr_hand[x]->FullCard();
			}
		}
		else
		{
			game_started = false;
		}
	}

	for (int x = 0; x < deckone.deck.size(); x++)
	{
		deckone.deck[x]->FullCard();
	}
	deckone.ShuffleDeck();
	std::cout << "-------------------------------" << std::endl;
	for (int x = 0; x < deckone.deck.size(); x++)
	{
		deckone.deck[x]->FullCard();
	}
	system("pause");
	return 0;
}
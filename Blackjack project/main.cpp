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
	deckone.ShuffleDeck();
	while (game_started = false);
	{
		if (begin == ' ')
		{
			game_started = true;
			Hand Player;
			for (int x = 0; x < 2; x++)
			{
				Player.GetCard(deckone);
				deckone.deck.erase(deckone.deck.begin());
				Player.curr_hand[x].FullCard();
			}
		}
		else
		{
			game_started = false;
		}
	}
	system("pause");
	return 0;
}
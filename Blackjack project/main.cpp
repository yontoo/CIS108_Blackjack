#include <iostream>
#include <conio.h>
#include "Cards.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"


int main()
{
	std::cout << "Press space to play." << std::endl;
	char begin = _getch();
	bool game_started = false;
	Deck deckone;
	deckone.InitDeck();
	while (game_started = false);
	{
		if (begin == ' ')
		{
			Player User;
			User.InitPlayer(deckone);
			deckone.deck.erase(deckone.deck.begin());
			deckone.deck.erase(deckone.deck.begin());
			User.ShowHand();
			game_started = true;
		}
		else
		{
			game_started = false;
		}
	}
	system("pause");
	return 0;
}
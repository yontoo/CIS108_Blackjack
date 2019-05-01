#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Cards.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Dealer.h"

//void EraseDeckElement(Deck*);

int main()
{
	std::cout << "Press space to play." << std::endl;
	char begin = _getch();
	bool game_started = false;
	bool new_hand;
	Deck deckone;
	deckone.InitDeck();
	while (game_started = false);
	{
		if (begin == ' ')
		{
			Player User;
			Dealer Joe;
			User.GetDeck(&deckone);
			Joe.GetDeck(&deckone);
			User.InitPlayer();
			User.MakeBet();
			User.FillHand();
			Joe.FillHand();
			User.Gameflow();
			Joe.FlipCard();
			Joe.CheckVicOrLose();
			User.PlayerOptions();
			Joe.FlipCard();
			Joe.CheckVicOrLose();
			User.PlayerOptions();
			if (User.GetIsStanding())
			{
				Joe.Dealerflow();
				Joe.CheckVicOrLose();
			}
			else
			{
				
			}























			//do
			//{
			//	User.MakeBet();
			//	User.FillHand();
			//	User.Gameflow();
			//	std::cout << "Play a new hand? (y/n)\n";
			//	while (true)
			//	{
			//		char choice = _getch();
			//		if (choice == 'y')
			//		{
			//			new_hand = true;
			//			break;
			//		}
			//		else if (choice == 'n')
			//		{
			//			std::cout << "\n\nClosing";
			//			Sleep(1000);
			//			return 0;
			//		}
			//		else
			//		{
			//			std::cout << "Select a valid choice." << std::endl;
			//		}
			//	}
			//	
			//} while (new_hand);

			//User.ShowHand();
			//User.PlayerOptions();
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


//void EraseDeckElement(Deck* DeckIn)
//{
//	deckone.deck.erase(deckone.deck.begin());
//}
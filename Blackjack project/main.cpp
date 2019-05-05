#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Cards.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Dealer.h"



int main()
{
	std::cout << "Press space to play." << std::endl;
	char begin = _getch();
	bool game_started = false;
	bool new_hand = false;
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
			User.MakeBet();
			while (true)
			{
				if (deckone.deck.size() < 4)
				{
					deckone.RefillDeck();
				}
				if (new_hand)
				{
					User.ResetBet();
					User.MakeBet();
				}
				new_hand = false;
				User.InitPlayer();
				Joe.InitPlayer();
				Joe.SetC2F(0);
				User.FillHand();
				Joe.FillHand();
				User.ShowHand();
				if (User.isBlackjack())
				{

					std::cout << "Player blackjack!" << std::endl;
					User.SetCashWin();
					std::cout << "Play a new hand? (y/n)\n\n";
					while (true)
					{
						char choice = _getch();
						if (choice == 'y')
						{
							new_hand = true;
							break;
						}
						else if (choice == 'n')
						{
							std::cout << "\n\nClosing";
							Sleep(1000);
							return 0;
						}
						else
						{
							std::cout << "select a valid choice." << std::endl;
						}
					}
				}
				else if (Joe.isBlackjack())
				{
					std::cout << "Dealer blackjack!" << std::endl;
					std::cout << "Play a new hand? (y/n)\n\n";
					while (true)
					{
						char choice = _getch();
						if (choice == 'y')
						{
							new_hand = true;
							break;
						}
						else if (choice == 'n')
						{
							std::cout << "\n\nClosing";
							Sleep(1000);
							return 0;
						}
						else
						{
							std::cout << "select a valid choice." << std::endl;
						}
					}
				}
				else
				{
					while (!new_hand)
					{
						new_hand = false;
						bool switching = true;
						char choice;
						while (switching)
						{
							switching = false;
							std::cout << "1. Hit		| 2. Stand		| 3. Surrender" << std::endl;
							choice = _getch();
							switch (choice)
							{
							case '1':
							{
								if (deckone.deck.size() < 4)
								{
									deckone.RefillDeck();
									std::cout << "Refilling and shuffling deck, one moment." << std::endl;
									Sleep(1000);
									std::cout << "Deck filled. Resume game." << std::endl << std::endl;
								}
								User.AddCard();
								User.ShowHand();
								if (User.GetHandVal() > 21)
								{
									std::cout << "Player busts." << std::endl;
									break;
								}
								if (User.GetHandVal() == 21)
								{
									User.SetCashWin();
									std::cout << "Player blackjack!" << std::endl;
									break;
								}
								switching = true;
								break;
							}
							case '2':
							{
								User.Stand();
								Joe.Dealerflow(&User);
								if (User.GetHandVal() > Joe.GetHandVal() && User.GetHandVal() <= 21)
								{
									User.SetCashWin();
									std::cout << "Player value is higher than Dealer, Player wins." << std::endl;
								}
								continue;
							}
							case '3':
							{
								User.Surrender();
								std::cout << "Play a new hand? (y/n)\n\n";
								while (true)
								{
									char choice = _getch();
									if (choice == 'y')
									{
										new_hand = true;
										break;
									}
									else if (choice == 'n')
									{
										std::cout << "\n\nClosing";
										Sleep(1000);
										return 0;
									}
									else
									{
										std::cout << "select a valid choice." << std::endl;
									}
								}
							}
							default:
								std::cout << "Select a valid choice." << std::endl << std::endl;
								switching = true;
							}
						}
						std::cout << "Play a new hand? (y/n)\n\n";
						while (true)
						{
							char choice = _getch();
							if (choice == 'y')
							{
								new_hand = true;
								break;
							}
							else if (choice == 'n')
							{
								std::cout << "\n\nClosing";
								Sleep(1000);
								return 0;
							}
							else
							{
								std::cout << "select a valid choice." << std::endl;
							}
						}
					}
				}
			}
		}

	}
}

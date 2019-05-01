#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

void Player::InitPlayer()
{
	bet = 0;
	hand_value = 0;
	canGetCard = true;
	canDouble = true;
	canSplit = false;
	isStanding = false;
	isDoubling = false;
	isSplit = false;
	hasHit = false;
}

void Player::FillHand()
{
	for (int x = 0; x < 2; x++)
	{
		PlayerHand.GetCard(deck_ptr);
		deck_ptr->deck.erase(deck_ptr->deck.begin());
	}
}

void Player::MakeBet()
{
	std::cout << "You have $" << cash << " to bet with." << std::endl;
	do
	{
		std::cout << "Place your bet(min. $200, max: $5000): ";
		std::cin >> bet;			//Gonna want a try block here, send an error if its a non int.
		if (bet < 200 || bet > 5000)
		{
			std::cout << "Please enter a valid bet." << std::endl << std::endl;
			validBet = false;
		}
		else
		{
			cash -= bet;
			validBet = true;
		}
	} while (!validBet);
}


//Outputs current hand to player.
void Player::ShowHand()
{
	std::cout << "Your hand" << std::endl;
	for (int x = 0; x < PlayerHand.curr_hand.size(); x++)
	{
		PlayerHand.curr_hand[x].FullCard();
		hand_value += PlayerHand.curr_hand[x].GetVal();
	}
	
	if (hand_value > 21)
	{
		lose = true;
	}
	else if (hand_value == 21)
	{
		win = true;
	}
	

	//Determine if the player can split or not.
	if (PlayerHand.curr_hand[0].GetVal() == PlayerHand.curr_hand[1].GetVal() && !hasHit)
	{
		canSplit = true;
	}
	std::cout << "______________________________" << std::endl;
	std::cout << "Hand value: " << hand_value << std::endl << std::endl;
	if (isSplit)
	{
		std::cout << "______________________________" << std::endl;
		std::cout << "Split hand value: " << hand_value << std::endl;
	}
}


void Player::AddCard()
{
	PlayerHand.GetCard(deck_ptr);
	deck_ptr->deck.erase(deck_ptr->deck.begin());
}

//Fundamentally the same as the previous add function, this just adds to the split hand instead.
void Player::AddSplitCard()
{
	SplitHand.GetCard(deck_ptr);
	deck_ptr->deck.erase(deck_ptr->deck.begin());
}



//Provides menu to player.
void Player::PlayerOptions()
{
	bool switching = true;
	char choice;
	if (!canSplit && canDouble && canGetCard)
	{
		while (switching)
		{
			switching = false;
			std::cout << "1. Hit		| 2. Stand		| 3. Double		| 4. Surrender" << std::endl;
			choice = _getch();
			switch (choice)
			{
			case '1':
			{
				AddCard();
				hasHit = true;
				canDouble = false;
				break;
			}
			case '2':
			{
				canGetCard = false;
				isStanding = true;
				break;
			}
			case '3':
			{
				Double();
				break;
			}

			case '4':
			{
				Surrender();
			}
			default:
				std::cout << "Select a valid choice." << std::endl << std::endl;
				switching = true;

			}
		}
	}
	else if (canSplit && canDouble && canGetCard)
	{
		std::cout << "1. Hit		| 2. Stand		| 3. Double		| 4. Split		| 5. Surrender" << std::endl;
		choice = _getch();
		switch (choice)
		{
		case '1':
		{
			AddCard();
			hasHit = true;
			canDouble = false;
			break;
		}
		case '2':
		{
			canGetCard = false;
			isStanding = true;
			break;
		}
		case '3':
		{
			Double();
			break;
		}

		case '4':
		{
			Split();
			break;
		}
		case '5':
		{
			Surrender();
		}
		default:
			std::cout << "Select a valid choice." << std::endl << std::endl;
			switching = true;
		}
	}
	else if (canSplit && !canDouble && canGetCard)
	{
		std::cout << "1. Hit		| 2. Stand		| 3. Surrender		| 4. Split" << std::endl;
		choice = _getch();
		switch (choice)
		{
		case '1':
		{
			AddCard();
			hasHit = true;
			canDouble = false;
			break;
		}
		case '2':
		{
			canGetCard = false;
			isStanding = true;
			break;
		}
		case '3':
		{
			Double();
			break;
		}

		case '4':
		{
			Surrender();
		}
		default:
			std::cout << "Select a valid choice." << std::endl << std::endl;
			switching = true;

		}
	}
	else
	{
		while (switching)
		{
			switching = false;
			std::cout << "1. Hit		| 2. Stand		| 3. Surrender" << std::endl;
			choice = _getch();
			switch (choice)
			{
			case '1':
			{
				AddCard();
				canDouble = false;
				break;
			}
			case '2':
			{
				canGetCard = false;
				isStanding = true;
				break;
			}
			case '3':
			{
				Surrender();
			}
			default:
				std::cout << "Select a valid choice." << std::endl << std::endl;
				switching = true;
			}
		}
	}

}



void Player::GetDeck(Deck * DeckIn)
{
	deck_ptr = DeckIn;
}

void Player::Surrender()
{
	std::cout << "Player surrendered, returning $" << (bet / 2) << std::endl;
	cash += (bet / 2);
	lose = true;
	//for (int x = 0; x <= PlayerHand.curr_hand.size() + 1; x++)
	while (!PlayerHand.curr_hand.empty())
	{
		PlayerHand.curr_hand.pop_back();
	}
}

void Player::Double()
{
	canDouble = false;
	bet += bet;
	cash -= bet;
	std::cout << "Player doubling.\nCash: " << cash << "\nCurrent bet: " << bet << std::endl;
	isStanding = true;
}


//Move card at index 1 of Player's hand to new hand, clear out the empty index left by the move and add one card to each new hand.
void Player::Split()
{
	isSplit = true;
	SplitHand.curr_hand.push_back(std::move(PlayerHand.curr_hand[1]));
	PlayerHand.curr_hand.erase(PlayerHand.curr_hand.begin() + 1);
	AddCard();
	AddSplitCard();
}


void Player::Gameflow()
{
	 do {
		ShowHand();
		PlayerOptions();
		hand_value = 0;
	} while (!lose);
	lose = false;
	InitPlayer();
}

int Player::GetHandVal()
{
	return hand_value;
}

bool Player::GetIsStanding()
{
	return isStanding;
}
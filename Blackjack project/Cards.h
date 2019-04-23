#pragma once
#include <string>

class Card
{
public:
	Card(int, char);			//I don't think I need a default constructor since I will only be making cards with data from other objects.
	Card(Card&);			
	~Card();
	void FullCard();


private:
	std::string full_card;
	int card_val;
	int card_suit;
	char card_rank;
	enum Values
	{
		ACE = 1,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
	};
	enum Suit
	{
		SPADES,
		CLUBS,
		DIAMONDS,
		HEARTS
	};

	int GiveValue();
};


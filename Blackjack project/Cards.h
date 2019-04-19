#pragma once


class Card
{
public:
	Card();
	~Card();

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
		JACK = 10,
		QUEEN = 10,
		KING = 10,
		ACE2, //Option used later for if player decides to use ACE as an 11.
	};
	enum Suit
	{
		SPADES,
		CLUBS,
		DIAMONDS,
		HEARTS
	};


};


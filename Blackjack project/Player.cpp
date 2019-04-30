#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

void Player::InitPlayer(Deck DeckIn)
{
	for (int x = 0; x < 2; x++)
	{
		PlayerHand.GetCard(DeckIn);
	}
	cash = 10000;
	bet = 0;
}
void Player::ShowHand()
{
	for (int x = 0; x < 2; x++)
	{
		PlayerHand.curr_hand[x].FullCard();
	}
}

// unittest_Blackjack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "gtest/gtest.h"
#include "Player.h"
#include "Cards.h"
#include "Deck.h"
#include "Hand.h"

TEST(testBet, valid_bet_test)
{
	EXPECT_TRUE(validBet);
}

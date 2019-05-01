#include "Cards.h"
#include "Hand.h"
#include <iostream>
#include <conio.h>
#pragma once
class Player
{
public:
	Player();
	~Player();
	void InitPlayer();
	void ShowHand();
	void MakeBet();
	virtual void FillHand();
	void AddCard();					//Function called to add one card to hand in the case of a hit
	void PlayerOptions();			//Hit, Stand, Double, Split, Surrender
	void GetDeck(Deck *);			//Returns pointer to main deck object
	void Gameflow();
	bool GetIsStanding();
protected:
	Hand PlayerHand;
	Deck* deck_ptr;
	int hand_value;
	int GetHandVal();
	bool win = false;
	bool lose = false;
	bool push = false;
private:
	int bet;
	int cash = 10000;
	bool hasHit;
	bool isStanding;
	bool isDoubling;
	bool isSplit;
	bool canSplit;
	bool canDouble;
	bool canGetCard;
	bool validBet = false;
	Hand SplitHand;				//In the case that the player splits.
	void Stand();
	void Double();
	void Split();
	void Surrender();			//Player forfeits their hand and receives half their bet back.
	void AddSplitCard();		//Adds a card to the split hand.


	

};


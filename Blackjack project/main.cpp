#include "Cards.h"
#include "Deck.h"

int main()
{
	Deck deckone;
	deckone.FillDeck();
	for (int x = 0; x < deckone.deck.size(); x++)
	{
		deckone.deck[x]->FullCard();
	}
	system("pause");
	return 0;
}
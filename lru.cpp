// First In First Out Algorithm implementation

#include "lru.h"

// constructor
LeastRecentlyUsedAlgorithm::LeastRecentlyUsedAlgorithm() {};

// method finds the victim and deletes it
// victim is the entry with the smallest hit ratio put in
// returns the position of the entry
int LeastRecentlyUsedAlgorithm::findVictim()
{
	int position;
	int leastRecentlyUsed = 16;

	// loop through table to find least recently used entry
	for (int i = 0; i < TLB_SIZE; i++)
	{
		if (TLBHitRatio[i] < leastRecentlyUsed)
		{
			leastRecentlyUsed = TLBHitRatio[i];
			position = i;
		}
	}

	// delete the entry
	TLBEntry[position].page.value_ = -1;
	TLBEntry[position].frame.value_ = -1;

	return position;
}

// method replaces the victim with entry
void replace(int position, Word pg)
{
	TLBEntries[position].page.value_ = pg.value_;
	TLBEntries[position].frame.value_ = // access pagetable for frame number
}
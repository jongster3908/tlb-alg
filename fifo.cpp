// First In First Out Algorithm implementation

#include "fifo.h"

// constructor
FirstInFirstOutAlgorithm::FirstInFirstOutAlgorithm() {};

// method finds the victim and deletes it
// victim is the first pagenumber put in for FIFO
Word FirstInFirstOutAlgorithm::findVictim()
{
	// first entry is always at the 0 index
	front = TLBEntries[0].page.value_;

	// scoot every entry over
	// this overwrites the first entry and so deleting it
	for (int i = 0; i < TLB_SIZE-1; i++)
	{
		TLBEntries[i].page.value_ = TLBEntries[i + 1].page.value_;
		TLBEntries[i].frame.value_ = TLBEntries[i + 1].frame.value_;
	}

	// empty last slot
	TLBEntries[15].page.value_ = -1;
	TLBEntries[15].frame.value_ = -1;

	// return the victim
	return front;
}

// method finds empty slot and enters new entry
void replace(Word pg)
{
	// input new entry into last slot
	TLBEntries[15].page.value_ = pg;
	TLBEntries[15].frame.value_ = // access pagetable for frame number
}
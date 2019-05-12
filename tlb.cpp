// TLB class implementation file

#include "tlb.h"
#include <iostream>
using namespace std;

// Constructor
TLB::TLB()
{
	// default values for variables
	for (int i = 0; i < TLB_SIZE; i++)
	{
		TLBEntries[i].page.value_ = -1;
		TLBEntries[i].frame.value_ = -1;
	}
	TLBHitRatio = { -1 };
	size = 0;
}

// method checks if the TLB is full
bool TLB::isFull()
{
	if (size == TLB_SIZE)
		return true;
	else
		return false;
}

// method checks if the pagenumber exists in the TLB
// if it exists, return the position of the pagenumber in the array
// returns -1 if it doesn't exist
int TLB::hit(Word pg)
{
	int position;

	for (int i = 0; i < TLB_SIZE; i++)
	{
		if (TLBEntries[i].page.value_ == pg.value_)
		{
			return i;
		}
	}

	return -1;
}

// access method
// adds a new entry to the TLB if it doesn't exist in TLB
void TLB::access(Word pg)
{
	// if TLB not full
	if (!isFull)
	{
		// if entry does not exist in TLB, add it
		if (hit(pg) == -1)
		{
			for (int i = 0; i < TLB_SIZE; i++)
			{
				// first empty slot
				// needs to reference page table to get frame number
				if (TLBEntries[i].page.value_ == -1)
				{
					TLBEntries[i].page.value_ = pg;
					TLBEntries[i].frame.value_ = //???
					TLBHitRatio[i] = 16;
					size++;
					break;
				}
			}
		}

		// if entry already exist in TLB, update hit ratio
		else
		{
			for (int i = 0; i < TLB_SIZE; i++)
			{
				// decrement hit ratio if position is not empty and is not an entry
				if (TLBHitRatio[i] != -1 && i != hit(pg))
				{
					TLBHitRatio[i]--;
				}
			}
			TLBHitRatio[hit(pg)] = 16;
		}
	}

	// if TLB is full, check if the pagenumber exists in the TLB
	else if (isFull)
	{
		// if the pagenumber doesn't exist in TLB
		// then use page replacement algorithm and update fault counter
		if (hit(pg) == -1)
		{
			tlbFaults(); // increase tlb_faults_ counter
			PageReplacementAlgorithm(); // call the replacement algorithm
		}

		// if page already exists in TLB
		// then do not add, but update hit ratio
		else
		{
			for (int i = 0; i < TLB_SIZE; i++)
			{
				// if entry is miss, decrement hit ratio
				if (TLBEntries[i].page.value_ != pg.value_)
				{
					TLBHitRatio[i]--;
				}

				// if the entry is a hit, then set hit ratio to 16
				else if (TLBEntries[i].page.value_ == pg.value_)
				{
					TLBHitRatio[i] = 16;
				}
			}
		}
	}
}
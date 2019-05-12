// Least Recently Used Algorithm header

#ifndef LRU_H
#define LRU_H

#include "pra.h"
#include "tlb.h"

class LeastRecentlyUsedAlgorithm
{
public:
	Word findVictim();
	LeastRecentlyUsedAlgorithm() {};
	void replace(Word pg);
};

#endif
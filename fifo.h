// First In First Out Algorithm header
// inherits the Page Replacement Algorithm Class

#ifndef FIFO_H
#define FIFO_H

struct FirstInFirstOutAlgorithm : PageReplacementAlgorithm
{
public:
	// method finds the victim
	Word findVictim();

	// constructor
	FirstInFirstOutAlgorithm() {};

	// method replaces the victim with new entry
	void replace(Word pg);
};

#endif
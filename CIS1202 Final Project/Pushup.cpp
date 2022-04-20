#include "Pushup.h"

// Constructors.
Pushup::Pushup() {
	setHands(0);
	setReps(0);
}

Pushup::Pushup(int h) {
	setHands(h);
	setReps(0);
}

Pushup::Pushup(int h, int r) {
	setHands(h);
	setReps(r);
}

// Setters or Mutators.
void Pushup::setHands(int h) {
	Pushup::hands = h;
}
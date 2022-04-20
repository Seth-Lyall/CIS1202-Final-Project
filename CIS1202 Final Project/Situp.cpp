#include "Situp.h"

// Constructors.
Situp::Situp() {
	setSecondsPer(0);
	setReps(0);
}

Situp::Situp(double s) {
	setSecondsPer(s);
	setReps(0);
}

Situp::Situp(double s, int r) {
	setSecondsPer(s);
	setReps(r);
}

// Setters or Mutators.
void Situp::setSecondsPer(double s) {
	Situp::secondsPer = s;
}
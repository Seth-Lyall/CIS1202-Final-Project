#include "Exercise.h"

// Constructors.
Exercise::Exercise() {
	setReps(0);
}

Exercise::Exercise(int r) {
	setReps(r);
}

// Setters and Mutators.
void Exercise::setReps(int r) {
	Exercise::reps = r;
}

void Exercise::halfReps() {
	setReps(getReps() / 2);
}

void Exercise::doubleReps() {
	setReps(getReps() * 2);
}

void Exercise::squareReps() {
	setReps(pow(getReps(), 2));
}

void Exercise::cubeReps() {
	setReps(pow(getReps(), 3));
}
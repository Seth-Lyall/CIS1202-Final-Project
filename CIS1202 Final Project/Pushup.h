#pragma once
#ifndef PUSHUP_H
#define PUSHUP_H

#include "Exercise.h"
using namespace std;

class Pushup : public Exercise {
private:
	// Member variables.
	int hands;
public:
	// Constructors.
	Pushup();
	Pushup(int);
	Pushup(int, int);
	// Display Information.
	void displayInfo() {
		cout << "Reps: " << getReps();
		cout << "\nHands: " << getHands();
	};
	// Getters.
	int getHands() {
		return hands;
	};
	// Setters.
	void setHands(int);
};
#endif
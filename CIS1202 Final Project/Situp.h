#pragma once
#ifndef SITUP_H
#define SITUP_H

#include "Exercise.h"
using namespace std;

class Situp : public Exercise {
private:
	// Member variables.
	double secondsPer;
public:
	// Constructors.
	Situp();
	Situp(double);
	Situp(double, int);
	// Display Information.
	void displayInfo() {
		cout << "Reps: " << getReps();
		cout << "\nSecondsPer: " << getSecondsPer();
	};
	// Getters.
	double getSecondsPer() {
		return secondsPer;
	};
	// Setters.
	void setSecondsPer(double);
};
#endif
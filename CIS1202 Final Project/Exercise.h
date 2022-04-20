#pragma once
#ifndef EXERCISE_H
#define EXERCISE_H

#include <iostream>
#include <cmath>
using namespace std;

class Exercise {
private:
	// Member variables.
	int reps;
public:
	// Constructors.
	Exercise();
	Exercise(int);
	// Display Information.
	void displayInfo() {
		cout << "Reps: " << getReps();
	};
	// Getters.
	int getReps() {
		return reps;
	};
	// Setters.
	void setReps(int);
	// Mutators.
	void halfReps();
	void doubleReps();
	void squareReps();
	void cubeReps();
};
#endif
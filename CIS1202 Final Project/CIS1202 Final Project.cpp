// Seth Lyall
// CIS1202 K01
// 4-18-2022
// This program keeps a user generated exercise log in a binary
// file that gets progressively more difficult each time the
// exercises are schedueled.

#include "PersonalLibrary.h"
#include "Pushup.h"
#include "Situp.h"
using namespace std;

int displayMenu();
void createFile(fstream&);
Pushup enterPushups();
Situp enterSitups();
void displayExercises(fstream&, unsigned long long&);

int main() {

	int choice = 0;
	unsigned long long day = 0;
	fstream exerciseFile;

	do {
		choice = displayMenu();

		switch (choice) {
		case 1:
			createFile(exerciseFile);
			if (exerciseFile.is_open()) {
				exerciseFile.close();
				exerciseFile.open("exercise.dat", ios::in | ios::out | ios::binary);
			}
			break;
		case 2:
			if (!exerciseFile.is_open()) {
				cout << "\nERROR: The file is not open.\n\n";
			}
			else {
				displayExercises(exerciseFile, day);
			}
			break;
		default:
			exerciseFile.close();
			if (!remove("exercise.dat")) {
				cout << "\nFile deleted successfully.";
			}
			else {
				cout << "\nFailed to delete the file, or file does not exist.";
			}
			break;
		}

	} while (choice != 3);

	endProgram();
}

/************************************************
Displays a menu at the start of the program,	*
so they user can choose an action.				*
************************************************/
int displayMenu() {
	int choice = 0;

	cout << "1. Create exercise file.\n";
	cout << "2. Display exercises.\n";
	cout << "3. End program.\n";

	choice = validateInteger("Choose an action: ", 1, 3);

	return choice;
}

/************************************************
Creates a file for the user to store exercises,	*
and has the user input the first records.		*
************************************************/
void createFile(fstream &exerciseFile) {
	if (exerciseFile.is_open()) {
		cout << "\nERROR: The file has already been created.\n\n";
	}
	else {
		exerciseFile.open("exercise.dat", ios::out | ios::binary);
		if (!exerciseFile.fail()) {

			Pushup Pushups = enterPushups();
			Situp Situps = enterSitups();

			exerciseFile.clear(ios::eofbit);
			exerciseFile.seekg(0L, ios::beg);

			exerciseFile.write(reinterpret_cast<char*>(&Pushups), sizeof(Pushups));
			exerciseFile.write(reinterpret_cast<char*>(&Situps), sizeof(Situps));

			cout << "\nFile Created Successfully, the first records have been added.\n\n";
		}
		else {
			cout << "\nERROR: The file was not opened.\n\n";
		}
	}
}

/************************************************
Has the user enter the number of pushups they	*
are going to do initially, and how many hands	*
they are going to use, then returns the			*
information in that class.						*
************************************************/
Pushup enterPushups() {
	Pushup Pushups;
	int reps = 0;
	int hands = 0;
	reps = validateInteger("Enter the number of pushup reps: ", 0);
	if (reps != 0) {
		hands = validateInteger("Enter the number of hands you will use for your reps (1 or 2): ", 1, 2);
		Pushups.setReps(reps);
		Pushups.setHands(hands);
	}
	else {
		cout << "No reps entered, no exercise added.\n";
	}
	return Pushups;
}

/************************************************
Has the user enter the number of situps they	*
are going to do initially, and the duration of	*
each situp, then returns the information in		*
that class.										*
************************************************/
Situp enterSitups() {
	Situp Situps;
	int reps = 0;
	int secondsPer = 0;
	reps = validateInteger("Enter the number of situp reps: ", 0);
	if (reps != 0) {
		secondsPer = validateDouble("Enter the number of seconds you will perform each situp: ", 1);
		Situps.setReps(reps);
		Situps.setSecondsPer(secondsPer);
	}
	else {
		cout << "No reps entered, no exercise added.\n";
	}
	return Situps;
}

/************************************************
Asks the user how they want to alter their		*
exercises for that day, and reads the classes	*
from the binary file to change them, displays	*
the changes, and writes the information back to	*
the file. The function then increments the day.	*
************************************************/
void displayExercises(fstream &exerciseFile, unsigned long long &day) {
	int choice = 0;
	Pushup Pushups;
	Situp Situps;
	choice = validateInteger("How would you like to alter your exercises today?\n1. Cut them in half.\n2. Double them.\n3. Square them.\n4. Cube them.\n5. Don't change them.\n", 1, 5);
	cout << "\n";

	exerciseFile.seekg(0L, ios::beg);
	exerciseFile.seekg(day * (sizeof(Pushups) + sizeof(Situps)), ios::beg);
	exerciseFile.read(reinterpret_cast<char*> (&Pushups), sizeof(Pushups));

	switch (choice) {
	case 1:
		Pushups.halfReps();
		Pushups.displayInfo();
		cout << "\n";
		break;
	case 2:
		Pushups.doubleReps();
		Pushups.displayInfo();
		cout << "\n";
		break;
	case 3:
		Pushups.squareReps();
		Pushups.displayInfo();
		cout << "\n";
		break;
	default:
		Pushups.cubeReps();
		Pushups.displayInfo();
		cout << "\n";
		break;
	}

	exerciseFile.seekg(((day + 1) * (sizeof(Pushups) + sizeof(Situps))), ios::beg);
	exerciseFile.write(reinterpret_cast<char*>(&Pushups), sizeof(Pushups));

	exerciseFile.seekg(0L, ios::beg);
	exerciseFile.seekg((day * (sizeof(Pushups) + sizeof(Situps))) + sizeof(Pushups), ios::beg);
	exerciseFile.read(reinterpret_cast<char*> (&Situps), sizeof(Situps));

	switch (choice) {
	case 1:
		Situps.halfReps();
		Situps.displayInfo();
		cout << "\n";
		break;
	case 2:
		Situps.doubleReps();
		Situps.displayInfo();
		cout << "\n";
		break;
	case 3:
		Situps.squareReps();
		Situps.displayInfo();
		cout << "\n";
		break;
	default:
		Situps.cubeReps();
		Situps.displayInfo();
		cout << "\n";
		break;
	}

	exerciseFile.seekg(((day + 1) * (sizeof(Pushups) + sizeof(Situps))) + sizeof(Pushups), ios::beg);
	exerciseFile.write(reinterpret_cast<char*>(&Situps), sizeof(Situps));

	day++;
	cout << "\n";

}
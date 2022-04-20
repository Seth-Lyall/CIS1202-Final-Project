#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <random>
#include <array>
#include <fstream>
#include <filesystem>
using namespace std;

void endProgram() {
	cout << "\n\n**********************************\n";
	cout << "Press ENTER to exit the program...";
	cin.ignore(100, '\n');
	cin.get();
	exit(0);
}

int randomNumber(int min, int max) {
	int number = 0;
	std::random_device rand_dev;
	std::mt19937 generator(rand_dev());
	std::uniform_int_distribution<int> distr(min, max);
	number = distr(generator);
	return number;
}

int validateInteger(string prompt) {
	int num = 0;
	cout << "\n" << prompt;
	while (!(cin >> num) || cin.fail()) {
		cout << "\nERROR: Invalid Data Entered, Please Try Again." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << prompt;
	}
	return num;
}

int validateInteger(string prompt, int min) {
	int num = 0;
	cout << "\n" << prompt;
	while (!(cin >> num) || cin.fail() || num < min) {
		cout << "\nERROR: Invalid Data Entered, Please Try Again." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << prompt;
	}
	return num;
}

int validateInteger(string prompt, int min, int max) {
	int num = 0;
	cout << "\n" << prompt;
	while (!(cin >> num) || cin.fail() || (num < min || num > max)) {
		cout << "\nERROR: Invalid Data Entered, Please Try Again." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << prompt;
	}
	return num;
}

double validateDouble(string prompt) {
	double num = 0.00;
	cout << "\n" << prompt;
	while (!(cin >> num) || cin.fail()) {
		cout << "\nERROR: Invalid Data Entered, Please Try Again." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << prompt;
	}
	return num;
}

double validateDouble(string prompt, double min) {
	double num = 0.00;
	cout << "\n" << prompt;
	while (!(cin >> num) || cin.fail() || num < min) {
		cout << "\nERROR: Invalid Data Entered, Please Try Again." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << prompt;
	}
	return num;
}

double validateDouble(string prompt, double min, double max) {
	double num = 0.00;
	cout << "\n" << prompt;
	while (!(cin >> num) || cin.fail() || (num < min || num > max)) {
		cout << "\nERROR: Invalid Data Entered, Please Try Again." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << prompt;
	}
	return num;
}

float validateFloat(string prompt) {
	float num = 0.00;
	cout << "\n" << prompt;
	while (!(cin >> num) || cin.fail()) {
		cout << "\nERROR: Invalid Data Entered, Please Try Again." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << prompt;
	}
	return num;
}

float validateFloat(string prompt, float min, float max) {
	float num = 0.00;
	cout << "\n" << prompt;
	while (!(cin >> num) || cin.fail() || (num < min || num > max)) {
		cout << "\nERROR: Invalid Data Entered, Please Try Again." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << prompt;
	}
	return num;
}

char validateChar(string prompt) {
	char num;
	cout << "\n" << prompt;
	while (!(cin >> num) || cin.fail()) {
		cout << "\nERROR: Invalid Data Entered, Please Try Again." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << prompt;
	}
	return num;
}

char validateChar(string prompt, char min) {
	char num;
	cout << "\n" << prompt;
	while (!(cin >> num) || cin.fail() || num != min) {
		cout << "\nERROR: Invalid Data Entered, Please Try Again." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << prompt;
	}
	return num;
}

char validateChar(string prompt, char min, char max) {
	char num;
	cout << "\n" << prompt;
	while (!(cin >> num) || cin.fail() || (num != min && num != max)) {
		cout << "\nERROR: Invalid Data Entered, Please Try Again." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << prompt;
	}
	return num;
}
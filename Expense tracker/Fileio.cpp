#include "Expense.h"
#include <vector>
#include <iostream>
#include <fstream>


string filename = "Expenses";

string toString(ExpenseType type);

int file_open(vector<Expense>& v) {
	ifstream File(filename + ".txt");

	if (!File) {
		system("cls");
		cout << "Error while opening file. Try again.";
		getchar();
		getchar();
		return 1;
	}

	while (!File.eof()) {
		Expense exp;
		string sType;
		File >> exp.sName >> exp.fCost >> sType;
		if (sType == "Entertainment") {
			exp.eType = ExpenseType::ENTERTAINMENT;
		}
		else if (sType == "Clothes") {
			exp.eType = ExpenseType::CLOTHES;
		}
		else if (sType == "Transport") {
			exp.eType = ExpenseType::TRANSPORT;
		}
		else if (sType == "Food") {
			exp.eType = ExpenseType::FOOD;
		}
		else if (sType == "Traveling") {
			exp.eType = ExpenseType::TRAVELING;
		}
		else if (sType == "Restaurants") {
			exp.eType = ExpenseType::RESTAURANTS;
		}
		else if (sType == "Electronics") {
			exp.eType = ExpenseType::ELECTRONICS;
		}
		else {
			exp.eType = ExpenseType::OTHER;
		}
		if (File.eof()) {
			break;
		}
		v.push_back(exp);
	}

	File.close();
	return 0;
}

int file_close(vector<Expense>& v) {
	ofstream File(filename + ".txt");

	if (!File) {
		system("cls");
		cout << "Error while saving file. Try again.";
		getchar();
		getchar();
		return 1;
	}

	for (int i = 0; i < v.size(); i++) {
		File << v[i].sName << " " << v[i].fCost << " " << toString(v[i].eType) << endl;
	}

	File.close();
	return 0;
}
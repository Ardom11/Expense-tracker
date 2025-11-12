#include "Expense.h"
#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

string toString(ExpenseType type);

void show_expense(vector<Expense>& v);

void add_expense(vector<Expense>& v) {
	Expense exp;

	cout << "Enter title of expense: ";
	//getline(cin, exp.sName);
	cin >> exp.sName;

	cout << "Enter value of expense: ";
	cin >> exp.fCost;

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "Enter type of expense" << endl << "1 Entertainment" << endl << "2 Clothes" << endl << "3 Transport"
		<< endl << "4 Food" << endl << "5 Traveling" << endl << "6 Restaurants" << endl << "7 Electronics" << endl << "8 Other" << endl;
	unsigned int iChoice;
	cin >> iChoice;

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	exp.eType = static_cast<ExpenseType>(iChoice-1);

	v.push_back(exp);
}

void delete_expense(vector<Expense>& v) {
	if (v.empty()) {
		cout << "No expense to delete";
		getchar();
		getchar();
		return;
	}

	show_expense(v);

	unsigned int pos;
	unsigned int iStatus = 1;
	while (iStatus)
	{
		cout << "Enter expense position you want to delete(0 to exit): ";
		cin >> pos;

		if (pos == 0) {
			return;
		}

		if (pos < 0 || pos > v.size()) {
			cout << "Wrong position" << endl;
			continue;
		}

		iStatus = 0;
	}

	v.erase(v.begin() + pos - 1);

	system("cls");
	show_expense(v);
	getchar();
	getchar();
}

float calculate_expenses(vector<Expense>& v) {
	if (v.empty()) {
		cout << "No expenses" << endl;
		getchar();
		getchar();
		return 0;
	}
	
	float sum = 0;

	for (auto exp : v) {
		sum += exp.fCost;
	}

	return sum;
}

void show_expense(vector<Expense>& v) {
	if (v.empty()) {
		cout << "No expenses";
		getchar();
		getchar();
		return;
	}
	
	cout << "Value of expenses " << calculate_expenses(v) << endl;
	cout << endl;
	cout << "TITLE      VALUE          TYPE" << endl;
	for (auto& exp : v) {
		cout << exp.sName << setw(10) << exp.fCost << setw(10) << toString(exp.eType) << endl;
	}

	getchar();
	getchar();
}

string toString(ExpenseType type) {
	static const array<string, 8> names = {
		"Entertainment",
		"Clothes",
		"Transport",
		"Food",
		"Traveling",
		"Restaurants",
		"Electronics",
		"Other"
	};

	return names[static_cast<int>(type)];
}
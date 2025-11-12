#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include <array>

using namespace std;

enum class ExpenseType {
	ENTERTAINMENT,
	CLOTHES,
	TRANSPORT,
	FOOD,
	TRAVELING,
	RESTAURANTS,
	ELECTRONICS,
	OTHER
};

typedef struct Expense {
	string sName;
	float fCost;
	ExpenseType eType;
};

#endif
#ifndef FUNC_H
#define FUNC_H

#include "Expense.h"
#include <vector>

void add_expense(vector<Expense> &v);

void delete_expense(vector<Expense>& v);

float calculate_expenses(vector<Expense>& v);

void show_expense(vector<Expense>& v);

#endif 
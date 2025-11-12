#include "Expense.h"
#include "Fileio.h"
#include "Menu.h"
#include <vector>

int main() {
	vector<Expense> Expenses;

	if (file_open(Expenses)) {
		return 1;
	}

	menu(Expenses);

	return 0;
}
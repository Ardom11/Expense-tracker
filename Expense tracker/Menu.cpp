//#include "Expense.h"
#include "Func.h"
#include "Fileio.h"
#include <iostream>
#include <vector>

void menu(vector<Expense>& v) {
	unsigned int iStatus = 1;
	unsigned int iChoice ;

	while (iStatus) {
		system("cls");
		cout << "1 Show expenses" << endl << "2 Add expense" << endl << "3 Delete expense" << endl << "4 Exit" << endl;
		cin >> iChoice;

		switch (iChoice) {
		//Show expenses
		case 1:
			system("cls");
			show_expense(v);
			break;

		//Add expense
		case 2:
			system("cls");
			add_expense(v);
			break;

		//Delete expense
		case 3:
			system("cls");
			delete_expense(v);
			break;

		//Save and exit
		case 4:
			system("cls");
			file_close(v);
			iStatus = 0;
			break;

		default:
			cout << "Wrong choice" << endl;
		}
	}
}
#ifndef FILEIO_H
#define FILEIO_H

#include "Expense.h"
#include <vector>

int file_open(vector<Expense> &v);

int file_close(vector<Expense> &v);

#endif;
/*
 * BooleanMatrix.h
 *
 *  Created on: Aug 5, 2013
 *      Author: Avinash
 */
//
// Testing Status
//
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>

using namespace std;
using namespace __gnu_cxx;

#define null NULL
#define PRINT_NEW_LINE printf("\n")
//int main(){
//	return -1;
//}

#ifndef BOOLEANMATRIX_H_
#define BOOLEANMATRIX_H_

#define ROWS_BOOLEAN_MATRIX 10
#define COLUMN_BOOLEAN_MATRIX 12

void BooleanMatrix(bool userInput[ROWS_BOOLEAN_MATRIX][],int rows,int columns){
	if(userInput == NULL){
		return;
	}
	bool rowFlag[rows];
	bool columnFlag[columns];
	for(int rowCounter = 0;rowCounter < rows;rowCounter++){
		for(int columnCounter = 0;columnCounter < columns;columnCounter++){
			if(userInput[rowCounter][columnCounter]){
				rowFlag[rowCounter] = true;
				columnFlag[columnCounter] = true;
			}
		}
	}

	for(int rowCounter = 0;rowCounter < rows;rowCounter++){
		for(int columnCounter = 0;columnCounter < columns;columnCounter++){
			if(rowFlag[rowCounter] && columnFlag[columnCounter]){
				userInput[rowCounter][columnCounter] = true;
			}
		}
	}
}

#endif /* BOOLEANMATRIX_H_ */

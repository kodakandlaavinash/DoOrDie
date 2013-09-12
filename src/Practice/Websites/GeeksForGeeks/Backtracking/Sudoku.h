/*
 * Sudoku.h
 *
 *  Created on: Sep 5, 2013
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

#ifndef SUDOKU_H_
#define SUDOKU_H_

#define MAX_ROWS_SUDOKU 10
#define MAX_COLUMNS_SUDOKU 10
#define SUDOKU_UNASSIGNED_BLOCK -1

bool IsSafeForSudoku(int userInput[][MAX_COLUMNS_SUDOKU],int noOfRows,int noOfColumns,int currentRowIndex,int currentColumnIndex,int placeValue){
	if(currentRowIndex == noOfRows && currentColumnIndex == noOfColumns){
		return true;
	}
	//Checking in horizontal
	for(int columnCounter = 0;columnCounter < noOfColumns;columnCounter++){
		if(columnCounter == currentColumnIndex){
			continue;
		}
		if(userInput[currentRowIndex][columnCounter] == placeValue){
			return false;
		}
	}

	//Checking in vertical
	for(int rowCounter = 0;rowCounter < noOfRows;rowCounter++){
		if(rowCounter == currentRowIndex){
			continue;
		}
		if(userInput[rowCounter][currentColumnIndex] == placeValue){
			return false;
		}
	}

	//Checking in box
	int rowIndexStart = currentRowIndex/3;
	int columnIndexStart = currentColumnIndex/3;
	for(int rowCounter = rowIndexStart;rowCounter < rowIndexStart+3;rowCounter++){
		for(int columnCounter = columnIndexStart;columnCounter < columnIndexStart+3;columnCounter++){
			if(userInput[rowCounter][columnCounter] == placeValue){
				return false;
			}
		}
	}
	return true;
}

bool SolveSudokuPuzzle(int userInput[][MAX_COLUMNS_SUDOKU],int noOfRows,int noOfColumns,int currentRowIndex,int currentColumnIndex){
	if(currentRowIndex == noOfRows && currentColumnIndex == noOfColumns){
		return true;
	}
	if(currentRowIndex >= noOfRows || currentColumnIndex >= noOfColumns){
		return false;
	}
	int rowCounter,columnCounter;
	for(rowCounter = 0;rowCounter < noOfRows;rowCounter++){
		for(columnCounter = 0;columnCounter < noOfColumns;columnCounter++){
			if(userInput[rowCounter][columnCounter] == SUDOKU_UNASSIGNED_BLOCK){
				for(int placeValue = 1;placeValue <=9;placeValue++){
					if(IsSafeForSudoku(userInput,noOfRows,noOfColumns,rowCounter,columnCounter,placeValue)){
						userInput[rowCounter][columnCounter] = placeValue;
						if(SolveSudokuPuzzle(userInput,noOfRows,noOfColumns,rowCounter+1,columnCounter+1)){
							return true;
						}
						userInput[rowCounter][columnCounter] = SUDOKU_UNASSIGNED_BLOCK;
					}
				}
			}
		}
	}
	return false;
}

#endif /* SUDOKU_H_ */

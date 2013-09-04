/*
 * ChessKnightProblem.h
 *  http://www.careercup.com/question?id=6203717334335488
 *  Created on: Aug 19, 2013
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

#ifndef CHESSKNIGHTPROBLEM_H_
#define CHESSKNIGHTPROBLEM_H_

#define MAX_ROWS_CHESS_KNIGHT 10
#define MAX_COLUMNS_CHESS_KNIGHT 10

bool CheckBoundaryConditionsChessKnight(int rowIndex,int columnIndex,int maxRows,int maxColumns){
	if(rowIndex < 0 || columnIndex < 0){
		return false;
	}
	if(rowIndex >= maxRows || columnIndex >= columnIndex){
		return false;
	}
	return true;
}

int MinimumNumberOfStepsChessKnightProblem(int maxRows,int maxColumns,int currentRowIndex,int currentColumnIndex){
	if(!CheckBoundaryConditionsChessKnight(currentRowIndex,currentColumnIndex,maxRows,maxColumns)){
		return INT_MAX;
	}
	if(currentRowIndex == maxRows-1 && currentColumnIndex == maxColumns-1){
		return 0;
	}
	int resultSteps = INT_MAX,possibility1,possibility2,possibility3,possibility4,possibility5,possibility6,possibility7,possibility8;
	possibility1 = MinimumNumberOfStepsChessKnightProblem(maxRows,maxColumns,currentRowIndex+1,currentColumnIndex+2);
	possibility2 = MinimumNumberOfStepsChessKnightProblem(maxRows,maxColumns,currentRowIndex+2,currentColumnIndex+1);
	possibility3 = MinimumNumberOfStepsChessKnightProblem(maxRows,maxColumns,currentRowIndex+1,currentColumnIndex-2);
	possibility4 = MinimumNumberOfStepsChessKnightProblem(maxRows,maxColumns,currentRowIndex+2,currentColumnIndex-1);
	possibility5 = MinimumNumberOfStepsChessKnightProblem(maxRows,maxColumns,currentRowIndex-1,currentColumnIndex+2);
	possibility6 = MinimumNumberOfStepsChessKnightProblem(maxRows,maxColumns,currentRowIndex-2,currentColumnIndex+1);
	possibility7 = MinimumNumberOfStepsChessKnightProblem(maxRows,maxColumns,currentRowIndex-1,currentColumnIndex-2);
	possibility8 = MinimumNumberOfStepsChessKnightProblem(maxRows,maxColumns,currentRowIndex-2,currentColumnIndex-1);
	if(possibility1 != INT_MAX){
		resultSteps = min(possibility1,resultSteps);
	}
	if(possibility2 != INT_MAX){
		resultSteps = min(possibility2,resultSteps);
	}
	if(possibility3 != INT_MAX){
		resultSteps = min(possibility3,resultSteps);
	}
	if(possibility4 != INT_MAX){
		resultSteps = min(possibility4,resultSteps);
	}
	if(possibility5 != INT_MAX){
		resultSteps = min(possibility5,resultSteps);
	}
	if(possibility6 != INT_MAX){
		resultSteps = min(possibility6,resultSteps);
	}
	if(possibility7 != INT_MAX){
		resultSteps = min(possibility7,resultSteps);
	}
	if(possibility8 != INT_MAX){
		resultSteps = min(possibility8,resultSteps);
	}
	if(resultSteps == INT_MAX){
		return INT_MAX;
	}else{
		return 1 + resultSteps;
	}
}

#endif /* CHESSKNIGHTPROBLEM_H_ */

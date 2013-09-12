/*
 * RatInMaze.h
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

#ifndef RATINMAZE_H_
#define RATINMAZE_H_

#define MAX_ROWS_RATS_MAZE 10
#define MAX_COLUMNS_RATS_MAZE 10
#define RAT_RESTRICTED_POSITION -1
#define RAT_VISITED_POSITION 1

bool isStableConfiguration(int mazeUserInput[][MAX_COLUMNS_RATS_MAZE],int maxRows,int maxColumns,int ratRowPosition,int ratColumnPosition){
	if(mazeUserInput[ratRowPosition][ratColumnPosition] != RAT_RESTRICTED_POSITION || mazeUserInput[ratRowPosition][ratColumnPosition] != RAT_VISITED_POSITION){
		return false;
	}
	if(ratRowPosition >= maxRows){
		return false;
	}
	if(ratColumnPosition >= maxColumns){
		return false;
	}
	return true;
}

// This is can be still reduced
bool RatInMazePuzzle(int mazeUserInput[][MAX_COLUMNS_RATS_MAZE],int maxRows,int maxColumns,int ratRowPosition,int ratColumnPosition){
	if(mazeUserInput == NULL  || (maxRows == 0 && maxColumns == 0)){
		return true;
	}
	if(ratRowPosition == maxRows-1 && ratColumnPosition == maxColumns-1){
		return true;
	}
	if(!isStableConfiguration(mazeUserInput,maxRows,maxColumns,ratRowPosition,ratColumnPosition)){
		return false;
	}
	bool truthValue = false;
	mazeUserInput[ratRowPosition-1][ratColumnPosition] = 1;
	truthValue = RatInMazePuzzle(mazeUserInput,maxRows,maxColumns,ratRowPosition-1,ratColumnPosition);
	if(truthValue){
		return true;
	}
	mazeUserInput[ratRowPosition-1][ratColumnPosition] = 0;
	mazeUserInput[ratRowPosition][ratColumnPosition-1] = 1;
	truthValue = RatInMazePuzzle(mazeUserInput,maxRows,maxColumns,ratRowPosition,ratColumnPosition-1);
	if(truthValue){
		return true;
	}
	mazeUserInput[ratRowPosition][ratColumnPosition-1] = 0;
	mazeUserInput[ratRowPosition][ratColumnPosition+1] = 1;
	truthValue = RatInMazePuzzle(mazeUserInput,maxRows,maxColumns,ratRowPosition,ratColumnPosition+1);
	if(truthValue){
		return true;
	}
	mazeUserInput[ratRowPosition][ratColumnPosition+1] = 0;
	mazeUserInput[ratRowPosition+1][ratColumnPosition] = 1;
	truthValue = RatInMazePuzzle(mazeUserInput,maxRows,maxColumns,ratRowPosition+1,ratColumnPosition);
	if(truthValue){
		return true;
	}
	mazeUserInput[ratRowPosition+1][ratColumnPosition] = 0;
	return false;
}

#endif /* RATINMAZE_H_ */

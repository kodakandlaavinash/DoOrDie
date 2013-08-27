/*
 * FloogFillAlgo.h
 *
 *  Created on: Aug 23, 2013
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

#ifndef FLOODFILLALGO_H_
#define FLOODFILLALGO_H_

#define MAX_ROWS_FLOOD_FILL_ALGO 10
#define MAX_COLUMNS_FLOOD_FILL_ALGO 10

struct matrixIndexes{
	int rowIndex;
	int columnIndex;
};

bool CheckFloodFillAlgoConstraint(matrixIndexes *constraintToBeChecked){
	if((constraintToBeChecked->rowIndex < MAX_ROWS_FLOOD_FILL_ALGO && constraintToBeChecked->rowIndex >= 0)&&(constraintToBeChecked->columnIndex >= 0 && constraintToBeChecked->columnIndex < MAX_COLUMNS_FLOOD_FILL_ALGO)){
		return true;
	}
	return false;
}

void FloodFillAlgo(bool userInput[][],int noOfRows,int noOfColumns,int targetRowIndex,int targetColumnIndex){
	if(userInput == NULL || (noOfRows == 0 && noOfColumns ==0)){
		return;
	}
	queue<matrixIndexes *> auxSpace;
	matrixIndexes *temp = (matrixIndexes *)malloc(sizeof(matrixIndexes));
	temp->rowIndex = targetRowIndex;
	temp->columnIndex = targetColumnIndex;
	auxSpace.push(temp);
	matrixIndexes *currentIndexValues,*north,*east,*south,*west;
	while(!auxSpace.empty()){
		currentIndexValues = auxSpace.front();
		userInput[currentIndexValues->rowIndex][currentIndexValues->columnIndex] = true;
		north = (matrixIndexes *)malloc(sizeof(matrixIndexes));
		north->rowIndex = currentIndexValues->rowIndex - 1;
		north->columnIndex = currentIndexValues->columnIndex;
		if(CheckFloodFillAlgoConstraint(north)){
			auxSpace.push(north);
		}
		east = (matrixIndexes *)malloc(sizeof(matrixIndexes));
		east->rowIndex = currentIndexValues->rowIndex;
		east->columnIndex = currentIndexValues->columnIndex + 1;
		if(CheckFloodFillAlgoConstraint(east)){
			auxSpace.push(east);
		}
		south = (matrixIndexes *)malloc(sizeof(matrixIndexes));
		south->rowIndex = currentIndexValues->rowIndex + 1;
		south->columnIndex = currentIndexValues->columnIndex;
		if(CheckFloodFillAlgoConstraint(south)){
			auxSpace.push(south);
		}
		west = (matrixIndexes *)malloc(sizeof(matrixIndexes));
		west->rowIndex = currentIndexValues->rowIndex;
		west->columnIndex = currentIndexValues->columnIndex - 1;
		if(CheckFloodFillAlgoConstraint(west)){
			auxSpace.push(west);
		}
	}
}

void FloodFillAlgoRecursion(bool userInput[],int noOfRows,int noOfColumns,int rowIndex,int columnIndex){
	if((rowIndex >= noOfRows && rowIndex < 0)&&(columnIndex >= noOfColumns && columnIndex < 0)){
		return;
	}
	userInput[rowIndex][columnIndex] = true;
	FloodFillAlgoRecursion(userInput,noOfRows,noOfColumns,rowIndex-1,columnIndex);
	FloodFillAlgoRecursion(userInput,noOfRows,noOfColumns,rowIndex,columnIndex+1);
	FloodFillAlgoRecursion(userInput,noOfRows,noOfColumns,rowIndex+1,columnIndex);
	FloodFillAlgoRecursion(userInput,noOfRows,noOfColumns,rowIndex,columnIndex-1);
}

#endif /* FLOODFILLALGO_H_ */

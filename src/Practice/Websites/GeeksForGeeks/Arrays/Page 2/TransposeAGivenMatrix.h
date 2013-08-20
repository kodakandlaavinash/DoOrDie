/*
 * TransposeAGivenMatrix.h
 *
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

#ifndef TRANSPOSEAGIVENMATRIX_H_
#define TRANSPOSEAGIVENMATRIX_H_

#define MAX_ROWS_TRANSPOSE_MATRIX 10
#define MAX_COLUMN_TRANSPOSE_MATRIX 10

int *TransposeOfGivenMatrixAuxSpace(int userInput[MAX_ROWS_TRANSPOSE_MATRIX][],int noOfRows,int noOfColumns){
	if(userInput == NULL){
		return;
	}
	int *newUserInput;
	newUserInput = (int *)calloc(noOfRows,sizeof(int));
	for(int counter =0;counter < noOfRows;counter++){
		newUserInput[counter] = (int *)calloc(noOfColumns,sizeof(int));
	}

	int rowCrawler,columnCrawler;
	for(rowCrawler =0;rowCrawler < noOfRows;rowCrawler++){
		for(columnCrawler = 0;columnCrawler < noOfColumns;columnCrawler++){
			newUserInput[columnCrawler][rowCrawler] = userInput[rowCrawler][columnCrawler];
		}
	}
	return newUserInput;
}

void TransposeOfGivenMatrix(int userInput[MAX_ROWS_TRANSPOSE_MATRIX][],int noOfRows,int noOfColumns){
	if(userInput == NULL){
		return;
	}

}

#endif /* TRANSPOSEAGIVENMATRIX_H_ */

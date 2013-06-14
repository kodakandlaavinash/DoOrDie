/*
 * MaximumSizeSquareSubMatrixWithAll1s.h
 *
 *  Created on: May 15, 2013
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

#ifndef MAXIMUMSIZESQUARESUBMATRIXWITHALL1S_H_
#define MAXIMUMSIZESQUARESUBMATRIXWITHALL1S_H_

int min(int a, int b,int c){
	return a < b ?(a<c?a:(b<c?b:c)):(a<c?a:(c<b)?c:b);
}

bool MaximumSizeSquareSubMatrixWithAll1sAuxSpace(int userInput[5][],int rows,int columns){
	int sumMatrix[rows][columns];
	int rowCrawler = 0,columnCrawler = 0;

	for(columnCrawler = 0;columnCrawler < columns;columnCrawler++){
		sumMatrix[0][columnCrawler] = userInput[0][columnCrawler];
	}

	for(rowCrawler=0;rowCrawler < rows;rowCrawler++){
		sumMatrix[rowCrawler][0] = userInput[columnCrawler][0];
	}

	for(rowCrawler=1;rowCrawler < rows;rowCrawler++){
		for(columnCrawler=1;columnCrawler < columns;columnCrawler++){
			if(userInput[rowCrawler][columnCrawler] == 1){
				sumMatrix[rowCrawler][columnCrawler] = min(sumMatrix[rowCrawler-1][columnCrawler],sumMatrix[rowCrawler][columnCrawler-1],sumMatrix[rowCrawler-1][columnCrawler-1]);
			}else{
				sumMatrix[rowCrawler][columnCrawler] = 0;
			}
		}
	}

	int maxSum = INT_MIN;
	int maxRowIndex,maxColumnIndex;
	int columnCrawler;
	for(int rowCrawler=0;rowCrawler < rows;rowCrawler++){
		for(columnCrawler=0;columnCrawler < columns;columnCrawler++){
			if(maxSum > sumMatrix[rowCrawler][columnCrawler]){
				maxSum = sumMatrix[rowCrawler][columnCrawler];
				maxRowIndex = rowCrawler;
				maxColumnIndex = columnCrawler;
			}
		}
	}

	return maxSum;
}


#endif /* MAXIMUMSIZESQUARESUBMATRIXWITHALL1S_H_ */

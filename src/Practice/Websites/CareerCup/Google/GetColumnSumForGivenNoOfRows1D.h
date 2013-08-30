/*
 * GetColumnSumForGivenNoOfRows1D.h
 *
 *  Created on: Aug 29, 2013
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

#ifndef GETCOLUMNSUMFORGIVENNOOFROWS1D_H_
#define GETCOLUMNSUMFORGIVENNOOFROWS1D_H_

int GetMaxColumnSumForGivenNoOfRows1DNaiveMethod(int userInput[],int sizeOfArray,int noOfRows){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	int resultMatrix[noOfRows][sizeOfArray/noOfRows];
	int outerCounter,innerCounter;
	int counter = -1;
	for(outerCounter = 0;outerCounter < noOfRows;outerCounter++){
		for(innerCounter = 0;innerCounter < sizeOfArray/noOfRows;innerCounter++){
			resultMatrix[outerCounter][innerCounter] = userInput[++counter];
		}
	}
	int columnSum[sizeOfArray/noOfRows];
	for(int columnCounter = 0;columnCounter < sizeOfArray/noOfRows;columnCounter++){
		for(int rowCounter = 0;rowCounter < noOfRows;rowCounter++){
			columnSum[rowCounter][columnCounter] += resultMatrix[rowCounter][columnCounter];
		}
	}
	int maxSum = INT_MIN;
	for(int counter = 0;counter < sizeOfArray/noOfRows;counter++){
		if(maxSum > columnSum[counter]){
			maxSum = columnSum[counter];
		}
	}
	return maxSum;
}

int GetMaxColumnSumForGivenNoOfRows1D(int userInput[],int sizeOfArray,int numberOfRows){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	hash_map<int,int> columnSum;
	hash_map<int,int>::iterator itToColumnSum;
	for(int counter = 0;counter < sizeOfArray;counter++){
		if((itToColumnSum = columnSum.find(counter%numberOfRows)) != columnSum.end()){
			columnSum[itToColumnSum->first] = itToColumnSum->second + userInput[counter];
		}else{
			columnSum[userInput[counter]] = userInput[counter];
		}
	}
	int maxColumnSum = INT_MIN;
	for(itToColumnSum = columnSum.begin();itToColumnSum != columnSum.end();itToColumnSum++){
		if(maxColumnSum > itToColumnSum->second){
			maxColumnSum = itToColumnSum->second;
		}
	}
	return maxColumnSum;
}

#endif /* GETCOLUMNSUMFORGIVENNOOFROWS1D_H_ */

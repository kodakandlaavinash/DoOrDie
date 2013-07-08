/*
 * FindTheEquilibriumIndexOfAnArray.h
 *
 *  Created on: Jun 20, 2013
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

#ifndef FINDTHEEQUILIBRIUMINDEXOFANARRAY_H_
#define FINDTHEEQUILIBRIUMINDEXOFANARRAY_H_

int FindTheEquilibriumIndexOfArray(int userInput[],int sizeOfArray){
	if(userInput == null || sizeOfArray == 0){
		return INT_MIN;
	}
	int leftSum,rightSum;
	int outerCounter,innerCounter;
	for(outerCounter =0;outerCounter < sizeOfArray;outerCounter++){
		leftSum = 0;
		for(innerCounter =0;innerCounter < outerCounter ;innerCounter++){
			leftSum += userInput[innerCounter];
		}
		rightSum = 0;
		for(innerCounter = outerCounter+1;innerCounter < sizeOfArray;innerCounter++){
			rightSum += userInput[innerCounter];
		}
		if(rightSum == leftSum){
			return outerCounter;
		}
	}
}

int FindEquilibriumIndexOfAnArrayWithAuxSpace(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}

	int *leftSum = (int *)calloc(sizeOfArray,sizeof(int));
	int *rightSum = (int *)calloc(sizeOfArray,sizeof(int));
	leftSum[0] = 0;
	rightSum[sizeOfArray - 1] = 0;
	for(int counter =1;counter < sizeOfArray;counter++){
		leftSum[counter] += leftSum[counter-1] + userInput[counter-1];
	}
	previousSum = 0;
	for(int counter = sizeOfArray-2;counter >= 0;counter--){
		rightSum[counter] += rightSum[counter+1] + userInput[counter+1];
	}

	for(int counter =0;counter < sizeOfArray;counter++){
		if(leftSum[counter] == rightSum[counter]){
			return counter;
		}
	}
}

int FindEquilibriumIndexOfArrayWithLimitedAuxSpace(int userInput[],int sizeOfArray){
	if(userInput != null && sizeOfArray == 0){
		return INT_MIN;
	}

	int *leftSum = (int *)calloc(sizeOfArray,sizeof(int));
	leftSum[0] = 0;
	for(int counter =1;counter < sizeOfArray;counter++){
		leftSum[counter] = leftSum[counter-1] + userInput[counter-1];
	}

	int rightSum = 0;
	for(int counter = sizeOfArray-1;counter >=0;counter--){
		if(rightSum == leftSum[counter]){
			return counter;
		}
		rightSum += userInput[counter];
	}

	return INT_MIN;
}

#endif /* FINDTHEEQUILIBRIUMINDEXOFANARRAY_H_ */

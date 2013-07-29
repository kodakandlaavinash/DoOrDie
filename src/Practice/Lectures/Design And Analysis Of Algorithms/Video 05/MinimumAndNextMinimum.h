/*
 * MinimumAndNextMinimum.h
 *
 *  Created on: Jul 12, 2013
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

#ifndef MINIMUMANDNEXTMINIMUM_H_
#define MINIMUMANDNEXTMINIMUM_H_

int *FindFirstTwoMinimumsOfNumbers(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0|| userInput == NULL){
		return NULL;
	}

	int firstMinimum = INT_MIN;
	int secondMinimum = INT_MIN;

	for(int counter =0;counter < sizeOfArray;counter++){
		if(userInput[counter] < firstMinimum){
			secondMinimum = firstMinimum;
			firstMinimum = userInput[counter];
		}else{
			if(userInput[counter] < secondMinimum){
				secondMinimum = userInput[counter];
			}
		}
	}
	int result[2];
	result[0] = firstMinimum;
	result[1] = secondMinimum;
	return result;
}

int *FindFirstTwoNumbers(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0 || userInput == NULL){
		return NULL;
	}
	int result[2]={INT_MAX};
	for(int counter =0;counter < sizeOfArray;counter++){
		if(result[0] > userInput[counter]){
			result[0] = userInput[counter];
		}
	}
	for(int counter = 0;counter < sizeOfArray;counter++){
		if(userInput[counter] == result[0]){
			continue;
		}
		if(result[1] > userInput[counter]){
			result[1] = userInput[counter];
		}
	}
	return result;
}

int *FindFirstTwoNumbersDivideAndConquer(int userInput[],int startIndex,int endIndex){
	int result[2];
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	if(endIndex - startIndex == 0){
		result[0] = userInput[startIndex];
		result[1] = userInput[startIndex];
		return result;
	}
	if(endIndex - startIndex == 1){
		result[0] = min(userInput[startIndex],userInput[endIndex]);
		result[1] = result[0] == userInput[startIndex]?userInput[endIndex]:userInput[startIndex];
		return result;
	}
	int middleIndex = (startIndex+endIndex)/2;
	int resultLeft[2] = FindFirstTwoNumbersDivideAndConquer(userInput,startIndex,middleIndex);
	int resultRight[2] = FindFirstTwoNumbersDivideAndConquer(userInput,middleIndex+1,endIndex);

	result[0] = min(resultLeft[0],resultRight[0]);
	bool didLeftWon = result[0]==resultLeft[0]?true:false;

	if(didLeftWon){
		result[1] = min(min(resultLeft[1],resultRight[0]),min(resultLeft[1],resultRight[1]));
	}else{
		result[1] = min(min(resultRight[1],resultLeft[0]),min(resultLeft[1],resultRight[1]));
	}
	return result;
}

int *MinMaxOfNumbers(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0||userInput == NULL){
		return NULL;
	}
	sort(userInput,userInput+sizeOfArray);
	if(sizeOfArray > 2){
		int result[2] = {userInput[0],userInput[1]};
	}else{
		int result[2] = {userInput[0],INT_MAX};
	}
	return result;
}
#endif /* MINIMUMANDNEXTMINIMUM_H_ */

/*
 * MaximumAndMinimumOfNumbers.h
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

#ifndef MAXIMUMANDMINIMUMOFNUMBERS_H_
#define MAXIMUMANDMINIMUMOFNUMBERS_H_

int *MinMaxOfNumbers(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0 || userInput == NULL){
		return NULL;
	}
	int minMax[2];
	minMax[0] = INT_MAX;
	minMax[1] = INT_MIN;
	for(int counter =0;counter < sizeOfArray;counter++){
		if(minMax[0] > userInput[counter]){
			minMax[0] = userInput[counter];
		}
		if(minMax[1] < userInput[counter]){
			minMax[1] = userInput[counter];
		}
	}
	return minMax;
}

int *MinMaxOfNumbers(int userInput[],int startIndex,int endIndex){
	int minMax[2];
	if(startIndex > endIndex){
		minMax[0] = INT_MAX;
		minMax[1] = INT_MIN;
		return minMax;
	}
	if(startIndex == endIndex){
		minMax[0] = userInput[startIndex];
		minMax[1] = userInput[startIndex];
		return minMax;
	}
	if(endIndex - startIndex == 1){
		minMax[0] = min(userInput[startIndex],userInput[endIndex]);
		minMax[1] = minMax[0] == userInput[startIndex]?userInput[endIndex]:userInput[startIndex];
		return minMax;
	}
	int middleIndex = (startIndex+endIndex)/2;
	int minMaxLeft[2] = MinMaxOfNumbers(userInput,startIndex,middleIndex);
	int minMaxRight[2] = MinMaxOfNumbers(userInput,middleIndex+1,endIndex);

	minMax[0] = min(minMaxLeft[0],minMaxRight[0]);
	minMax[1] = max(minMaxLeft[1],minMaxRight[1]);

	return minMax;
}

int *MinMaxOfNumbers(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0||userInput == NULL){
		return NULL;
	}
	sort(userInput,userInput+sizeOfArray);
	int result[2] = {userInput[0],userInput[sizeOfArray-1]};
	return result;
}
#endif /* MAXIMUMANDMINIMUMOFNUMBERS_H_ */

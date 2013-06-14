/*
 * MaximumMinimumOfArray.h
 *
 *  Created on: May 20, 2013
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

#ifndef MAXIMUMMINIMUMOFARRAY_H_
#define MAXIMUMMINIMUMOFARRAY_H_

void MaximumMinimumOfArrayLinearSearch(int userInput[],int sizeOfArray,int &maxArray = INT_MIN,int &minArray = INT_MAX){
	if(sizeOfArray == 0){
		maxArray = INT_MAX;
		minArray = INT_MIN;
		return;
	}

	for(int crawler=0;crawler < sizeOfArray;crawler++){
		if(maxArray < userInput[crawler]){
			maxArray = userInput[crawler];
		}
		if(minArray > userInput[crawler]){
			minArray = userInput[crawler];
		}
	}
}

struct MinMax{
	int min;
	int max;
};

MinMax MaximumMinimumOfArrayTournamentStructure(int userInput[],int startIndex,int endIndex){
	if(startIndex == endIndex){
		MinMax minMaxForSingleElement;
		minMaxForSingleElement.min = userInput[startIndex];
		minMaxForSingleElement.max = userInput[startIndex];
		return minMaxForSingleElement;
	}
	if(startIndex+1 == endIndex){
		MinMax minMaxForTwoElements;
		if(userInput[startIndex] > userInput[startIndex+1]){
			minMaxForTwoElements.max = userInput[startIndex];
			minMaxForTwoElements.min = userInput[startIndex+1];
		}else{
			minMaxForTwoElements.max = userInput[startIndex+1];
			minMaxForTwoElements.min = userInput[startIndex];
		}
	}

	int middle = (startIndex+endIndex)/2;
	MinMax leftMinMax = MaximumMinimumOfArrayTournamentStructure(userInput,startIndex,middle);
	MinMax rightMinMax = MaximumMinimumOfArrayTournamentStructure(userInput,middle+1,endIndex);

	MinMax minMaxForArray;
	if(leftMinMax.min < rightMinMax.min){
		minMaxForArray.min = leftMinMax.min;
	}else{
		minMaxForArray.min = rightMinMax.min;
	}

	if(leftMinMax.max < rightMinMax.max){
		minMaxForArray.max = rightMinMax.max;
	}else{
		minMaxForArray.min = leftMinMax.max;
	}

	return minMaxForArray;
}

MinMax MaximumAndMinimumOfArrayComparisonInPairs(int userInput[],int sizeOfArray){

}

#endif /* MAXIMUMMINIMUMOFARRAY_H_ */

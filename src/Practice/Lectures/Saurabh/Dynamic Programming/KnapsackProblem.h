/*
 * KnapsackProblem.h
 *
 *  Created on: Jul 29, 2013
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

#ifndef KNAPSACKPROBLEM_H_
#define KNAPSACKPROBLEM_H_

int ZeroOneKnapsackProblem(int weights[],int benefits[],int sizeOfArray,int currentIndex,int knapsackSize){
	if(knapsackSize == 0){
		return 0;
	}
	if(currentIndex >= sizeOfArray){
		return 0;
	}
	if(weights[currentIndex] > knapsackSize){
		return ZeroOneKnapsackProblem(weights,benefits,sizeOfArray,currentIndex,knapsackSize);
	}else{
		return max(ZeroOneKnapsackProblem(weights,benefits,sizeOfArray,currentIndex+1,knapsackSize),benefits[currentIndex]+ZeroOneKnapsackProblem(weights,benefits,sizeOfArray,currentIndex+1,knapsackSize-weights[currentIndex]));
	}
}

int ZeroOneKnapsackProblemMemoization(int weights[],int benefits[],int sizeOfArray,int knapsackMaxWeight){
	if(knapsackMaxWeight == 0 || sizeOfArray == 0||weights == NULL || benefits == NULL){
		return 0;
	}
	int knapsackMatrix[sizeOfArray][knapsackMaxWeight];
	for(int resetCounter = 0;resetCounter < sizeOfArray;resetCounter++){
		knapsackMatrix[resetCounter][0] = 0;
		knapsackMatrix[0][resetCounter] = 0;
	}

	int innerCounter,outerCounter;
	for(outerCounter=1;outerCounter < sizeOfArray;outerCounter++){
		for(innerCounter=1;innerCounter<knapsackMaxWeight;innerCounter++){
			if(weights[outerCounter] > knapsackMatrix){
				continue;
			}
			knapsackMatrix[outerCounter][innerCounter]= max();
		}
	}
}

int ZeroOneKnapsackProblemO2N(int weights[],int benefits[],int sizeOfArray,int knapsackMaxWeight){
	if(knapsackMaxWeight == 0||  sizeOfArray == 0 || weights == NULL || benefits == NULL){
		return 0;
	}
	int maxBenefit = INT_MIN;
	int currentSetWeight,currentSetBenefit;
	for(int counter = 0;counter < pow(2,sizeOfArray);counter++){
		bitset<sizeOfArray> bitRepOfDecimal;
		currentSetBenefit = 0;currentSetWeight = 0;
		for(int bitCounter = 0;bitCounter < sizeOfArray;bitCounter++){
			if(bitRepOfDecimal[bitCounter]){
				currentSetWeight += weights[bitCounter];
				currentSetBenefit += benefits[bitCounter];
			}
		}
		if(currentSetWeight < knapsackMaxWeight){
			if(maxBenefit < currentSetBenefit){
				maxBenefit = currentSetBenefit;
			}
		}
	}
	return maxBenefit;
}

void ZeroOneKnapsackProblemO2NRecursion(int weights[],int benefits[],int sizeOfArray,int knapsackMaxWeight,int currentIndex,int currentWeight,int currentBenefit,int maxBenefit = INT_MIN){
	if(currentIndex >= sizeOfArray){
		return;
	}
	if(currentIndex == sizeOfArray-1){
		if(currentWeight+weights[currentIndex] <= knapsackMaxWeight){
			if(currentBenefit+benefits[currentIndex] > maxBenefit){
				maxBenefit = currentBenefit + benefits[currentIndex];
			}
		}
		return;
	}
	ZeroOneKnapsackProblemO2NRecursion(weights,benefits,sizeOfArray,knapsackMaxWeight,currentIndex+1,weights[currentIndex]+currentWeight,benefits[currentIndex]+currentBenefit,maxBenefit);
	ZeroOneKnapsackProblemO2NRecursion(weights,benefits,sizeOfArray,knapsackMaxWeight,currentIndex+1,currentWeight,currentBenefit,maxBenefit);
}

int KnapsackProblemBranchAndBoundProblem(int weights[],int benefits[],int sizeOfArray,int knapsackMaxWeight){
	if(knapsackMaxWeight == 0||  sizeOfArray == 0 || weights == NULL || benefits == NULL){
		return 0;
	}
	int maxBenefit = INT_MIN;
	int currentSetWeight,currentSetBenefit;
	bool isCompleted;
	for(int counter = 0;counter < pow(2,sizeOfArray);counter++){
		bitset<sizeOfArray> bitRepOfDecimal;
		currentSetBenefit = 0;currentSetWeight = 0;
		isCompleted = true;
		for(int bitCounter = 0;bitCounter < sizeOfArray;bitCounter++){
			if(currentSetWeight+weights[bitCounter] <= maxBenefit){
				currentSetWeight += weights[bitCounter];
				currentSetBenefit += benefits[bitCounter];
			}else{
				isCompleted = false;
			}
		}
		if(isCompleted){
			if(maxBenefit < currentSetBenefit){
				maxBenefit = currentSetBenefit;
			}
		}
	}
	return maxBenefit;
}

int KnapsackProblemBranchAndBoundProblemRecursion(int weights[],int benefits[],int sizeOfArray,int knapsackMaxWeight,int currentWeight,int currentBenefit,int &maxBenefit,int currentIndex){
	if(currentIndex >= sizeOfArray){
		return;
	}
	if(currentIndex == sizeOfArray-1){
		if(currentWeight+weights[currentIndex] <= knapsackMaxWeight){
			if(currentBenefit+benefits[currentIndex] > maxBenefit){
				maxBenefit = currentBenefit + benefits[currentIndex];
			}
		}
		return;
	}
	if(currentWeight > knapsackMaxWeight){
		return;
	}
	KnapsackProblemBranchAndBoundProblemRecursion(weights,benefits,sizeOfArray,knapsackMaxWeight,weights[currentIndex]+currentWeight,benefits[currentIndex]+currentBenefit,maxBenefit,currentIndex+1);
	KnapsackProblemBranchAndBoundProblemRecursion(weights,benefits,sizeOfArray,knapsackMaxWeight,currentWeight,currentBenefit,maxBenefit,currentIndex+1);
}


#endif /* KNAPSACKPROBLEM_H_ */

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

#endif /* KNAPSACKPROBLEM_H_ */

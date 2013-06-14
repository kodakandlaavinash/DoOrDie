/*
 * CheckWhetherPairExistsForInputSum.h
 *
 *  Created on: Apr 24, 2013
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

#ifndef CHECKWHETHERPAIREXISTSFORINPUTSUM_H_
#define CHECKWHETHERPAIREXISTSFORINPUTSUM_H_

/**
 * Tested
 */
void GetPairOfElementsWhichEqualsToGivenSum(int inputArray[],int sizeOfArray,int targetSum){
	set<int> visitedValues;
	set<int>::iterator itToVisitedValues;

	for(int counter=0;counter < sizeOfArray; counter++){
		if((itToVisitedValues = visitedValues.find(targetSum - inputArray[counter])) != visitedValues.end()){
			printf("(%d,%d)",inputArray[counter],targetSum - inputArray[counter]);
		}else{
			visitedValues.insert(inputArray[counter]);
		}
	}
}

/**
 * Tested
 */
// Prints both ordered pairs
void GetPairOfElementsEqualsToGivenSumON2(int inputArray[],int sizeOfArray,int targetSum){
	int outerCrawler = 0,innerCrawler;
	for(outerCrawler=0;outerCrawler < sizeOfArray;outerCrawler++){
		for(innerCrawler =0;innerCrawler < sizeOfArray;innerCrawler++){
			if(innerCrawler == outerCrawler){
				continue;
			}
			if(inputArray[outerCrawler]+inputArray[innerCrawler] == targetSum){
				printf("(%d,%d)",inputArray[outerCrawler],inputArray[innerCrawler]);
			}
		}
	}
}

/**
 * Tested
 */
void GetPairOfElementsEqualsToGivenSumSorting(int inputArray[],int sizeOfArray,int targetSum){
	sort(inputArray,inputArray+sizeOfArray);
	int forwardCrawler = 0;
	int backwardCrawler = sizeOfArray - 1;
	int sumOfElements = 0;
	while(forwardCrawler < backwardCrawler){
		sumOfElements = inputArray[forwardCrawler] + inputArray[backwardCrawler];
		if(sumOfElements == targetSum){
			printf("(%d,%d)",inputArray[forwardCrawler],inputArray[backwardCrawler]);
			return;
		}
		if(sumOfElements > targetSum){
			backwardCrawler--;
		}
		if(sumOfElements < targetSum){
			forwardCrawler++;
		}
	}
}

#endif /* CHECKWHETHERPAIREXISTSFORINPUTSUM_H_ */

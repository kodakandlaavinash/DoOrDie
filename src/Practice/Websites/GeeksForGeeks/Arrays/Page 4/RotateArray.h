/*
 * RotateArray.h
 *
 *  Created on: Apr 25, 2013
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

#ifndef ROTATEARRAY_H_
#define ROTATEARRAY_H_

/**
 * Tested
 */
void RotateArrayAuxSpace(int userInput[],int sizeOfArray,int rotateBy){
	int auxSpace[sizeOfArray];
	int counter=-1;
	int crawler;
	for(crawler = rotateBy;crawler+1 != rotateBy;crawler++,crawler = crawler%sizeOfArray){
		auxSpace[++counter] = userInput[crawler];
	}
	auxSpace[++counter] = userInput[crawler];
	for(crawler =0;crawler < sizeOfArray;crawler++){
		userInput[crawler] = auxSpace[crawler];
	}

}

/**
 * Tested
 */
void RotateArrayLeftShifting(int userInput[],int sizeOfArray){
	int firstElement = userInput[0];
	int crawler;
	for(crawler = 0;crawler < sizeOfArray-1;crawler++){
		userInput[crawler] = userInput[crawler+1];
	}
	userInput[crawler] = firstElement;
}

/**
 * Tested
 */
void RotateArrayShiftDriver(int userInput[],int sizeOfArray,int rotateBy){
	for(int leftShiftCrawler = 0;leftShiftCrawler < rotateBy;leftShiftCrawler++){
		RotateArrayLeftShifting(userInput,sizeOfArray);
	}
}

void RotateArrayReversalStrategy(int userInput[],int sizeOfArray,int rotateBy){
	if(userInput == NULL || sizeOfArray == 0){
		return;
	}
	ReverseArrayRecursive2(userInput,0,rotateBy-1);
	ReverseArrayRecursive2(userInput,rotateBy,sizeOfArray-1);
	ReverseArrayRecursive2(userInput,0,sizeOfArray-1);
}

void RotateArrayJugglingStrategy(int userInput[],int sizeOfArray,int rotateBy){
	if(userInput == NULL){
		return;
	}
	//int gcdOfNumbers = FindHCFOfTwoNumbers(sizeOfArray,rotateBy);

}

void RotateArrayBlockStrategyRecursive(int userInput[],int startIndex,int endIndex,int rotateBy){

}

void RotateArrayBlockStrategyDriver(int userInput[],int sizeOfArray,int rotateBy){

}

void RotateArrayBlockStrategyIterative(){

}
#endif /* ROTATEARRAY_H_ */

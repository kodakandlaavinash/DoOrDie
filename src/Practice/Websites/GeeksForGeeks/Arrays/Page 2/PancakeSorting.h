/*
 * PancakeSorting.h
 *
 *  Created on: Aug 19, 2013
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

#ifndef PANCAKESORTING_H_
#define PANCAKESORTING_H_


void ReverseAnArray(int userInput[],int startArray,int endArray){
	int tempForSwap;
	while(startArray < endArray){
		tempForSwap = userInput[startArray];
		userInput[startArray] = userInput[endArray];
		userInput[endArray] = tempForSwap;
 	}
}

/*
 * If any number is allowed as start of array
 */
void PanCakeSorting(int userInput[],int sizeOfArray){
	if(userInput== NULL || sizeOfArray == 0){
		return;
	}
	int minElement,minElementIndex;
	int innerCounter,outerCounter;
	for(outerCounter = 0;outerCounter < sizeOfArray-1;outerCounter++){
		minElement = INT_MAX;
		minElementIndex = outerCounter;
		for(innerCounter = outerCounter;innerCounter < sizeOfArray;innerCounter++){
			if(userInput[innerCounter] < minElement){
				minElement = userInput[innerCounter];
				minElementIndex = innerCounter;
			}
		}
		ReverseAnArray(userInput,outerCounter,minElementIndex);
		ReverseAnArray(userInput,outerCounter+1,minElementIndex);
	}
}

void PanCakeSortingMaxElement(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return;
	}
	int outerCounter,innerCounter;
	int maxElement,maxElementIndex;
	for(outerCounter = sizeOfArray-1;outerCounter > 0;outerCounter--){
		maxElement = INT_MIN;
		maxElementIndex = outerCounter;
		for(innerCounter = 0;innerCounter <= outerCounter;innerCounter++){
			if(maxElement < userInput[innerCounter]){
				maxElement = userInput[innerCounter];
				maxElementIndex = innerCounter;
			}
		}
		ReverseAnArray(userInput,0,maxElementIndex);
		ReverseAnArray(userInput,0,outerCounter);
	}
}

void PanCakeSortingNLOGN(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return;
	}
}


#endif /* PANCAKESORTING_H_ */

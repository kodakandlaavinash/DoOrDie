/*
 * RearrangeAnArrayUsingSwapZero.h
 *
 *  Created on: Aug 20, 2013
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

#ifndef REARRANGEANARRAYUSINGSWAPZERO_H_
#define REARRANGEANARRAYUSINGSWAPZERO_H_

void RearrangeAnArrayUsingSwapZeroON2(int userInputSource[],int userInputTarget[],int sizeOfArray){
	if(userInputSource == NULL && userInputTarget == NULL){
		return;
	}
	if(userInputSource == NULL || userInputTarget == NULL){
		return;
	}
	int zeroIndex=0,targetElementIndex,tempForSwap;
	int outerCounter,innerCounter;
	for(outerCounter = 0;outerCounter < sizeOfArray;outerCounter++){
		if(userInputTarget[outerCounter] == 0){
			continue;
		}
		if(userInputSource[outerCounter] == userInputTarget[outerCounter]){
			continue;
		}
		if(userInputSource[zeroIndex] != 0){
			for(innerCounter = 0;innerCounter < sizeOfArray;innerCounter++){
				if(userInputSource[innerCounter] == 0){
					zeroIndex = innerCounter;
				}
				if(userInputSource[innerCounter] == userInputTarget[innerCounter]){
					targetElementIndex = innerCounter;
				}
			}
		}

		tempForSwap = userInputSource[zeroIndex];
		userInputSource[zeroIndex] = userInputSource[outerCounter];
		userInputSource[outerCounter] = tempForSwap;

		tempForSwap = userInputSource[targetElementIndex];
		userInputSource[targetElementIndex] = userInputSource[zeroIndex];
		userInputSource[zeroIndex] = tempForSwap;
		zeroIndex = targetElementIndex;
	}
}

void RearrangeAnArrayUsingZeroHashMapON(int userInputSource[],int userInputTarget[],int sizeOfArray){
	if(userInputSource == NULL && userInputTarget == NULL){
		return;
	}
	if(userInputSource == NULL || userInputTarget == NULL){
		return;
	}
	hash_map<int,int> elementMapOfSource;
	for(int counter =0;counter < sizeOfArray;counter++){
		elementMapOfSource.insert(pair<int,int>(userInputSource[counter],counter));
	}
	int targetElement,tempForSwap,indexOfTargetElement,zeroIndex;
	zeroIndex = elementMapOfSource.find(0)->second;
	for(int counter =0;counter < sizeOfArray;counter++){
		targetElement = userInputTarget[counter];
		indexOfTargetElement = elementMapOfSource.find(targetElement)->second;
		tempForSwap = userInputSource[zeroIndex];
		userInputSource[zeroIndex] = userInputSource[indexOfTargetElement];
		userInputSource[indexOfTargetElement]  = tempForSwap;
		zeroIndex = indexOfTargetElement;
		elementMapOfSource[0] = zeroIndex;
	}
}

int BinarySearchForZeroSwap(int userInput[],int startArray,int endArray,int key){
	if(startArray > endArray){
		return INT_MIN;
	}
	int middleIndex = (startArray + endArray)/2;
	if(userInput[middleIndex]==key){
		return middleIndex;
	}
	if(userInput[middleIndex] == 0){
		if(middleIndex-1 > startArray){
			if(userInput[middleIndex-1] > key){
				return BinarySearchForZeroSwap(userInput,startArray,middleIndex-1,key);
			}else{
				return BinarySearchForZeroSwap(user,middleIndex+1,endArray,key);
			}
		}else{
			return BinarySearchForZeroSwap(userInput,middleIndex+1,endArray,key);
		}
	}
	if(userInput[middleIndex] > key){
		return BinarySearchForZeroSwap(userInput,startArray,middleIndex-1,key);
	}else{
		return BinarySearchForZeroSwap(userInput,middleIndex+1,endArray,key);
	}
}

void RearrangeAnArrayUsingSwapZeroSortingONLOGN(int userInputSource[],int userInputTarget[],int sizeOfArray){
	if(userInputSource == NULL && userInputTarget == NULL){
		return;
	}
	if(userInputSource == NULL || userInputTarget == NULL){
		return;
	}
	sort(userInputSource,userInputSource+sizeOfArray);

	int zeroIndex = 0;
	int targetElement,targetElementIndex,tempForSwap;
	for(int counter = 0;counter < sizeOfArray;counter++){
		targetElement = userInputTarget[counter];
		targetElementIndex = BinarySearchForZeroSwap(userInputSource,counter,sizeOfArray-1,targetElement);
		tempForSwap = userInputSource[zeroIndex];
		userInputSource[zeroIndex] = userInputSource[targetElementIndex];
		userInputSource[targetElementIndex] = tempForSwap;
		zeroIndex = targetElementIndex;
	}
}

void RearrangeAnArrayUsingSwapZeroShortestPath(int userInputSource[],int userInputTarget[],int sizeOfArray){

}

void RearrangeAnArrayUsingSwapZeroDPMinimumSwaps(int userInputSource[],int userInputTarget[],int sizeOfArray){

}

#endif /* REARRANGEANARRAYUSINGSWAPZERO_H_ */

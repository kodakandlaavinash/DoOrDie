/*
 * NoOfTriangles.h
 *
 *  Created on: Aug 21, 2013
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

#ifndef NOOFTRIANGLES_H_
#define NOOFTRIANGLES_H_

int NoOfTrianglesON3(int userInput[],int sizeOfArray){
	if(userInput== NULL || sizeOfArray == 0){
		return 0;
	}
	int outerCounter,middleCounter,innerCounter,totalTriangles = 0;
	bool truthValue;
	for(outerCounter = 0;outerCounter < sizeOfArray;outerCounter++){
		for(middleCounter = outerCounter+1;middleCounter < sizeOfArray;middleCounter++){
			for(innerCounter = middleCounter+1;innerCounter < sizeOfArray;innerCounter++){
				truthValue = (userInput[outerCounter]+userInput[middleCounter] > userInput[innerCounter]);
				truthValue &= (userInput[middleCounter]+userInput[innerCounter] > userInput[outerCounter]);
				truthValue &= (userInput[outerCounter]+userInput[innerCounter] > userInput[middleCounter]);
				if(truthValue){
					totalTriangles += 0;
				}
			}
		}
	}
	return totalTriangles;
}

int NoOfTrianglesON2(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return 0;
	}
	sort(userInput,userInput+sizeOfArray);
	int outerCounter,middleCounter,innerCounter,totalNoOfTriangles=0;
	for(innerCounter = 0;innerCounter < sizeOfArray-2;innerCounter++){
		for(middleCounter = innerCounter+1;middleCounter < sizeOfArray-1;middleCounter++){
			outerCounter = middleCounter+1;
			while(userInput[innerCounter] + userInput[middleCounter] < userInput[outerCounter]){
				outerCounter++;
			}
			totalNoOfTriangles += outerCounter - middleCounter;
		}
	}
	return totalNoOfTriangles;
}


int BinarySearchEnhancedNoOfTriangles(int userInput[],int startArray,int endArray,int sumOfOtherTwoSides){
	if(startArray > endArray){
		return INT_MIN;
	}
	int middleIndex = (startArray+endArray)/2;
	if(userInput[middleIndex] <= sumOfOtherTwoSides){
		if(middleIndex+1 < endArray){
			if(userInput[middleIndex+1] <= sumOfOtherTwoSides){
				return BinarySearchEnhancedNoOfTriangles(userInput,middleIndex+1,endArray,sumOfOtherTwoSides);
			}
		}
		return middleIndex;
	}else{
		return BinarySearchEnhancedNoOfTriangles(userInput,startArray,middleIndex-1,sumOfOtherTwoSides);
	}
}

int NoOfTrainglesON2BinarySearch(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return 0;
	}
	sort(userInput,userInput+sizeOfArray);
	int outerCounter,middleCounter,innerCounter = INT_MIN,totalNoOfTriangles = 0;
	for(outerCounter = 0;outerCounter < sizeOfArray-2;outerCounter++){
		for(middleCounter = outerCounter+1;middleCounter < sizeOfArray-1;middleCounter++){
			if(innerCounter == INT_MIN){
				innerCounter = middleCounter+1;
			}else{
				innerCounter++;
			}
			totalNoOfTriangles += abs(middleCounter - BinarySearchEnhancedNoOfTriangles(userInput,innerCounter,sizeOfArray-1,userInput[outerCounter]+userInput[middleCounter]));
		}
	}
	return totalNoOfTriangles;
}

#endif /* NOOFTRIANGLES_H_ */

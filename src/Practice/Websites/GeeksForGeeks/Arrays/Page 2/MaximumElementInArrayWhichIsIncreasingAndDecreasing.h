/*
 * MaximumElementInArrayWhichIsIncreasingAndDecreasing.h
 *
 *  Created on: May 23, 2013
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

#ifndef MAXIMUMELEMENTINARRAYWHICHISINCREASINGANDDECREASING_H_
#define MAXIMUMELEMENTINARRAYWHICHISINCREASINGANDDECREASING_H_

int FindMaximumElementInArraysIncreasingDecreasing(int userInput[],int sizeOfUserInput){
	if(sizeOfUserInput == 0){
		return INT_MAX;
	}

	int maxElement = INT_MIN;
	for(int crawler=0;crawler < sizeOfUserInput;crawler++){
		if(maxElement < userInput[crawler]){
			maxElement = userInput[crawler];
		}
	}

	return maxElement;
}

int FindMaximumElementInArrayIncreasingDecreasingBinarySearch(int userInput[],int sizeOfArray,int startIndex,int endIndex){
	if(startIndex < endIndex){
		return INT_MAX;
	}

	int middleElement  = (startIndex+endIndex)/2;
	if(middleElement-1 >=0 && middleElement +1 < sizeOfArray){
		if(userInput[middleElement] > userInput[middleElement-1] && userInput[middleElement] > userInput[middleElement+1]){
			return userInput[middleElement];
		}
	}
	if(middleElement - 1 >=0 && middleElement+1 < sizeOfArray){
		if(userInput[middleElement] > userInput[middleElement-1] && userInput[middleElement] < userInput[middleElement+1]){
			return FindMaximumElementInArrayIncreasingDecreasingBinarySearch(userInput,sizeOfArray,middleElement+1,endIndex);
		}
	}
	if(middleElement - 1 >=0 && middleElement+1 < sizeOfArray){
		if(userInput[middleElement] < userInput[middleElement-1] && userInput[middleElement] > userInput[middleElement+1]){
			return FindMaximumElementInArrayIncreasingDecreasingBinarySearch(userInput,sizeOfArray,startIndex,middleElement-1);
		}
	}
}

int FindMaximumElementInArrayIncreasingDecreasing(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return INT_MAX;
	}

	tNode *root = NULL;
	for(int crawler =0;crawler < sizeOfArray;crawler++){
		CreateBinarySearchTree(&root,userInput[crawler]);
	}

	tNode *ptr = root;
	while(ptr->right != NULL){
		ptr = ptr->right;
	}
	return ptr->value;
}
#endif /* MAXIMUMELEMENTINARRAYWHICHISINCREASINGANDDECREASING_H_ */

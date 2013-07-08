/*
 * SearchForElementInSortedRotatedArray.h
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

#ifndef SEARCHFORELEMENTINSORTEDROTATEDARRAY_H_
#define SEARCHFORELEMENTINSORTEDROTATEDARRAY_H_

int FindPivotInSortedRotatedArray(int userInput[],int startIndex,int endIndex){
	if(startIndex > endIndex){
		return -1;
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(middleIndex + 1 < endIndex && userInput[middleIndex] > userInput[middleIndex+1]){
		return middleIndex;
	}
	if(middleIndex > startIndex && userInput[middleIndex-1] > userInput[middleIndex]){
		return middleIndex-1;
	}
	if(userInput[middleIndex] > userInput[startIndex]){
		return FindPivotInSortedRotatedArray(userInput,middleIndex+1,endIndex);
	}else{
		return FindPivotInSortedRotatedArray(userInput,startIndex,middleIndex-1);
	}

}

int BinarySearchDescendingOrder(int userInput[],int startIndex,int endIndex,int key){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		return middleIndex;
	}
	if(userInput[middleIndex] > key){
		return BinarySearchDescendingOrder(userInput,middleIndex+1,endIndex,key);
	}else{
		return BinarySearchDescendingOrder(userInput,startIndex,middleIndex-1,key);
	}
}


int BinarySearchAscendingOrder(int userInput[],int startIndex,int endIndex,int key){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		return middleIndex;
	}
	if(userInput[middleIndex] > key){
		return BinarySearchAscendingOrder(userInput,startIndex,middleIndex-1,key);
	}else{
		return BinarySearchAscendingOrder(userInput,middleIndex+1,endIndex,key);
	}
}

int SearchForElementInSortedRotatedArray(int userInput[],int startIndex,int endIndex){
	if(userInput == NULL){
		return INT_MIN;
	}
	int pivotElementIndex = FindPivotInSortedRotatedArray(userInput,startIndex,endIndex);
	if(pivotElement == -1){
		//Array is not rotated
		return BinarySearchAscendingOrder(userInput,startIndex,endIndex);
	}else{
		if(userInput[pivotElementIndex] == key){
			return pivotElementIndex;
		}
		if(userInput[pivotElementIndex] < key && userInput[startIndex] > key){
			return BinarySearchDescendingOrder(userInput,startIndex,pivotElementIndex-1,key);
		}else{
			return BinarySearchAscendingOrder(userInput,pivotElementIndex+1,endIndex,key);
		}
	}
}

#endif /* SEARCHFORELEMENTINSORTEDROTATEDARRAY_H_ */

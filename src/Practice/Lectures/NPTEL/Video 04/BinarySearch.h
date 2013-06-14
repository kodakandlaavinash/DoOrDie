/*
 * BinarySearch.h
 *
 *  Created on: May 24, 2013
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

#ifndef BINARYSEARCH_H_
#define BINARYSEARCH_H_

int BinarySearchRecursion(int userInput[],int startIndex,int endIndex,int key){
	if(startIndex > endIndex){
		return INT_MAX;
	}
	int middleIndex = (startIndex+endIndex)/2;
	if(userInput[middleIndex] == key){
		return middleIndex;
	}
	if(userInput[middleIndex] > key){
		return BinarySearchRecursion(userInput,startIndex,middleIndex-1,key);
	}else{
		return BinarySearchRecursion(userInput,middleIndex+1,endIndex,key);
	}
}

int BinarySearchIterative(int userInput[],int sizeOfArray,int key){
	if(sizeOfArray == 0){
		return INT_MAX;
	}

	int startIndex = 0;
	int endIndex = sizeOfArray-1;
	int middle;
	while(startIndex < endIndex){
		middle = (startIndex + endIndex)/2;
		if(userInput[middle] == key){
			return middle;
		}
		if(userInput[middle] > key){
			endIndex = middle-1;
		}else{
			startIndex = middle+1;
		}
	}
	return INT_MAX;
}

#endif /* BINARYSEARCH_H_ */

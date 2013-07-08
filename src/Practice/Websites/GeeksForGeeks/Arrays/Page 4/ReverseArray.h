/*
 * ReverseArray.h
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

#ifndef REVERSEARRAY_H_
#define REVERSEARRAY_H_

/**
 * Tested
 */
void ReverseArrayIterative(int userInput[],int sizeOfArray){
	int start = -1;
	int end = sizeOfArray;
	int temp;
	while(start < end){
		temp = userInput[++start];
		userInput[start]  = userInput[--end];
		userInput[end] = temp;
	}
	return;
}

/**
 * Tested
 */
void ReverseArrayRecursive(int userInput[],int sizeOfArray,int recursiveCrawler,int &forwardCrawler){
	if(recursiveCrawler == sizeOfArray){
		return;
	}
	ReverseArrayRecursive(userInput,sizeOfArray,recursiveCrawler+1,forwardCrawler);
	if(forwardCrawler < recursiveCrawler){
		int temp;
		temp = userInput[recursiveCrawler];
		userInput[recursiveCrawler] = userInput[forwardCrawler];
		userInput[forwardCrawler++] = temp;
	}
}

/**
 * Tested
 */
void ReverseArrayAuxSpace(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return;
	}
	stack<int> auxSpace;
	for(int crawler =0;crawler < sizeOfArray;crawler++){
		auxSpace.push(userInput[crawler]);
	}
	int crawler =-1;
	while(!auxSpace.empty()){
		userInput[++crawler] = auxSpace.top();
		auxSpace.pop();
	}
}

void ReverseArrayRecursive2(int userInput[],int frontCrawler,int endCrawler){
	if(frontCrawler > endCrawler){
		return;
	}
	int tempForSwap;
	tempForSwap = userInput[frontCrawler];
	userInput[frontCrawler] = userInput[endCrawler];
	userInput[endCrawler] = tempForSwap;
	ReverseArrayRecursive2(userInput,frontCrawler+1,endCrawler-1);
}
#endif /* REVERSEARRAY_H_ */

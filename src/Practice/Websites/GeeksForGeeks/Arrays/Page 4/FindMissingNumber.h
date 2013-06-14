/*
 * FindMissingNumber.h
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

#ifndef FINDMISSINGNUMBER_H_
#define FINDMISSINGNUMBER_H_

/**
 * Tested
 */
int FindMissingNumber(int userInput[],int sizeOfArray,int startNumber,int endNumber){
	int XORActualResult = 0;
	int XORArrayResult = 0;
	for(int crawler = startNumber;crawler <= endNumber;crawler++){
		XORActualResult ^= crawler;
	}

	for(int crawler = 0;crawler < sizeOfArray;crawler++){
		XORArrayResult ^= userInput[crawler];
	}
	return XORActualResult ^ XORArrayResult;
}

/**
 * Tested
 */
int FindMissingNumberSum(int userInput[],int sizeOfArray,int startNumber,int endNumber){
	int sumArray = 0;
	for(int crawler=0;crawler < sizeOfArray;crawler++){
		sumArray += userInput[crawler];
	}
	int actualSum;
	int numberOfElements = (endNumber - startNumber)+1;
	actualSum = (numberOfElements/2)*(startNumber + endNumber);
	return actualSum - sumArray;
}

/**
 * Tested
 */
int FindMissingNumberCrawling(int userInput[],int sizeOfArray,int startNumber,int endNumber){
	bool elementFound;
	int outerCrawler,innerCrawler;
	for(outerCrawler = startNumber;outerCrawler <= endNumber;outerCrawler++){
		elementFound = false;
		for(innerCrawler =0;innerCrawler < sizeOfArray;innerCrawler++){
			if(userInput[innerCrawler] == outerCrawler){
				elementFound = true;
			}
		}
		if(!elementFound){
			return outerCrawler;
		}
	}
	return INT_MIN;
}

/**
 * Tested
 */
int FindMissingNumberSet(int userInput[],int sizeOfArray,int startNumber,int endNumber){
	set<int> numbers;
	int crawler;
	for(crawler = startNumber;crawler <= endNumber;crawler++){
		numbers.insert(crawler);
	}

	for(crawler = 0;crawler < sizeOfArray;crawler++){
		numbers.erase(userInput[crawler]);
	}

	return *(numbers.begin());
}


#endif /* FINDMISSINGNUMBER_H_ */

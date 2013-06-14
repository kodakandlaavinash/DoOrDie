/*
 * LeadersInArray.h
 *
 *  Created on: Apr 30, 2013
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

#ifndef LEADERSINARRAY_H_
#define LEADERSINARRAY_H_

/**
 * Tested
 */
void PrintLeadersInArrayON2(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return;
	}
	int innerCrawler = 0;
	bool isLeader;
	for(int outerCrawler = 0;outerCrawler < sizeOfArray;outerCrawler++){
		isLeader = true;
		for(innerCrawler = outerCrawler+1;innerCrawler < sizeOfArray;innerCrawler++){
			if(userInput[innerCrawler] > userInput[outerCrawler]){
				isLeader = false;
				break;
			}
		}
		if(isLeader){
			printf("%d\t",userInput[outerCrawler]);
		}
	}
}

/**
 * Tested
 */
void PrintLeadersInArray(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return;
	}
	int arrayCrawler = sizeOfArray-1;
	int maxTillNow = INT_MIN;
	for(;arrayCrawler >= 0;arrayCrawler--){
		if(maxTillNow < userInput[arrayCrawler]){
			maxTillNow = userInput[arrayCrawler];
			printf("%d\t",userInput[arrayCrawler]);
		}
	}
}

/**
 * Tested
 */
void PrintLeadersInArrayRecursion(int userInput[],int sizeOfArray,int runner,int &maxTillNow){
	if(runner >= sizeOfArray){
		maxTillNow = INT_MIN;
		return;
	}
	PrintLeadersInArrayRecursion(userInput,sizeOfArray,runner+1,maxTillNow);
	if(userInput[runner] > maxTillNow){
		printf("%d\t",userInput[runner]);
		maxTillNow = userInput[runner];
	}

}

/**
 * Tested
 */
void PrintLeadersInArrayStackAux(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return;
	}
	stack<int> auxSpace;
	int crawler=0;
	while(crawler < sizeOfArray){
		auxSpace.push(userInput[crawler]);
		crawler++;
	}

	int maxTillNow = INT_MIN;
	while(!auxSpace.empty()){
		int currentValue = auxSpace.top();
		if(maxTillNow < currentValue){
			printf("%d\t",currentValue);
			maxTillNow = currentValue;
		}
		auxSpace.pop();
	}
}

#endif /* LEADERSINARRAY_H_ */

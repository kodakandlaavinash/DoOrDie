/*
 * FindAPairForGivenDifference.h
 *
 *  Created on: Aug 6, 2013
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

#ifndef FINDAPAIRFORGIVENDIFFERENCE_H_
#define FINDAPAIRFORGIVENDIFFERENCE_H_

int *FindAPairForGivenDifference(int userInput[],int sizeOfArray,int targetDifference){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	int innerCounter,currentDifference;
	for(int outerCounter = 0;outerCounter < sizeOfArray-1;outerCounter++){
		for(innerCounter = outerCounter+1;innerCounter < sizeOfArray;innerCounter++){
			currentDifference = abs(userInput[outerCounter] - userInput[innerCounter]);
			if(currentDifference == targetDifference){
				int result[2];
				result[0] = userInput[outerCounter];
				result[1] = userInput[innerCounter];
				return result;
			}
		}
	}
	return NULL;
}

int *FindAPairForGivenDifference(int userInput[],int sizeOfArray,int targetDifference){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	sort(userInput,userInput+sizeOfArray);
	int startCrawler = 0,endCrawler = sizeOfArray--;
	int currentDifference;
	while(startCrawler < endCrawler){
		currentDifference = userInput[endCrawler] - userInput[startCrawler];
		if(currentDifference ==  targetDifference){
			int result[2];
			result[0] = userInput[startCrawler];
			result[1] = userInput[endCrawler];
			return result;
		}
		if(currentDifference > targetDifference){
			endCrawler--;
		}else{
			startCrawler++;
		}
	}
	return NULL;
}

#endif /* FINDAPAIRFORGIVENDIFFERENCE_H_ */

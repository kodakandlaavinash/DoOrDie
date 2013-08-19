/*
 * FindSubArrayForGivenSum.h
 *
 *  Created on: Aug 12, 2013
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

#ifndef FINDSUBARRAYFORGIVENSUM_H_
#define FINDSUBARRAYFORGIVENSUM_H_

int *FindSubArrayForGivenSumON2(int userInput[],int sizeOfArray,int targetSum){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	int outerCounter,innerCounter;
	int sumOfElements;
	for(outerCounter = 0;outerCounter < sizeOfArray;outerCounter++){
		sumOfElements = userInput[outerCounter];
		for(innerCounter = outerCounter+1;innerCounter <sizeOfArray;innerCounter++){
			sumOfElements += userInput[innerCounter];
			if(sumOfElements == targetSum){
				int resultIndexes[2];
				resultIndexes[0] = outerCounter;
				resultIndexes[1] = innerCounter;
				return resultIndexes;
			}
		}
	}
	return NULL;
}

int *FindSubArrayForGivenSumON(int userInput[],int sizeOfArray,int targetSum){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	if(sizeOfArray == 1){
		if(userInput[0] == targetSum){
			int result[2];
			result[0] = 0;
			result[1] = 1;
			return result;
		}
	}
	int frontCrawler=1,rearCrawler=0,sum=userInput[rearCrawler];
	while(frontCrawler < sizeOfArray && rearCrawler < sizeOfArray){
		sum += userInput[frontCrawler];
		if(sum == targetSum){
			int result[2];
			result[0] = fr;
			result[1] = 1;
			return result;
		}
		if(sum > targetSum){
			sum -= userInput[rearCrawler];
			rearCrawler++;
		}
	}

	return NULL;
}

#endif /* FINDSUBARRAYFORGIVENSUM_H_ */

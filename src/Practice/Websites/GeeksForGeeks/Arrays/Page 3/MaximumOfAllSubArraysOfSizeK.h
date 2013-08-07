/*
 * MaximumOfAllSubArraysOfSizeK.h
 *
 *  Created on: Aug 5, 2013
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

#ifndef MAXIMUMOFALLSUBARRAYSOFSIZEK_H_
#define MAXIMUMOFALLSUBARRAYSOFSIZEK_H_

vector<int> MaximumOfAllSubArraysOfSizeKON2(int userInput[],int sizeOfArray,int k){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	int innerCounter,outerCounter;
	vector<int> maxElements;
	int maxElementInSubArray;
	for(outerCounter=0;outerCounter < sizeOfArray;outerCounter+=k){
		maxElementInSubArray = INT_MIN;
		for(innerCounter=outerCounter;innerCounter<outerCounter+k && innerCounter< sizeOfArray;innerCounter++){
			if(maxElementInSubArray < userInput[innerCounter]){
				maxElementInSubArray = userInput[innerCounter];
			}
		}
		maxElements.push_back(maxElementInSubArray);
	}
	return maxElements;
}

vector<int> MaximumOfAllSubArraysOfSizeKON(int userInput[],int sizeOfArray,int k){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
}


#endif /* MAXIMUMOFALLSUBARRAYSOFSIZEK_H_ */

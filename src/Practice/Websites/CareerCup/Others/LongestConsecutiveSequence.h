/*
 * LongestConsecutiveSequence.h
 *
 *  Created on: Aug 19, 2013
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

#ifndef LONGESTCONSECUTIVESEQUENCE_H_
#define LONGESTCONSECUTIVESEQUENCE_H_

int LongestConsecutiveSequenceON2(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	int outerCounter,innerCounter;
	for(outerCounter = 0;outerCounter < sizeOfArray;outerCounter++){
		for(innerCounter = outerCounter;innerCounter < sizeOfArray;innerCounter++){

		}
	}
}

int LongestConsecutiveSequenceONLOGN(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
}

int LongestConsecutiveSequenceON(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
}

#endif /* LONGESTCONSECUTIVESEQUENCE_H_ */

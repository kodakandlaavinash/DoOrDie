/*
 * FindNumberOccuringOddTimes.h
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

#ifndef FINDNUMBEROCCURINGODDTIMES_H_
#define FINDNUMBEROCCURINGODDTIMES_H_

/**
 * Tested
 */
int FindNumberOccuringOddNumberTimesXOR(int userInput[],int sizeOfArray){
	int XORResult = 0;
	for(int crawler=0;crawler < sizeOfArray;crawler++){
		XORResult ^= userInput[crawler];
	}
	return XORResult;
}

/**
 * Tested
 */
int FindNumberOccuringOddNumberTimes(int userInput[],int sizeOfArray){
	hash_map<int,int> frequencyMap;
	hash_map<int,int>::iterator itToFrequencyMap;
	set<int> keys;
	int keyOccurence;
	for(int crawler=0;crawler < sizeOfArray;crawler++){
		if((itToFrequencyMap = frequencyMap.find(userInput[crawler]))!= frequencyMap.end()){
			keyOccurence = itToFrequencyMap->second;
			keyOccurence++;
		}else{
			keyOccurence = 1;
			keys.insert(userInput[crawler]);
		}
		frequencyMap[userInput[crawler]] = keyOccurence;
	}

	for(set<int>::iterator itToKeys = keys.begin();itToKeys != keys.end();itToKeys++){
		if(frequencyMap[*itToKeys]%2 == 1){
			return *itToKeys;
		}
	}
	return INT_MIN;
}

/**
 * Tested
 */
int OddOccurenceOfKeyON2(int userInput[],int arraySize){
	int outerCrawler =0;
	int innerCrawler;
	int keyCounter =1;
	for(outerCrawler =0;outerCrawler < arraySize;outerCrawler++){
		keyCounter =1;
		for(innerCrawler = 0;innerCrawler < arraySize;innerCrawler++){
			if(outerCrawler == innerCrawler){
				continue;
			}
			if(userInput[outerCrawler] == userInput[innerCrawler]){
				keyCounter++;
			}
		}
		if(keyCounter%2 == 1){
			return userInput[outerCrawler];
		}
	}
	return INT_MIN;
}

/**
 * Tested
 */
int FindNumberOccuringOddTimesHashMap(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return INT_MIN;
	}

	hash_map<int,bool> occurenceOfNumber;
	hash_map<int,bool>::iterator itToOccurenceMap;
	int crawler = 0;
	for(;crawler < sizeOfArray;crawler++){
		if(((itToOccurenceMap = occurenceOfNumber.find(userInput[crawler]))!= occurenceOfNumber.end())){
			occurenceOfNumber[userInput[crawler]] = !occurenceOfNumber[userInput[crawler]];
		}else{
			occurenceOfNumber.insert(pair<int,bool>(userInput[crawler],true));
		}
	}

	for(itToOccurenceMap = occurenceOfNumber.begin();itToOccurenceMap != occurenceOfNumber.end();itToOccurenceMap++){
		if(itToOccurenceMap->second){
			return itToOccurenceMap->first;
		}
	}
	return INT_MIN;
}
#endif /* FINDNUMBEROCCURINGODDTIMES_H_ */

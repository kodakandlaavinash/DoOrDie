/*
 * FindDuplicatesInONTimeO1Space.h
 *
 *  Created on: Jul 29, 2013
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

#ifndef FINDDUPLICATESINONTIMEO1SPACE_H_
#define FINDDUPLICATESINONTIMEO1SPACE_H_

vector<int> FindDuplicatesInONTimeO1Space(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	vector<int> duplicates;
	for(int counter =0;counter < sizeOfArray;counter++){
		if(userInput[userInput[counter]] < 0){
			duplicates.push_back(userInput[counter]);
		}else{
			userInput[userInput[counter]] *= -1;
		}
	}
	return duplicates;
}

set<int> FindDuplicatesInON2Time(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	set<int> duplicates;
	for(int outerCounter =0;outerCounter < sizeOfArray;outerCounter++){
		for(int innerCounter = 0;innerCounter < sizeOfArray;innerCounter++){
			if(innerCounter == outerCounter){
				continue;
			}
			if(userInput[outerCounter] == userInput[innerCounter]){
				duplicates.insert(userInput[outerCounter]);
			}
		}
	}
}

vector<int> FindDuplicatesInONTimeONSpace(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	hash_map<int,int> occurenceMap;
	hash_map<int,int>::iterator *itToOccurenceMap;
	vector<int> duplicates;
	for(int counter =0;counter < sizeOfArray;counter++){
		if((itToOccurenceMap = occurenceMap.find(userInput[counter])) != occurenceMap.end()){
			duplicates.push_back(userInput[counter]);
			occurenceMap[userInput[counter]] += 1;
		}else{
			occurenceMap.insert(pair<int,int>(userInput[counter],1));
		}
	}
	return duplicates;
}

#endif /* FINDDUPLICATESINONTIMEO1SPACE_H_ */

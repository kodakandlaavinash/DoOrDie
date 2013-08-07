/*
 * FindRepeatingAndMissingNumber.h
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

#ifndef FINDREPEATINGANDMISSINGNUMBER_H_
#define FINDREPEATINGANDMISSINGNUMBER_H_

int *FindRepeatingAndMissingNumberForRange1ToNON(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	int repeatingNumber,missingNumber;
	for(int counter =0;counter < sizeOfArray;counter++){
		if(userInput[userInput[counter] - 1] < 0){
			repeatingNumber = userInput[counter];
		}else{
			userInput[userInput[counter]-1] *= -1;
		}
	}
	for(int counter =0;counter < sizeOfArray;counter++){
		if(userInput[userInput[counter]] > 0){
			missingNumber = userInput[counter];
		}
	}
	int output[2]={repeatingNumber,missingNumber};
	return output;
}

int *FindRepeatingAndMissingNumberForRange1ToNON2(int userInput[],int sizeOfArray,int n){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	int outerCounter,innerCounter;
	int countOfOccurence;
	bool keyOccured;
	int repeatMissingResult[2];
	for(int counter = 1;counter < n;counter++){
		keyOccured = false;
		countOfOccurence = 0;
		for(int arrayCounter =0 ;arrayCounter < sizeOfArray;arrayCounter++){
			if(counter == userInput[arrayCounter]){
				countOfOccurence++;
				keyOccured = true;
			}
		}
		if(!keyOccured){
			repeatMissingResult[1] = counter;
		}
		if(countOfOccurence > 1){
			repeatMissingResult[0] = counter;
		}
	}
	return repeatMissingResult;
}

int *FindRepeatingAndMissingNumberAuxSpaceON(int userInput[],int sizeOfArray,int n){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	hash_map<int,int> occurenceMap;
	hash_map<int,int>::iterator itToOccurenceMap;
	for(int counter =0;counter < sizeOfArray;counter++){
		if((itToOccurenceMap = occurenceMap.find(userInput[counter])) != occurenceMap.end()){
			occurenceMap.insert(pair<int,int>(userInput[counter],itToOccurenceMap->second+1));
		}
	}
	int repeatMissingNumber[2];
	for(int finder = 1;finder <= n;finder++){
		if((itToOccurenceMap = occurenceMap.find(finder)) != occurenceMap.end()){
			if(itToOccurenceMap->second > 1){
				repeatMissingNumber[0]=finder;
			}
		}else{
			repeatMissingNumber[1]=finder;
		}
	}
	return repeatMissingNumber;
}

int *FindRepeatingAndMissingNumberONLogN(int userInput[],int sizeOfArray,int n){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
}

#endif /* FINDREPEATINGANDMISSINGNUMBER_H_ */

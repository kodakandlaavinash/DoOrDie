/*
 * PokerFunction.h
 *	http://www.careercup.com/question?id=10225569
 *  Created on: Aug 19, 2013
 *  Author: Avinash
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

#ifndef POKERFUNCTION_H_
#define POKERFUNCTION_H_

//Assuming all the values are positive
bool PokerFunctionON2(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return true;
	}
	int counterForTwo,counterForThree;
	int outerCounter,innerCounter;
	int frequencyCounter = 0;
	for(outerCounter = 0;outerCounter<sizeOfArray;outerCounter++){
		if(userInput[outerCounter] < 0){
			continue;
		}
		frequencyCounter = 0;
		for(innerCounter = outerCounter+1;innerCounter<sizeOfArray;innerCounter++){
			if(userInput[innerCounter] == userInput[outerCounter]){
				frequencyCounter++;
			}
		}
		if(frequencyCounter != 2 && frequencyCounter != 3){
			return false;
		}
		if(frequencyCounter%2 == 0){
			counterForTwo += frequencyCounter/2;
		}
		if(frequencyCounter%3 == 0){
			counterForThree+=frequencyCounter/3;
		}
	}
	if(counterForThree == counterForTwo){
		return true;
	}
	return false;
}

bool PokerFunctionON(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return true;
	}
	hash_map<int,int> frequencyMap;
	hash_map<int,int>::iterator itToFrequencyMap;
	int noOfOccurence;
	for(int counter = 0;counter < sizeOfArray;counter++){
		if((itToFrequencyMap = frequencyMap.find(userInput[counter])) != frequencyMap.end()){
			noOfOccurence = itToFrequencyMap->second;
			frequencyMap[userInput[counter]] = ++noOfOccurence;
		}else{
			frequencyMap[userInput[counter]]=1;
		}
	}
	int twoCounter=0,threeCounter=0;
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		if(itToFrequencyMap->second !=2 && itToFrequencyMap->second != 3){
			return false;
		}
		if(itToFrequencyMap->second%2 == 0){
			twoCounter += itToFrequencyMap->second/2;
		}
		if(itToFrequencyMap->second%3 == 0){
			threeCounter += itToFrequencyMap->second/3;
		}
	}
	if(twoCounter == threeCounter){
		return true;
	}
	return false;
}

bool PokerFunctionSorting(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return false;
	}
	sort(userInput,userInput+sizeOfArray);
	int twoCounter = 0,threeCounter =0,frequencyCounter;
	for(int counter = 0;counter < sizeOfArray-1;counter++){
		frequencyCounter = 1;
		while(userInput[counter] == userInput[counter+1]){
			frequencyCounter++;counter++;
		}
		if(!frequencyCounter%2 == 0 && !frequencyCounter%3 == 0){
			return false;
		}
		if(frequencyCounter%2 == 0){
			twoCounter += frequencyCounter/2;
		}else{
			threeCounter += frequencyCounter/3;
		}
	}
	if(twoCounter == threeCounter){
		return true;
	}
	return false;
}

#endif /* POKERFUNCTION_H_ */

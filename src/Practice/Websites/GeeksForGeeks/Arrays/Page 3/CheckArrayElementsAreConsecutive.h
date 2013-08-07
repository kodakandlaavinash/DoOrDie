/*
 * CheckArrayElementsAreConsecutive.h
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

#ifndef CHECKARRAYELEMENTSARECONSECUTIVE_H_
#define CHECKARRAYELEMENTSARECONSECUTIVE_H_


/*
 * Assuming element are distinct
 */
bool CheckWhetherElementsAreConsecutive(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray ==0){
		return true;
	}
	int maxElement = INT_MIN;
	int minElement = INT_MAX;
	int sumOfElementOfArray = 0;
	for(int counter = 0;counter < sizeOfArray;counter++){
		if(maxElement < userInput[counter]){
			maxElement = userInput[counter];
		}
		if(minElement > userInput[counter]){
			minElement = userInput[counter];
		}
		sumOfElementOfArray += userInput[counter];
	}

	int expectedSum = (sizeOfArray/2)(minElement+maxElement);
	if(expectedSum == sumOfElementOfArray){
		return true;
	}
	return false;
}

bool CheckElementsAreConsecutiveON2(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return true;
	}
	int minElement = min_element(userInput,userInput+sizeOfArray);
	int maxElement = max_element(userInput,userInput+sizeOfArray);

	int innerCounter,outerCounter;
	bool elementFound;
	for(outerCounter = minElement;outerCounter <= maxElement;outerCounter++){
		elementFound = false;
		for(innerCounter =0;innerCounter < sizeOfArray;innerCounter++){
			if(userInput[innerCounter] == outerCounter){
				elementFound = true;
			}
		}
		if(!elementFound){
			return false;
		}
	}
	return true;
}

bool CheckArrayElementAreConsecutiveAuxSpace(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return true;
	}
	hash_map<int,int> occurenceMap;
	int maxElement = INT_MIN,minElement = INT_MAX;
	for(int counter = 0;counter < sizeOfArray;counter++){
		occurenceMap.insert(pair<int,int>(userInput[counter],1));
		if(maxElement < userInput[counter]){
			maxElement = userInput[counter];
		}
		if(minElement < userInput[counter]){
			minElement = userInput[counter];
		}
	}
	for(int counter = minElement;counter <= maxElement;counter++){
		if(occurenceMap.find(counter) == occurenceMap.end()){
			return false;
		}
	}
	return true;
}

bool CheckArrayElementAreConsecutiveDivideAndConquer(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return true;
	}
	int startCrawler = 0,endCrawler = sizeOfArray-1,tempForSwap;
	while(startCrawler < endCrawler){
		while(userInput[startCrawler] > 0){
			startCrawler++;
		}
		while(userInput[endCrawler] < 0 && startCrawler < endCrawler){
			endCrawler--;
		}
		if(startCrawler < endCrawler){
			tempForSwap = userInput[startCrawler];
			userInput[startCrawler] = userInput[endCrawler];
			userInput[endCrawler] = tempForSwap;
		}
	}

	int minElementForNegativeNumbers = min_element(userInput,userInput+endCrawler);
	//For Negative numbers
	for(int counter = 0;counter < endCrawler;counter++){
		userInput[userInput[counter] - minElementForNegativeNumbers] *= -1;
	}

	//For Positive numbers
	for(int counter = endCrawler+1;counter < sizeOfArray;counter++){
		userInput[userInput[counter]+endCrawler+1] *= -1;
	}


	for(int counter =0;counter < endCrawler;counter++){
		if(userInput[counter] < 0){
			return false;
		}
	}

	for(int counter  = endCrawler+1;counter < sizeOfArray;counter++){
		if(userInput[counter] > 0){
			return false;
		}
	}
	return true;
}

#endif /* CHECKARRAYELEMENTSARECONSECUTIVE_H_ */

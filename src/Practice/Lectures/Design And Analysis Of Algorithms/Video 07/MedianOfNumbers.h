/*
 * MediaOfNumbers.h
 *
 *  Created on: Jul 12, 2013
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

#ifndef MEDIAOFNUMBERS_H_
#define MEDIAOFNUMBERS_H_

int MedianOfNumbersON2(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	int middleIndex = (sizeOfArray)/2;
	int totalLess;
	int totalGreater;
	for(int outerCounter = 0;outerCounter < sizeOfArray;outerCounter++){
		totalLess = 0;
		totalGreater = 0;
		for(int innerCounter =0;innerCounter < sizeOfArray;innerCounter++){
			if(innerCounter  == outerCounter){
				continue;
			}
			if(userInput[outerCounter] > userInput[innerCounter]){
				totalLess++;
			}else{
				totalGreater++;
			}
		}
		if(totalLess == totalGreater){
			return userInput[outerCounter];
		}
	}
}

int MedianOfNumberONLOGN(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	sort(userInput,userInput+sizeOfArray);
	return userInput[sizeOfArray/2];
}

int FindMedianOfNumbersOfSmallGroup(int userInput[],int startIndex,int endIndex){
	sort(userInput+startIndex,userInput+endIndex);
	return userInput[(startIndex+endIndex)/2];
}

int GetApproximateMedian(int userInput[],int startIndex,int endIndex){
	vector<int> auxSpace;
	for(int counter=startIndex;counter <= endIndex;startIndex+=5){
		auxSpace.push_back(FindMedianOfNumbersOfSmallGroup(userInput,counter,counter+4));
	}
	sort(auxSpace.begin(),auxSpace.end());
	return auxSpace[auxSpace.size()/2];
}

int MedianOfNumbersOfON(int userInput[],int startIndex,int endIndex,int rank){
	if(startIndex > endIndex){
		return INT_MIN;
	}
	int appxMedian = GetApproximateMedian(userInput,startIndex,endIndex);

}

#endif /* MEDIAOFNUMBERS_H_ */

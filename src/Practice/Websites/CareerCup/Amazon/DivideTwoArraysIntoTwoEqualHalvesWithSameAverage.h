/*
 * DivideTwoArraysIntoTwoEqualHalvesWithSameAverage.h
 *	http://www.careercup.com/question?id=6748824919867392
 *  Created on: Sep 4, 2013
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

#ifndef DIVIDETWOARRAYSINTOTWOEQUALHALVESWITHSAMEAVERAGE_H_
#define DIVIDETWOARRAYSINTOTWOEQUALHALVESWITHSAMEAVERAGE_H_

bool CheckWhetherThereExistsTwoSubarraysWithSameAverageValue(int userInput[],int sizeOfArray,int totalSum,int currentSize,int currentSum){
	if(userInput == NULL || sizeOfArray == 0){
		return true;
	}
	if(currentSize == sizeOfArray/2){
		if(currentSum == totalSum/2){
			return true;
		}
		return false;
	}
	return CheckWhetherThereExistsTwoSubarraysWithSameAverageValue(userInput,sizeOfArray,totalSum,currentSize+1,currentSum) || CheckWhetherThereExistsTwoSubarraysWithSameAverageValue(userInput,sizeOfArray,totalSum,currentSize+1,currentSum+userInput[currentSize]);
}

bool CheckWhetherThereExistsTwoSubArraysWithSameAverageValueNaive(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return true;
	}
	int sumOfArray = 0;
	for(int counter = 0;counter < sizeOfArray;counter++){
		sumOfArray += userInput[counter];
	}
	int sumOfSubArray =0;
	for(int counter = 0;counter < pow(2,sizeOfArray);counter++){
		bitset<sizeOfArray> bitRepOfDecimal(userInput[counter]);
		int bitSet = bitRepOfDecimal.count();
		if(bitSet == sizeOfArray/2){
			sumOfSubArray = 0;
			for(int bitCounter = 0;bitCounter < sizeOfArray;bitCounter++){
				if(bitRepOfDecimal[bitCounter]){
					sumOfSubArray += userInput[bitCounter];
				}
			}
			if(sumOfSubArray == sumOfArray/2){
				return true;
			}
		}
	}
	return false;
}

#endif /* DIVIDETWOARRAYSINTOTWOEQUALHALVESWITHSAMEAVERAGE_H_ */

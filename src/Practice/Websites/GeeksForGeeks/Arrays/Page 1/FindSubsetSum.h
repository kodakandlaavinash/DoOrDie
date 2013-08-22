/*
 * FindSubsetSum.h
 *
 *  Created on: Aug 22, 2013
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

#ifndef FINDSUBSETSUM_H_
#define FINDSUBSETSUM_H_

bool FindSubsetSumO2N(int userInput[],int sizeOfArray,vector<int> &resultingSubset1,vector<int> &resultingSubset2){
	if(userInput == NULL || sizeOfArray == 0){
		return false;
	}
	int sum = 0;
	for(int counter = 0;counter < sizeOfArray;counter++){
		sum += userInput[counter];
	}
	if(sum%2 == 1){
		return false;
	}
	int currentSubSetSum;
	for(int counter = 0;counter < pow(2,sizeOfArray);counter++){
		currentSubSetSum = 0;
		bitset<sizeOfArray> bitRep(counter);
		for(int bitCounter = 0;bitCounter < sizeOfArray;bitCounter++){
			if(bitRep[bitCounter]){
				currentSubSetSum += userInput[bitCounter];
			}
		}
		if(currentSubSetSum = sum/2){
			for(int bitCounter = 0;bitCounter < sizeOfArray;bitCounter++){
				if(bitRep[bitCounter]){
					resultingSubset1.push_back(userInput[bitCounter]);
				}else{
					resultingSubset2.push_back(userInput[bitCounter]);
				}
			}
			return true;
		}
	}
	return false;
}

bool FindSubSetSumDP(int userInput[],int sizeOfArray,int currentIndex,int targetSum){
	if(currentIndex >= sizeOfArray){
		return false;
	}
	if(targetSum == 0){
		return true;
	}
	return FindSubSetSumDP(userInput,sizeOfArray,currentIndex+1,targetSum) || FindSubSetSumDP(userInput,sizeOfArray,currentIndex+1,targetSum - userInput[currentIndex]);
}


#endif /* FINDSUBSETSUM_H_ */

/*
 * MaximumSubSequenceSum.h
 *
 *  Created on: Aug 1, 2013
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

#ifndef MAXIMUMSUBSEQUENCESUM_H_
#define MAXIMUMSUBSEQUENCESUM_H_

int MaximumSubSequenceSum(int userInput[],int sizeOfArray,int currentIndex){
	if(sizeOfArray < 0 || currentIndex < 0){
		return INT_MIN;
	}
	if(currentIndex == 0){
		return userInput[0];
	}
	int maxSubSequenceSum = INT_MIN,result;
	for(int counter = sizeOfArray -1;counter >=0;counter++){
		result = MaximumSubSequenceSum(userInput,counter-1,currentIndex-1);
		if(result > maxSubSequenceSum){
			result = maxSubSequenceSum;
		}
	}
	return maxSubSequenceSum;
}

int MaximumSubSequenceSumMemoziation(int userInput[],int sizeOfArray,int crawler){

}

int MaximumSubSequenceSumO2N(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	int maxSubSequenceSum = INT_MIN,currentSum;
	for(int counter =0;counter < pow(2,sizeOfArray);counter++){
		bitset<sizeOfArray> binaryRepOfCounter;
		currentSum = 0;
		for(int bitCounter = 0;bitCounter < sizeOfArray;bitCounter++){
			if(binaryRepOfCounter[bitCounter]){
				currentSum += userInput[bitCounter];
			}
		}
		if(maxSubSequenceSum < currentSum){
			maxSubSequenceSum = currentSum;
		}
	}
	return maxSubSequenceSum;
}

#endif /* MAXIMUMSUBSEQUENCESUM_H_ */

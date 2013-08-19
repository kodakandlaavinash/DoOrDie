/*
 * LongestIncreasingSubSequence.h
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

#ifndef LONGESTINCREASINGSUBSEQUENCE_H_
#define LONGESTINCREASINGSUBSEQUENCE_H_

void LongestIncreasingSubSequence(int userInput[],int sizeOfArray,int i){

}

void LongestIncreasingSubSequenceMemoziation(int userInput[],int sizeOfArray,int i){

}

int LongestIncreasingSubSequenceO2N(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0 || userInput == NULL){
		return 0;
	}
	int longestIncreasingSequenceLength,currentLengthOfIncSequence;
	bool isIncreasingSequence;
	vector<int> currentSubSet;
	for(int counter = 1;counter < pow(2,sizeOfArray);counter++){
		bitset<sizeOfArray> bitRepOfCounter(counter);
		isIncreasingSequence = true;
		currentSubSet.clear();
		for(int bitCounter = 0;bitCounter < sizeOfArray;bitCounter++){
			if(bitRepOfCounter[bitCounter] == counter){
				currentSubSet.push_back(userInput[bitCounter]);
			}
		}
		//Elliminating empty sub set
		if(currentSubSet.size() > 0){
			isIncreasingSequence = true;
			currentLengthOfIncSequence = 0;
			for(int vectorCounter = 0;vectorCounter < currentSubSet.size()-1;vectorCounter++){
				if(currentSubSet[vectorCounter] > currentSubSet[vectorCounter+1]){
					isIncreasingSequence = false;
				}
				currentLengthOfIncSequence++;
			}
			if(isIncreasingSequence){
				if(longestIncreasingSequenceLength < currentLengthOfIncSequence){
					longestIncreasingSequenceLength = currentLengthOfIncSequence;
				}
			}
		}
	}
	return longestIncreasingSequenceLength;
}
#endif /* LONGESTINCREASINGSUBSEQUENCE_H_ */

/*
 * TANGLED.h
 *	http://www.codechef.com/problems/TANGLED
 *  Created on: Sep 9, 2013
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

#ifndef TANGLED_H_
#define TANGLED_H_

void PrintCommonSubStrings(string userInput1,string userInput2,int length){
	hash_map<string,int> frequencyMapOfSubstrings;
	hash_map<string,int>::iterator itToFrequencyMapOfSubStrings;
	hash_map<int,int> subStringCounter;
	hash_map<int,int>::iterator itToSubStringCounter;
	string subString;
	for(int subStringLengthCounter = 1;subStringLengthCounter <= length;subStringLengthCounter++){
		for(int counter = 0;counter < userInput1.length() - length +1;counter+=subStringLengthCounter){
			subString = substr(counter,subStringLengthCounter);
			if(itToFrequencyMapOfSubStrings = frequencyMapOfSubstrings.find(subString) != frequencyMapOfSubstrings.end()){
				frequencyMapOfSubstrings[subString] = itToFrequencyMapOfSubStrings->second+1;
			}else{
				frequencyMapOfSubstrings[subString] = 1;
			}
		}
	}

	for(int subStringLengthCounter = 1;subStringLengthCounter <= length;subStringLengthCounter){
		for(int counter =0;counter < userInput2.length() - length + 1;counter+=subStringLengthCounter){
			subString = substr(counter,subStringLengthCounter);
			if(itToFrequencyMapOfSubStrings = frequencyMapOfSubstrings.find(subString) != frequencyMapOfSubstrings.end()){
				if(itToSubStringCounter = subStringCounter.find(subStringLengthCounter) != subStringCounter.end()){
					subStringCounter[subStringLengthCounter] += itToFrequencyMapOfSubStrings->second;
				}else{
					subStringCounter[subStringLengthCounter] = itToFrequencyMapOfSubStrings->second;
				}
			}
		}
	}

	for(itToSubStringCounter = subStringCounter.begin();itToSubStringCounter != subStringCounter.end();itToSubStringCounter++){
		printf("%d %d\n",itToSubStringCounter->first,itToSubStringCounter->second);
	}
}

int main(){
	int noOfTestCases;
	scanf("%d",&noOfTestCases);
	string userInput1;
	string userInput2;
	int lengthOfSubString;
	while(noOfTestCases--){
		scanf("%d",&userInput1);
		scanf("%d",&userInput2);
		scanf("%d",lengthOfSubString);
		PrintCommonSubStrings(userInput1,userInput2,lengthOfSubString);
	}
}

#endif /* TANGLED_H_ */

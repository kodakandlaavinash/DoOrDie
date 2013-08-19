/*
 * LongestCommonSubsequence.h
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

#ifndef LONGESTCOMMONSUBSEQUENCE_H_
#define LONGESTCOMMONSUBSEQUENCE_H_

int LongestCommonSubsequenceDP(char userInput1[],int sizeOfArray1,char userInput2[],int sizeOfArray2,int crawler1,int crawler2){
	if(crawler1 >= sizeOfArray1 || crawler2 >= sizeOfArray2){
		return 0;
	}
	if(userInput1[crawler1] == userInput2[crawler2]){
		return 1 + LongestCommonSubsequenceDP(userInput1,sizeOfArray1,userInput2,sizeOfArray2,crawler1+1,crawler2);
	}else{
		return max(LongestCommonSubsequenceDP(userInput1,sizeOfArray1,userInput2,sizeOfArray2,crawler1+1,crawler2),LongestCommonSubsequenceDP(userInput1,sizeOfArray1,userInput2,sizeOfArray2,crawler1,crawler2+1));
	}
}

int LongestCommonSubsequenceMemoziation(char userInput1[],int sizeOfArray1,char userInput2[],int sizeOfArray2,int crawler1,int crawler2){

}

int LongestCommonSubsequenceDPStrategy2(int userInput1[],int sizeOfArray1,int userInput2[],int sizeOfArray2,int crawler1,int crawler2){

}

int LongestCommonSubSequenceO2N(int userInput1[],int sizeOfArray1,int userInput2[],int sizeOfArray2){
	if(userInput1 == NULL || sizeOfArray1 == 0 || userInput2 == NULL || sizeOfArray2 == 0){
		return 0;
	}
	list<vector<int>> subsetsOfUserInput1,subsetsOfUserInput2;
	for(int counter = 0;counter < pow(2,sizeOfArray1);counter++){
		bitset<sizeOfArray1> bitRep;
		vector<int> currentSubSet;
		for(int bitCounter  = 0;bitCounter < bitRep.size();bitCounter++){
			if(bitRep[bitCounter]){
				currentSubSet.push_back(userInput1[bitCounter]);
			}
		}
		subsetsOfUserInput1.push_back(currentSubSet);
		currentSubSet.clear();
	}

	for(int counter = 0;counter < pow(2,sizeOfArray2);counter++){
		bitset<sizeOfArray2> bitRep;
		vector<int> currentSubSet;
		for(int bitCounter = 0;bitCounter < bitRep.size();bitCounter++){
			if(bitRep[bitCounter]){
				currentSubSet.push_back(userInput2[bitCounter]);
			}
		}
		subsetsOfUserInput2.push_back(currentSubSet);
		currentSubSet.clear();
	}

	for(int firstSubSetCounter = 0;firstSubSetCounter < subsetsOfUserInput1.size();firstSubSetCounter++){
		for(int secondSubSetCounter =0;secondSubSetCounter < subsetsOfUserInput2.size();secondSubSetCounter++){

		}
	}
}
#endif /* LONGESTCOMMONSUBSEQUENCE_H_ */

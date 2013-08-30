/*
 * 	SubsetProblem.h
 *	http://www.careercup.com/question?id=6241189850251264
 *  Created on: Aug 28, 2013
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

#ifndef SUBSETPROBLEM_H_
#define SUBSETPROBLEM_H_

vector<vector<int>> FindAllSubsetsWithGivenSum(int userInput[],int sizeOfArray,int sum){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	vector<vector<int>> allSubsetsWithGivenSum;
	vector<int> currentSet;
	int currentSum;
	for(int counter = 0;counter < pow(2,sizeOfArray);counter++){
		bitset<sizeOfArray> bitRepresentationOfDecimal;
		currentSum = 0;
		currentSet.clear();
		for(int bitCounter = 0;bitCounter < sizeOfArray;bitCounter++){
			if(bitRepresentationOfDecimal[bitCounter]){
				currentSet.push_back(userInput[bitCounter]);
				currentSum += userInput[bitCounter];
			}
		}
		if(currentSum == sum){
			allSubsetsWithGivenSum.push_back(currentSet);
		}
	}
}

void FindSubsetProblemDP(int userInput[],int sizeOfArray,int currentCounter,int targetSum,vector<vector<int>> &allSubsets){
	if(targetSum  == 0){

	}
	if(currentCounter >= sizeOfArray){
		return;
	}

}

void FindSubSetProblemAfterSorting(int userInput[],int sizeOfArray,int currentCounter,int targetSum,vector<int> currentSet,vector<vector<int>> &allSubsets){
	if(targetSum == 0){
		allSubsets.push_back(currentSet);
		return;
	}
	if(currentCounter >= sizeOfArray){
		return;
	}
	//If current element is greater than the current sum
	//there is no need to check for the other elements from this index
	//because they are greater than the current element since they are sorted
	if(userInput[currentCounter] > targetSum){
		return;
	}
	FindSubSetProblemAfterSorting(userInput,sizeOfArray,currentCounter+1,targetSum,currentSet,allSubsets);
	FindSubSetProblemAfterSorting(userInput,sizeOfArray,currentCounter+1,targetSum-userInput[currentCounter],currentSet.push_back(userInput[currentCounter]),allSubsets);
}

#endif /* SUBSETPROBLEM_H_ */

/*
 * FindTripletThatSumToGivenValue.h
 *
 *  Created on: Aug 6, 2013
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

#ifndef FINDTRIPLETTHATSUMTOGIVENVALUE_H_
#define FINDTRIPLETTHATSUMTOGIVENVALUE_H_

int *FindTripeletThatEqualsToGivenValue(int userInput[],int sizeOfArray,int target){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	int sumOfElements = 0;
	for(int i=0;i < sizeOfArray;i++){
		for(int j=i+1;j < sizeOfArray;j++){
			for(int k=j+1;k < sizeOfArray;k++){
				sumOfElements = userInput[i] + userInput[j] + userInput[k];
				if(sumOfElements == target){
					int result[3];
					result[0] = userInput[i];
					result[1] = userInput[j];
					result[2] = userInput[k];
					return result;
				}
			}
		}
	}
	return result;
}

int *FindTripletThatSumToGivenValue(int userInput[],int sizeOfArray,int targetSum){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	sort(userInput,userInput+sizeOfArray);
	int sumOfElements = 0;
	for(int i=0;i < sizeOfArray;i++){
		j=i+1;
		k=sizeOfArray-1;
		while(j < k){
			sumOfElements = userInput[i] + userInput[j] + userInput[k];
			if(sumOfElements == targetSum){
				int result[3];
				result[0] = userInput[i];
				result[1] = userInput[j];
				result[2] = userInput[k];
				return result;
			}
			if(sumOfElements > targetSum){
				k--;
			}
			if(sumOfElements < targetSum){
				j++;
			}
		}
	}
}

#endif /* FINDTRIPLETTHATSUMTOGIVENVALUE_H_ */

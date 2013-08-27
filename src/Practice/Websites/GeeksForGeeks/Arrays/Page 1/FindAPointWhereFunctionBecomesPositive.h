/*
 * FindAPointWhereFunctionBecomesPositive.h
 *
 *  Created on: Aug 26, 2013
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

#ifndef FINDAPOINTWHEREFUNCTIONBECOMESPOSITIVE_H_
#define FINDAPOINTWHEREFUNCTIONBECOMESPOSITIVE_H_


int FunctionalValue(int userInput){

}

int FindAPointWhereFunctionBecomesPositiveON(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	int functionOutputValue;
	for(int counter =0;counter < sizeOfArray;counter++){
		functionOutputValue = FunctionalValue(userInput[counter]);
		if(functionOutputValue > 0){
			return userInput[counter];
		}
	}
	return INT_MIN;
}

int FindAPointWhereFunctionBecomesPositiveOLOGN(int userInput[],int startIndex,int endIndex){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] > 0){
		if(middleIndex-1 > 0){
			if(FunctionalValue(userInput[middleIndex]) > 0){
				return FindAPointWhereFunctionBecomesPositiveOLOGN(userInput,startIndex,middleIndex-1);
			}
		}else{
			return middleIndex;
		}
	}else{
		return FindAPointWhereFunctionBecomesPositiveOLOGN(userInput,middleIndex+1,endIndex);
	}
}

#endif /* FINDAPOINTWHEREFUNCTIONBECOMESPOSITIVE_H_ */

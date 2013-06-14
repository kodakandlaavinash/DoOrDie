/*
 * FindFixedPointInArray.h
 *
 *  Created on: May 20, 2013
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

#ifndef FINDFIXEDPOINTINARRAY_H_
#define FINDFIXEDPOINTINARRAY_H_

int FindFixedPointInArray(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return -1;
	}

	for(int crawler=0;crawler < sizeOfArray;crawler++){
		if(userInput[crawler] == crawler){
			return userInput[crawler];
		}
	}
	return -1;
}

int FindFixedPointInArrayBinaryEnhanced(int userInput[],int startIndex,int endIndex){
	if(startIndex > endIndex){
		return -1;
	}
	int middle  = (startIndex+endIndex)/2;
	if(userInput[middle] == middle){
		return userInput[middle];
	}

	if(userInput[middle] > middle){
		return FindFixedPointInArrayBinaryEnhanced(userInput,startIndex,middle-1);
	}else{
		return FindFixedPointInArrayBinaryEnhanced(userInput,middle+1,endIndex);
	}
}

#endif /* FINDFIXEDPOINTINARRAY_H_ */

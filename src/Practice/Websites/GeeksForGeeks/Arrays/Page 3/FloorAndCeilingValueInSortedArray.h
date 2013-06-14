/*
 * FloorAndCeilingValueInSortedArray.h
 *
 *  Created on: May 15, 2013
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

#ifndef FLOORANDCEILINGVALUEINSORTEDARRAY_H_
#define FLOORANDCEILINGVALUEINSORTEDARRAY_H_

int *FloorAndCeilingForGivenValue(int userInput[],int sizeOfArray,int inputValue){
	if(sizeOfArray == 0){
		return NULL;
	}
	int ceil = INT_MIN;
	int floor = INT_MAX;
	for(int crawler =0;crawler < sizeOfArray;crawler++){
		if(ceil < userInput[crawler] && userInput[crawler] < inputValue){
			ceil = userInput[crawler];
		}else{
			if(floor > userInput[crawler] && userInput[crawler] > inputValue){
				floor = userInput[crawler];
			}
		}
	}
	int ceilFloor[2] ={ceil,floor};
	return ceilFloor;
}

int *FloorAndCeilingForGivenValueBinarySearch(int userInput[],int startIndex,int endIndex,int key){
	if(startIndex > endIndex){
		return NULL;
	}
	int middleIndex = (startIndex+endIndex)/2;
	if(userInput[middleIndex] == key){

	}
}

int *FloorAndCeilinForGivenValueDriver(int userInput[],int sizeOfArray,int inputValue){

}
#endif /* FLOORANDCEILINGVALUEINSORTEDARRAY_H_ */

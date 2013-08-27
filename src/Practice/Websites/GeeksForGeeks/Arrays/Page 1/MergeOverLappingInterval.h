/*
 * MergeOverLappingInterval.h
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

#ifndef MERGEOVERLAPPINGINTERVAL_H_
#define MERGEOVERLAPPINGINTERVAL_H_

struct interval{
	int startInterval;
	int endInterval;
};

void MergeOverLappingIntervalsON2(interval userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	for(int counter = 0;counter < sizeOfArray;counter++){

	}
}

bool sortFunctionOverLappingInterval(interval left,interval right){
	return left.startInterval < right.startInterval?true:false;
}

void MergeOverLappingIntervalON(interval userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return;
	}
	sort(userInput,userInput+sizeOfArray,sortFunctionOverLappingInterval);
	stack<interval> auxSpace;
	auxSpace.push(userInput[0]);
	interval currentInterval;
	for(int counter = 1;counter < sizeOfArray;counter++){
		currentInterval= auxSpace.top();
		if(userInput[counter].startInterval < userInput[counter].endInterval){
			currentInterval.endInterval = max(currentInterval.endInterval,userInput[counter].endInterval);
			auxSpace.pop();
			auxSpace.push(currentInterval);
		}else{
			auxSpace.push(userInput[counter]);
		}
	}
	while(!auxSpace.empty()){
		printf("{%d,%d}",auxSpace.top().startInterval,auxSpace.top().endInterval);
		auxSpace.pop();
	}
}


#endif /* MERGEOVERLAPPINGINTERVAL_H_ */

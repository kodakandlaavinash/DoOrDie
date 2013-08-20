/*
 * IterativeQuickSort.h
 *
 *  Created on: Aug 19, 2013
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

#ifndef ITERATIVEQUICKSORT_H_
#define ITERATIVEQUICKSORT_H_

void QuickSortDivideStep(int userInput[],int startArray,int endArray){
	if(userInput == NULL){
		return;
	}
	int dividingElementValue = userInput[endArray];
	int tempForSwap;
	while(startArray < endArray){
		while(userInput[startArray]  < dividingElementValue){
			startArray++;
		}
		while(userInput[endArray] > dividingElementValue && startArray < endArray){
			endArray--;
		}
		if(startArray > endArray){
			return endArray;
		}
		tempForSwap = userInput[startArray];
		userInput[startArray] = userInput[endArray];
		userInput[endArray] = tempForSwap;
	}
}

void QuickSortIterative(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return;
	}
	stack<int> auxSpaceForQuickSort;
	auxSpaceForQuickSort.push(0);
	auxSpaceForQuickSort.push(sizeOfArray-1);
	int startIndex,endIndex,dividingIndex;
	while(auxSpaceForQuickSort.size()){
		endIndex = auxSpaceForQuickSort.top();auxSpaceForQuickSort.pop();
		startIndex = auxSpaceForQuickSort.top();auxSpaceForQuickSort.pop();
		dividingIndex = QuickSortDivideStep(userInput,startIndex,endIndex);
		auxSpaceForQuickSort.push(dividingIndex+1);
		auxSpaceForQuickSort.push(endIndex);
		auxSpaceForQuickSort.push(startIndex);
		auxSpaceForQuickSort.push(dividingIndex);
	}
}

#endif /* ITERATIVEQUICKSORT_H_ */

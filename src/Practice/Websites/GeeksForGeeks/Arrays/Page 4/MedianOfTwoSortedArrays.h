/*
 * MedianOfTwoSortedArrays.h
 *
 *  Created on: Jun 20, 2013
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

#ifndef MEDIANOFTWOSORTEDARRAYS_H_
#define MEDIANOFTWOSORTEDARRAYS_H_

int MedianOfTwoSortedArrays(int sortedUserInput1[],int sizeOfUserInput1,int sortedUserInput2[],int sizeOfUserInput2){
	if(sortedUserInput1 == null && sortedUserInput2 == null && sizeOfUserInput1 ==0 && sizeOfUserInput2 == 0){
		return 0;
	}
	int *mergedArray = (int *)calloc(sizeOfUserInput1 + sizeOfUserInput2 -1 ,sizeof(int));
	int counterSortedArray1=0,counterSortedArray2 = 0;
	int fillCounter = -1;
	while(counterSortedArray1 < sizeOfUserInput1 && counterSortedArray2 < sizeOfUserInput2){
		if(sortedUserInput1[counterSortedArray1] < sortedUserInput2[countedSortedArray2]){
			mergedArray[++fillCounter] = sortedUserInput1[counterSortedArray1];
			counterSortedArray1 += 1;
		}else{
			mergedArray[++fillCounter] = sortedUserInput2[countedSortedArray2];
			counterSortedArray2 += 1;
		}
		if(fillCounter == (sizeOfUserInput1+sizeOfUserInput2)/2){
			return (mergedArray[fillCounter] + mergedArray[fillCounter-1])/2;
		}
	}
}

int MedianOfTwoSortedArraysByIndividualMedians(int sortedUserInput1[],int sizeOfUserInput1,int sortedUserInput2[],int sizeOfUserInput2){
	if(sortedUserInput1 == null || sortedUserInput2 == null || sizeOfUserInput1 ==0 || sizeOfUserInput2 == 0){
		return 0;
	}

}

#endif /* MEDIANOFTWOSORTEDARRAYS_H_ */

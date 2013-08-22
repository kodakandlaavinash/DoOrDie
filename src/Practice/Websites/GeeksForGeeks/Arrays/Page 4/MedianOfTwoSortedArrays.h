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

int MedianOfTwoSortedArraysPostSorting(int sortedUserInput1[],int sizeOfUserInput1,int sortedUserInput2[],int sizeOfUserInput2){
	if(sortedUserInput1 == NULL || sizeOfUserInput1 == 0||sortedUserInput2 == NULL || sizeOfUserInput2 == 0){
		return 0;
	}
	int auxSpaceFiller = -1,sizeOfAuxArray = sizeOfUserInput1 + sizeOfUserInput2-1;
	int *auxSpace = (int *)calloc(sizeOfAuxArray,sizeof(int));
	for(int counter = 0;counter < sizeOfUserInput1;counter++){
		auxSpace[++auxSpaceFiller] = sortedUserInput1[counter];
	}
	for(int counter = 0;counter < sizeOfUserInput2;counter++){
		auxSpace[++auxSpaceFiller] = sortedUserInput2[counter];
	}
	sort(auxSpace,auxSpace+sizeOfAuxArray);
	if(sizeOfAuxArray%2 == 0){
		return (auxSpace[(sizeOfAuxArray/2)]+auxSpace[(sizeOfAuxArray/2+1)])/2;
	}else{
		return auxSpace[sizeOfAuxArray/2];
	}
}

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

int MedianOfTwoSortedArraysByIndividualMedians(int sortedUserInput1[],int startOfUserInput1,int endOfUserInput1,int sortedUserInput2[],int startOfUserInput2,int endOfUserInput2){
	if(startOfUserInput1 > endOfUserInput1 || startOfUserInput2 > endOfUserInput2){
		return INT_MIN;
	}
	int medianOfFirstSortedArray1,medianOfSecondSortedArray2;
	if((endOfUserInput1-startOfUserInput1)%2 == 1){
		medianOfFirstSortedArray1 = sortedUserInput1[(endOfUserInput1-startOfUserInput1)/2];
	}else{
		medianOfFirstSortedArray1 = (sortedUserInput1((endOfUserInput1-startOfUserInput1)/2)+sortedUserInput1((endOfUserInput1-startOfUserInput1)/2+1))/2;
	}
	if((endOfUserInput2 - startOfUserInput1)%2 == 1){
		medianOfFirstSortedArray2 = sortedUserInput2[(endOfUserInput2-startOfUserInput2)/2];
	}else{
		medianOfFirstSortedArray2 = (sortedUserInput2((endOfUserInput2-startOfUserInput2)/2)+sortedUserInput2((endOfUserInput2-startOfUserInput2)/2+1))/2;
	}
	if(medianOfFirstSortedArray1 == medianOfSecondSortedArray2){
		return medianOfFirstSortedArray1;
	}
	if(medianOfFirstSortedArray1 > medianOfSecondSortedArray2){
		return MedianOfTwoSortedArraysByIndividualMedians(sortedUserInput1,startOfUserInput1,(endOfUserInput1-startOfUserInput1)/2,sortedUserInput2,(endOfUserInput2-startOfUserInput2)/2,endOfUserInput2);
	}else{
		return MedianOfTwoSortedArraysByIndividualMedians(sortedUserInput1,(endOfUserInput1-startOfUserInput1)/2,endOfUserInput1,sortedUserInput1,startOfUserInput2,(endOfUserInput2 - startOfUserInput2)/2);
	}
}



#endif /* MEDIANOFTWOSORTEDARRAYS_H_ */

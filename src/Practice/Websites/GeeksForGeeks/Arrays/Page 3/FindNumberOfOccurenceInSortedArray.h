/*
 * FindNumberOfOccurenceInSortedArray.h
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

#ifndef FINDNUMBEROFOCCURENCEINSORTEDARRAY_H_
#define FINDNUMBEROFOCCURENCEINSORTEDARRAY_H_

int FindNumberOfOccurenceInSortedArray(int userInput[],int sizeOfArray,int key){
	if(userInput == NULL ||  sizeOfArray == 0){
		return 0;
	}
	int occurenceCounter =0;
	for(int counter =0;counter < sizeOfArray;counter++){
		if(userInput[counter] == key){
			occurenceCounter++;
		}
	}
	return occurenceCounter;
}

int FindNumberOfOccurenceInSortedArray(int userInput[],int sizeOfArray,int key){
	if(userInput == NULL || sizeOfArray == 0){
		return 0;
	}
	hash_map<int,int> occurenceMap;
	hash_map<int,int>::iterator *itToOcccurenceMap;
	for(int counter =0;counter < sizeOfArray;counter++){
		if((itToOcccurenceMap = occurenceMap.find(userInput[counter])) != occurenceMap.end()){
			occurenceMap[userInput[counter]] += 1;
		}else{
			occurenceMap.insert(pair<int,int>(userInput[counter],1));
		}
	}
	return ((itToOcccurenceMap = occurenceMap.find(key))==occurenceMap.end()?0:(*itToOcccurenceMap)->second);
}

void FindNumberOfOccurenceInSortedArrayBinarySearch(int userInput[],int startIndex,int endIndex,int &minIndex,int &maxIndex,int key){
	if(startIndex > endIndex){
		return;
	}
	int middleIndex = (startIndex+endIndex)/2;
	if(userInput[middleIndex] == key){
		if(minIndex > middleIndex){
			minIndex = middleIndex;
		}
		if(maxIndex < middleIndex){
			maxIndex = middleIndex;
		}
		if(middleIndex-1 >= startIndex){
			FindNumberOfOccurenceInSortedArrayBinarySearch(userInput,startIndex,middleIndex-1,minIndex,maxIndex,key);
		}
		if(middleIndex +1 <= endIndex){
			FindNumberOfOccurenceInSortedArrayBinarySearch(userInput,middleIndex+1,endIndex,minIndex,maxIndex,key);
		}
	}else{
		if(userInput[middleIndex] > key){
			FindNumberOfOccurenceInSortedArrayBinarySearch(userInput,startIndex,middleIndex-1,minIndex,maxIndex,key);
		}else{
			FindNumberOfOccurenceInSortedArrayBinarySearch(userInput,middleIndex+1,endIndex,minIndex,maxIndex,key);
		}
	}
}

int FindNumberOfOccurenceInSortedArrayBinarySearchDriver(int userInput[],int sizeOfArray,int key){
	if(userInput == NULL || sizeOfArray == 0){
		return 0;
	}
	int startIndex=0,endIndex=0;
	FindNumberOfOccurenceInSortedArrayBinarySearch(userInput,0,sizeOfArray-1,startIndex,endIndex,key);
	return endIndex-startIndex+1;
}

#endif /* FINDNUMBEROFOCCURENCEINSORTEDARRAY_H_ */

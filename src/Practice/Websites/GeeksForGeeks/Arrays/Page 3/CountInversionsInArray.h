/*
 * CountInversionsInArray.h
 *
 *  Created on: Jun 18, 2013
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

#ifndef COUNTINVERSIONSINARRAY_H_
#define COUNTINVERSIONSINARRAY_H_

int FindNumberOfInversionsInArray(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return INT_MIN;
	}

	int outerCrawler = 0,innerCrawler;
	int numberOfInversions = 0;
	for(outerCrawler = 0;outerCrawler < sizeOfArray;outerCrawler++){
		for(innerCrawler = outerCrawler+1;innerCrawler < sizeOfArray;innerCrawler++){
			if(userInput[outerCrawler] < userInput[innerCrawler]){
				numberOfInversions += 1;
			}
		}
	}
	return numberOfInversions;
}

void InversionCountMainMerge(int userInput[],int startIndex,int middleIndex,int endIndex,int &inversionCount){
	int firstArrayCrawler = startIndex;
	int secondArrayCrawler = middleIndex+1;
	vector<int> tempForMerge;
	while(firstArrayCrawler <= middleIndex && secondArrayCrawler <= endIndex){
		if(userInput[firstArrayCrawler] < userInput[secondArrayCrawler]){
			tempForMerge.push_back(userInput[firstArrayCrawler]);
			firstArrayCrawler++;
		}else{
			tempForMerge.push_back(userInput[secondArrayCrawler]);
			secondArrayCrawler++;
			inversionCount += (middleIndex - firstArrayCrawler);
		}
	}
	while(firstArrayCrawler <= middleIndex){
		tempForMerge.push_back(userInput[firstArrayCrawler]);
		firstArrayCrawler++;
	}
	while(secondArrayCrawler <= endIndex){
		tempForMerge.push_back(userInput[secondArrayCrawler]);
		secondArrayCrawler++;
	}
	for(int counter =0,arrayCounter = startIndex;counter < tempForMerge.size();counter++,arrayCounter++){
		userInput[startIndex] = tempForMerge[counter];
	}
}

void FindInversionCountMerge(int userInput[],int startIndex,int endIndex,int &inversionCount){
	if(startIndex > endIndex){
		return;
	}
	int middleIndex = (startIndex + endIndex)/2;
	FindInversionCountMerge(userInput,startIndex,middleIndex,inversionCount);
	FindInversionCountMerge(userInput,middleIndex+1,endIndex,inversionCount);
	InversionCountMainMerge(userInput,startIndex,middleIndex,endIndex,inversionCount);
}

int InversionCountPlainSorting(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return 0;
	}
	vector<int> copyOfUserInput;
	for(int counter =0;counter < sizeOfArray;counter++){
		copyOfUserInput.push_back(userInput[counter]);
	}
	sort(copyOfUserInput.begin(),copyOfUserInput.end());
	hash_map<int,int> valueIndexMap;
	for(int counter = 0;counter < copyOfUserInput.size();counter++){
		valueIndexMap.insert(pair<int,int>(copyOfUserInput[counter],counter));
	}
	int inversionCounter = 0;
	for(int counter =0;counter < sizeOfArray;counter++){
		inversionCounter = abs(counter - valueIndexMap.find(userInput[counter]));
	}
	return inversionCounter;
}

#endif /* COUNTINVERSIONSINARRAY_H_ */

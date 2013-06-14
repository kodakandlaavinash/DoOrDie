/*
 * SortElementsByFrequency.h
 *
 *  Created on: Apr 26, 2013
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

#ifndef SORTELEMENTSBYFREQUENCY_H_
#define SORTELEMENTSBYFREQUENCY_H_

void SortElementsByFrequency(int userInput[],int sizeOfArray){
	struct auxDS{
		int value;
		int frequency;
	};
	hash_map<int,int> frequencyTable;
	hash_map<int,int>::iterator itToFrequencyTable;
	set<int> uniqueElements;
	set<int>::iterator itToUniqueElements;
	int numberOfUniqueElements = 0;
	int frequencyOfKey = -1;

	for(int counter=0;counter < sizeOfArray;counter++){
		if((itToFrequencyTable = frequencyTable.find(userInput[counter]))!=frequencyTable.end()){
			frequencyOfKey = itToFrequencyTable->second;
		}else{
			uniqueElements.insert(itToFrequencyTable->second);
			numberOfUniqueElements++;
		}
		frequencyTable[userInput[counter]] = ++frequencyOfKey;
	}

	auxDS arrayOfElements[numberOfUniqueElements];
	int crawlerToArray = -1;
	for(itToUniqueElements = uniqueElements.begin();itToFrequencyTable != uniqueElements.end();itToFrequencyTable++){
		arrayOfElements[++crawlerToArray].frequency = itToFrequencyTable->second;
		arrayOfElements[crawlerToArray].value = itToFrequencyTable->first;
	}

	//Sort Elements By Frequency and fill the inpur array
}

void sortElementsByFrequecyHashSort(int userInput[],int sizeOfArray){

}

#endif /* SORTELEMENTSBYFREQUENCY_H_ */

/*
 * FindSmallestMissingNumber.h
 *
 *  Created on: Aug 2, 2013
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

#ifndef FINDSMALLESTMISSINGNUMBER_H_
#define FINDSMALLESTMISSINGNUMBER_H_

int FindSmallestMissingNumber(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray ==0){
		return 1;
	}
	bool elementFound;
	for(int positiveCounter = 1;;positiveCounter++){
		elementFound = false;
		for(int counter = 0;counter < sizeOfArray;counter++){
			if(userInput[counter] == positiveCounter){
				elementFound = true;
				break;
			}
		}
		if(!elementFound){
			return positiveCounter;
		}
	}
}

/*
 * No duplicates
 */
int FindSmallestMissingNumber(int userInput[],int sizeOfArray){
	if(userInput == NULL ||  sizeOfArray == 0){
		return 1;
	}
	sort(userInput,userInput+sizeOfArray);

	int counter;
	while(userInput[counter] <= 0){
		counter++;
	}

	for(int counter = 1;counter < sizeOfArray;counter){
		if(userInput[counter] != counter){
			return counter;
		}
	}
}

int FindSmallestMissingNumberHashMap(int userInput[],int sizeOfArray){
	if(userInput == NULL ||  sizeOfArray == 0){
		return 1;
	}
	hash_map<int,int> existenceMap;
	for(int counter =0;counter < sizeOfArray;counter++){
		existenceMap.insert(pair<int,int>(userInput[counter],1));
	}

	hash_map<int,int>::iterator itToExistenceMap;
	for(int counter = 1;counter < sizeOfArray;counter++){
		if(existenceMap.find(counter) == existenceMap.end()){
			return counter;
		}
	}
}


#endif /* FINDSMALLESTMISSINGNUMBER_H_ */

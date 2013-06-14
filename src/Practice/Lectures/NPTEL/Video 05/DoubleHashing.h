/*
 * DoubleHashing.h
 *
 *  Created on: May 27, 2013
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

#ifndef DOUBLEHASHING_H_
#define DOUBLEHASHING_H_

#define DOUBLE_HASH_TABLE_SIZE 13
#define DOUBLE_HASH_INCREMENTS 8
int doubleHashingHashTable[DOUBLE_HASH_TABLE_SIZE];

int IncrementsForDoubleHashing(int key){
	return DOUBLE_HASH_INCREMENTS + (key %DOUBLE_HASH_INCREMENTS); // Adding default value so that the increment will never be equal to zero
}

int computeHashValueOfKey(int key){
	return key % DOUBLE_HASH_TABLE_SIZE;
}

void DoubleHashing(int userInput[],int sizeOfUserInput){
	int hashValueOfKey;
	int counter;
	for(int crawler =0;crawler < sizeOfUserInput;crawler++){
		hashValueOfKey = computeHashValueOfKey(userInput[crawler]);
		counter = 0;
		while(counter < DOUBLE_HASH_TABLE_SIZE){
			if(doubleHashingHashTable[hashValueOfKey] == 0){
				doubleHashingHashTable[hashValueOfKey] = userInput[crawler];
				break;
			}else{
				hashValueOfKey = (hashValueOfKey + IncrementsForDoubleHashing(hashValueOfKey))%DOUBLE_HASH_TABLE_SIZE;
			}
			counter++;
		}
		if(counter == DOUBLE_HASH_TABLE_SIZE){
			printf("HASH TABLE IS FULL");
			return;
		}
	}
}

bool searchForElement(int key){
	int hashValueOfKey = computeHashValueOfKey(key);
	while(doubleHashingHashTable[hashValueOfKey] != 0){
		if(doubleHashingHashTable[hashValueOfKey] == key){
			return true;
		}else{
			hashValueOfKey = (hashValueOfKey+IncrementsForDoubleHashing(hashValueOfKey))%DOUBLE_HASH_TABLE_SIZE;
		}
	}
	return false;
}

void deleteAKeyInDoubleHashing(int key){
	int hashValueOfKey = computeHashValueOfKey(key);
	while(doubleHashingHashTable[hashValueOfKey] != 0){
		if(doubleHashingHashTable[hashValueOfKey] == key){
			doubleHashingHashTable[hashValueOfKey] = 0;
			return;
		}else{
			hashValueOfKey = (hashValueOfKey+IncrementsForDoubleHashing(hashValueOfKey))%DOUBLE_HASH_TABLE_SIZE;
		}
	}
	return;
}

#endif /* DOUBLEHASHING_H_ */

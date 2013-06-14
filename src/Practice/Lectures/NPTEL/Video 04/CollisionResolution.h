/*
 * CollisionResolution.h
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

#ifndef COLLISIONRESOLUTION_H_
#define COLLISIONRESOLUTION_H_

struct hashNode{
	int value;
	hashNode *next;
};

#define HASH_TABLE_SIZE 20
hashNode *hashTable[HASH_TABLE_SIZE];
void ComputeHashValue(int key,int hashTableSize){
	return key % hashTableSize;
}

void HasingUsingChaining(int userInput[],int sizeOfUserInput){
	int hashValueOfKey;
	hashNode *newNode;
	for(int crawler = 0;crawler < sizeOfUserInput;crawler++){
		hashValueOfKey = ComputeHashValue(userInput[crawler],HASH_TABLE_SIZE);
		newNode = (hashNode *)malloc(sizeof(hashNode));
		newNode->value = userInput[crawler];
		newNode->next = NULL;
		if(hashTable[hashValueOfKey] == NULL){
			hashTable[hashValueOfKey] = newNode;
		}else{
			newNode->next = hashTable[hashValueOfKey];
			hashTable[hashValueOfKey] = newNode;
		}
	}
}

bool searchForElementInChaining(int key){
	int hashValueOfKey = ComputeHashValue(key,HASH_TABLE_SIZE);
	hashNode *crawler = hashTable[hashValueOfKey];
	while(crawler != NULL){
		if(crawler->value == key){
			return true;
		}
		crawler = crawler->next;
	}
	return false;
}

void deletionOfElementInChaining(int key){
	/**
	 * Its very similar to deletion of a node in the linked list
	 */
}

#endif /* COLLISIONRESOLUTION_H_ */

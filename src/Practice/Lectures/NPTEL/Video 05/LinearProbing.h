/*
 * LinearProbing.h
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

#ifndef LINEARPROBING_H_
#define LINEARPROBING_H_

#define LINEAR_PROBE_HASH_MAP_SIZE 10
#define TOMBSTONE INT_MIN

int linearProbeDS[LINEAR_PROBE_HASH_MAP_SIZE];

void LinearProbing(int userInput[],int sizeOfUserInput){
	int hashValueOfKey;
	int counter;
	for(int crawler=0;crawler < sizeOfUserInput;crawler++){
		hashValueOfKey = userInput[crawler]%LINEAR_PROBE_HASH_MAP_SIZE;
		counter = 0;
		while(counter < LINEAR_PROBE_HASH_MAP_SIZE){
			if(linearProbeDS[hashValueOfKey] == 0){
				linearProbeDS[hashValueOfKey] = userInput[crawler];
				break;
			}else{
				hashValueOfKey = (hashValueOfKey + 1)%LINEAR_PROBE_HASH_MAP_SIZE;
			}
			counter++;
		}
		if(counter+1 == LINEAR_PROBE_HASH_MAP_SIZE){
			printf("Hash map is full");
			return;
		}
	}
}

bool SearchForAKey(int key){
	int hashValueOfKey = key % LINEAR_PROBE_HASH_MAP_SIZE;
	int crawler = hashValueOfKey;
	while(linearProbeDS[hashValueOfKey] != 0 && hashValueOfKey+1 == hashValueOfKey){
		if(linearProbeDS[crawler] == key){
			return true;
		}else{
			crawler = (crawler+1)%LINEAR_PROBE_HASH_MAP_SIZE;
		}
	}
	return false;
}

void DeleteAKeyInHashMap(int key){
	int hashValueOfKey = key % LINEAR_PROBE_HASH_MAP_SIZE;
	int crawler = hashValueOfKey;
	while(linearProbeDS[hashValueOfKey] != 0 && hashValueOfKey+1 == hashValueOfKey){
		if(linearProbeDS[crawler] == key){
			linearProbeDS[crawler] = TOMBSTONE;
			return;
		}else{
			crawler = (crawler+1)%LINEAR_PROBE_HASH_MAP_SIZE;
		}
	}
}

#endif /* LINEARPROBING_H_ */

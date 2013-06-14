/*
 * UnorderedDictionary.cpp
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

#include "UnorderedDictionary.h"

UnorderedDictionary::UnorderedDictionary() {
	// TODO Auto-generated constructor stub

}

UnorderedDictionary::UnorderedDictionary(int sizeOfDictionary){
	this->size = sizeOfDictionary;
}

UnorderedDictionary::~UnorderedDictionary() {
	// TODO Auto-generated destructor stub
}

void UnorderedDictionary::addKeyToDictionary(int key){
	dictionary[tail]=key;
	tail++;
}

void UnorderedDictionary::deleteKeyFromDictionary(int key){
	int index = searchKeyFromDictionary(key);
	while(index < tail-1){
		dictionary[index] = dictionary[index+1];
		index++;
	}
	dictionary[index] = 0;
	tail--;
}

bool UnorderedDictionary::doesKeyExistsInDictionary(int key){
	for(int counter =0;counter < tail;counter++){
		if(dictionary[counter] == key){
			return true;
		}
	}
	return false;
}

int UnorderedDictionary::searchKeyFromDictionary(int key){
	for(int counter =0;counter < tail;counter++){
		if(dictionary[counter] == key){
			return counter;
		}
	}
	return INT_MIN;
}

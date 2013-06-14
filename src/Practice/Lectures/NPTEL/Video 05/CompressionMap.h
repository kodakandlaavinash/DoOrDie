/*
 * CompressionMap.h
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

#ifndef COMPRESSIONMAP_H_
#define COMPRESSIONMAP_H_

int FindHashValue(int key,int sizeOfTable){
	return key%sizeOfTable;
}

int FindHashValueStrategy2(int key,int sizeOfTable){
	double fractionalValue = (sqrt(key)-1)/2;
	return floor(sizeOfTable*(key * fractionalValue));
}

int FindHashValueMAD(int key,int sizeOfTable){
	int aValue,bValue;
	return ((aValue*key)+bValue)%sizeOfTable;
}

int UniversalHashing(int key,int sizeOfTable){
	static int hashFunctionToBeApplied;
	if(!hashFunctionToBeApplied){
		hashFunctionToBeApplied = GenerateRandomNumber();
	}
	return hashValue(hashFunctionToBeApplied,key,sizeOfTable);
}

int UniversalHashValue(int hashFunctionToBeApplied,int key,int sizeOfTable){
	switch (hashFunctionToBeApplied) {
	case 1:
		return FindHashValue(key,sizeOfTable);
	case 2:
		return FindHashValueStrategy2(key,sizeOfTable);
	case 3:
		return FindHashValueMAD(key,sizeOfTable);
	}
}

int GenerateRandomNumber(){
	return rand()%3 + 1;
}
#endif /* COMPRESSIONMAP_H_ */

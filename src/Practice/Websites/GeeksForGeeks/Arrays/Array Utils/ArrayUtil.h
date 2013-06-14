/*
 * ArrayUtil.h
 *
 *  Created on: May 7, 2013
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

#ifndef ARRAYUTIL_H_
#define ARRAYUTIL_H_

/**
 * Tested
 */
void PrintArray(int userInput[],int sizeOfArray){
	for(int crawler = 0;crawler < sizeOfArray;crawler++){
		printf("%d\t",userInput[crawler]);
	}
}

/**
 * Tested
 */
void PrintHashMap(hash_map<int,int> mapOfIntToInt){
	hash_map<int,int>::iterator itToMapOfIntToInt;
	for(itToMapOfIntToInt = mapOfIntToInt.begin();itToMapOfIntToInt != mapOfIntToInt.end();itToMapOfIntToInt++){
		printf("Key = %d Value = %d\n",itToMapOfIntToInt->first,itToMapOfIntToInt->second);
	}
	printf("END OF PRINTING\n");
	return;
}
#endif /* ARRAYUTIL_H_ */

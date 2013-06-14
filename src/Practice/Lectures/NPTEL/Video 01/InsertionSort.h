/*
 * InsertionSort.h
 *
 *  Created on: May 20, 2013
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

#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_

void SortElementsByInsertionSort(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return;
	}

	int outerCrawler = 1;
	int innerCrawler = 0;
	int key;
	for(outerCrawler = 1;outerCrawler < sizeOfArray;outerCrawler++){
		key = userInput[outerCrawler];
		while(key < userInput[innerCrawler]){
			userInput[innerCrawler+1] = userInput[innerCrawler];
			innerCrawler--;
		}
		userInput[innerCrawler+1] = key;
	}
}

#endif /* INSERTIONSORT_H_ */

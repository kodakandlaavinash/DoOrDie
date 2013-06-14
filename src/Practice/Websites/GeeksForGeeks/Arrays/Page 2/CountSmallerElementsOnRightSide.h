/*
 * CountSmallerElementsOnRightSide.h
 *
 *  Created on: May 23, 2013
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

#ifndef COUNTSMALLERELEMENTSONRIGHTSIDE_H_
#define COUNTSMALLERELEMENTSONRIGHTSIDE_H_

vector<int> CountSmallerElementsOnRightSide(int userInput[],int sizeOfUserInput){
	if(sizeOfUserInput == 0){
		return NULL;
	}
	vector<int> smallerElementsCounter;
	int outerCrawler,innerCrawler,counter;
	for(outerCrawler =0;outerCrawler < sizeOfUserInput;outerCrawler++){
		counter = 0;
		for(innerCrawler = outerCrawler+1;innerCrawler < sizeOfUserInput;outerCrawler++){
			if(userInput[innerCrawler] < userInput[outerCrawler]){
				counter++;
			}
		}
		smallerElementsCounter.push_back(counter);
	}
	return smallerElementsCounter;
}

#endif /* COUNTSMALLERELEMENTSONRIGHTSIDE_H_ */

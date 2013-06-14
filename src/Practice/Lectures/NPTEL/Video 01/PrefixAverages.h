/*
 * Averages.h
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

#ifndef AVERAGES_H_
#define AVERAGES_H_

vector<int> FindPrefixAveragesON2(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return NULL;
	}
	vector<float> prefixAverages;
	int outerCrawler,innerCrawler;
	int sumOfElements;
	for(outerCrawler=0;outerCrawler < sizeOfArray;outerCrawler++){
		sumOfElements = 0;
		for(innerCrawler = 0;innerCrawler <= outerCrawler;innerCrawler++){
			sumOfElements += userInput[innerCrawler];
		}
		prefixAverages.push_back(sumOfElements/(outerCrawler+1));
	}
	return prefixAverages;
}

vector<int> FindPrefixAveragesON(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return NULL;
	}

	int crawler =0;
	int runningSum = 0;
	vector<float> prefixAverages;
	for(crawler = 0;crawler < sizeOfArray;crawler++){
		runningSum += userInput[crawler];
		prefixAverages.insert(runningSum/(crawler+1));
	}
	return prefixAverages;
}

#endif /* AVERAGES_H_ */

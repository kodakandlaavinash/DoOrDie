/*
 * BucketSort.h
 *
 *  Created on: Jun 17, 2013
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

#ifndef BUCKETSORT_H_
#define BUCKETSORT_H_

void SortUsingBuckets(int &userInput[],int sizeOfArray,int minValue,int maxValue){
	if(sizeOfArray == 0){
		return;
	}
	vector<int> buckets[maxValue - minValue+1];
	for(int crawler =0;crawler < sizeOfArray;crawler++){
		buckets[userInput[crawler]].push_back(userInput[crawler]);
	}

	int fillCounter = -1;
	for(int crawler =0;crawler < maxValue-minValue+1;crawler++){
		for(int innerCrawler =0;innerCrawler < buckets[crawler].size();innerCrawler++){
			userInput[++fillCounter] = crawler;
		}
	}
}

#endif /* BUCKETSORT_H_ */

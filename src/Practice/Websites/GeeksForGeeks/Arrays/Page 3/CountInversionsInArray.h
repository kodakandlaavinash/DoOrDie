/*
 * CountInversionsInArray.h
 *
 *  Created on: Jun 18, 2013
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

#ifndef COUNTINVERSIONSINARRAY_H_
#define COUNTINVERSIONSINARRAY_H_

int FindNumberOfInversionsInArray(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return INT_MIN;
	}

	int outerCrawler = 0,innerCrawler;
	int numberOfInversions = 0;
	for(outerCrawler = 0;outerCrawler < sizeOfArray;outerCrawler++){
		for(innerCrawler = outerCrawler+1;innerCrawler < sizeOfArray;innerCrawler++){
			if(userInput[outerCrawler] < userInput[innerCrawler]){
				numberOfInversions += 1;
			}
		}
	}
	return numberOfInversions;
}

#endif /* COUNTINVERSIONSINARRAY_H_ */

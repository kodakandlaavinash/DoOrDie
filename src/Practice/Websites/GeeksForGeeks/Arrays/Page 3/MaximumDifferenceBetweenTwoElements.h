/*
 * MaximumDifferenceBetweenTwoElements.h
 *
 *  Created on: May 15, 2013
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

#ifndef MAXIMUMDIFFERENCEBETWEENTWOELEMENTS_H_
#define MAXIMUMDIFFERENCEBETWEENTWOELEMENTS_H_

int MaximumDifferenceBetweenTwoElements(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return INT_MAX;
	}

	int outerCrawler,innerCrawler;
	int maxDifference = INT_MIN,difference;
	for(outerCrawler =0;outerCrawler < sizeOfArray;outerCrawler++){
		for(innerCrawler = outerCrawler+1;innerCrawler< sizeOfArray;innerCrawler++){
			difference = userInput[innerCrawler] - userInput[outerCrawler];
			if(difference > maxDifference){
				maxDifference = difference;
			}
		}
	}
	return maxDifference;
}


int MaximumDifferenceBetweenTwoElementsByMinTrack(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return INT_MAX;
	}

	int max_difference = INT_MIN;
	int min_element = userInput[0];

	for(int crawler = 1;crawler < sizeOfArray;crawler++){
		if(userInput[crawler] - min_element > max_difference){
			max_difference = userInput[crawler] - min_element;
		}
		if(min_element > userInput[crawler]){
			min_element = userInput[crawler];
		}
	}
	return max_difference;
}



#endif /* MAXIMUMDIFFERENCEBETWEENTWOELEMENTS_H_ */

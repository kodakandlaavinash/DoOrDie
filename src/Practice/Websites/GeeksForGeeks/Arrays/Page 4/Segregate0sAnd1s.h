/*
 * Segregate0sAnd1s.h
 *
 *  Created on: Apr 30, 2013
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

#ifndef SEGREGATE0SAND1S_H_
#define SEGREGATE0SAND1S_H_

/**
 * Tested
 */
void SegregateZerosAndOnesON(int userInput[],int sizeOfArray){
	int forwardCrawler = 0;
	int backwardCrawler = sizeOfArray-1;
	while(forwardCrawler < backwardCrawler){
		while(userInput[forwardCrawler] != 1){
			forwardCrawler++;
		}
		while(userInput[backwardCrawler] != 0){
			backwardCrawler--;
		}
		if(forwardCrawler < backwardCrawler){
			userInput[forwardCrawler] = 0;
			userInput[backwardCrawler] = 1;
		}
	}
}

void SegregateZerosAndOnesON2(int userInput[],int sizeOfArray){

}

/**
 * Tested
 */
void SegregateZerosAndOnesCounter(int userInput[],int sizeOfArray){
	int zeroCounter=0,oneCounter = 0;
	int crawler;
	for(crawler = 0;crawler < sizeOfArray;crawler++){
		if(userInput[crawler] == 0){
			zeroCounter++;
		}
		if(userInput[crawler] == 1){
			oneCounter++;
		}
	}
	int runner=-1;
	while(zeroCounter--){
		userInput[++runner] = 0;
	}
	while(oneCounter--){
		userInput[++runner] = 1;
	}
}

#endif /* SEGREGATE0SAND1S_H_ */

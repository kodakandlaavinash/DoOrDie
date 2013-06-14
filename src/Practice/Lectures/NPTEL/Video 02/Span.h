/*
 * Span.h
 *
 *  Created on: May 21, 2013
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

#ifndef SPAN_H_
#define SPAN_H_

vector<int> CalculateSpanForStocksON2(int userInput[],int sizeOfUserInput){
	if(sizeOfUserInput == 0){
		return NULL;
	}

	int outerCrawler;
	int innerCrawler;
	vector<int> spanForStocks;
	spanForStocks.push_back(-1);
	int span = 0;
	for(outerCrawler = 1;outerCrawler < sizeOfUserInput;outerCrawler++){
		span = 0;
		for(innerCrawler=outerCrawler;innerCrawler >= 0;innerCrawler++){
			if(userInput[innerCrawler] <= userInput[outerCrawler]){
				span+=1;
			}
		}
		spanForStocks.push_back(span);
	}

	return spanForStocks;
}

vector<int> CalculateSpanUsingStack(int userInput[],int sizeOfUserInput){
	if(sizeOfUserInput == 0){
		return NULL;
	}
	stack<int> auxSpace;
	vector<int> spanForStocks;
	auxSpace.push(userInput[0]);
	int tempCounter;
	for(int counter =0;counter<sizeOfUserInput;counter++){
		if(auxSpace.top() > userInput[counter]){
			spanForStocks.push_back(1);
			auxSpace.push(userInput[counter]);
		}else{
			tempCounter = 0;
			while(auxSpace.top() > userInput[counter]){
				auxSpace.pop();
				tempCounter += 1;
			}
			spanForStocks.push_back(tempCounter);
			auxSpace.push(userInput[counter]);
		}
	}
	return spanForStocks;
}

#endif /* SPAN_H_ */

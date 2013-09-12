/*
 * AND.h
 *
 *  Created on: Sep 9, 2013
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

#ifndef AND_H_
#define AND_H_

int ANDOperation(vector<int> userInput){
	if(userInput == NULL || userInput.size() == 0){
		return 0;
	}
	int outerCrawler,innerCrawler,size = userInput.size(),result;
	int temp;
	for(outerCrawler =0;outerCrawler < size;outerCrawler++){
		for(innerCrawler = outerCrawler+1;innerCrawler < size;innerCrawler++){
			temp = userInput[outerCrawler] && userInput[innerCrawler];
			result = result + temp;
		}
	}
	return result;
}

int main(){
	//int noOfTestCases;
	//scanf("%d",&noOfTestCases);
	int inputSize,input;
	vector<int> userInput;
	//while(noOfTestCases--){
	scanf("%d",&inputSize);
	userInput.clear();
	while(inputSize--){
		scanf("%d",&input);
		userInput.push_back(input);
	}
	printf("%d",ANDOperation(userInput));
	//}
}

#endif /* AND_H_ */

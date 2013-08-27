/*
 * ParityOfUnsignedInteger.h
 *
 *  Created on: Aug 27, 2013
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

#ifndef PARITYOFUNSIGNEDINTEGER_H_
#define PARITYOFUNSIGNEDINTEGER_H_

bool CheckParityOfUnsignedInteger(unsigned int userInput){
	bool parityFlag = false;
	while(userInput){
		if(userInput&1){
			parityFlag = !parityFlag;
		}
		userInput = userInput >> 1;
	}
	return parityFlag;
}

bool CheckParityByGettingRightMostBit(unsigned int userInput){
	bool parityFlag = false;
	while(userInput){
		parityFlag = !parityFlag;
		userInput = (userInput & (userInput-1));
	}
	return parityFlag;
}

#endif /* PARITYOFUNSIGNEDINTEGER_H_ */

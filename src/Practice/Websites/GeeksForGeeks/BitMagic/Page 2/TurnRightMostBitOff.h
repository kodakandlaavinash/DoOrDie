/*
 * TurnRightMostBitOff.h
 *
 *  Created on: Aug 28, 2013
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

#ifndef TURNRIGHTMOSTBITOFF_H_
#define TURNRIGHTMOSTBITOFF_H_

int TurnRightMostBitOff(int userInput){
	return userInput & (userInput - 1);
}

int TurnRightMostBitOffIteration(int userInput){
	int counter = 0;
	while(userInput%2 != 1){
		counter++;
	}
	return (userInput ^ 1) << counter;
}


#endif /* TURNRIGHTMOSTBITOFF_H_ */

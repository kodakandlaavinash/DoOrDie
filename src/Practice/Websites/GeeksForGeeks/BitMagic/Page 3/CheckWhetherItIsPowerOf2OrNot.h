/*
 * CheckWhetherItIsPowerOf2OrNot.h
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

#ifndef CHECKWHETHERITISPOWEROF2ORNOT_H_
#define CHECKWHETHERITISPOWEROF2ORNOT_H_

bool CheckWhetherGivenNumberIsPowerOf2OrNot(int userInput){
	return n&&!(n & (n-1));
}

bool CheckWhetherGivenNumberIsPowerOf2OrNot(int userInput){
	int counter = 0;
	while(userInput){
		counter++;
		userInput = userInput & userInput-1;
	}
	return counter == 1?true:false;
}

#endif /* CHECKWHETHERITISPOWEROF2ORNOT_H_ */

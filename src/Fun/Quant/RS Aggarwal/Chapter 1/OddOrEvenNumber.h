/*
 * OddOrEvenNumber.h
 *
 *  Created on: May 14, 2013
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

#include "DivisibilityRules.h"
using namespace std;
using namespace __gnu_cxx;

#define null NULL
#define PRINT_NEW_LINE printf("\n")
//int main(){
//	return -1;
//}

#ifndef ODDOREVENNUMBER_H_
#define ODDOREVENNUMBER_H_

void CheckWhetherANumberIsOddOrNot(int userInput){
	if(CheckWhetherANumberIsDivisibleBy2OrNot(userInput)){
		return false;
	}else{
		return true;
	}
}

void CheckWhetherANumberIsOddOrNotBitwise(int userInput){
	return userInput&&1?true:false;
}

#endif /* ODDOREVENNUMBER_H_ */

/*
 * FindANumberOccuringOddNumber.h
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

#ifndef FINDANUMBEROCCURINGODDNUMBER_H_
#define FINDANUMBEROCCURINGODDNUMBER_H_

int FindANumberOccuringOddNumberOfTimes(int userInput[],int sizeOfArray){
	int XORResult = 0;
	for(int counter = 0;counter < sizeOfArray;counter++){
		XORResult ^= userInput[counter];
	}
	return XORResult;
}


#endif /* FINDANUMBEROCCURINGODDNUMBER_H_ */

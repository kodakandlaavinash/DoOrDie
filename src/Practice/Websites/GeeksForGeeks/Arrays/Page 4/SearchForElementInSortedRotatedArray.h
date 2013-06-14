/*
 * SearchForElementInSortedRotatedArray.h
 *
 *  Created on: Apr 24, 2013
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

#ifndef SEARCHFORELEMENTINSORTEDROTATEDARRAY_H_
#define SEARCHFORELEMENTINSORTEDROTATEDARRAY_H_

int FindPivotInSortedRotatedArray(int userInput[],int startIndex,int endIndex){
	if(startIndex < endIndex){
		return INT_MIN;
	}
	int middleIndex = (endIndex - startIndex)/2;
	if(userInput[middleIndex] > userInput[middleIndex+1] && userInput[middleIndex] > userInput[middleIndex-1]){
		return middleIndex;
	}


}

#endif /* SEARCHFORELEMENTINSORTEDROTATEDARRAY_H_ */

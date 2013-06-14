/*
 * IntersectionOfTwoSortedArrays.h
 *
 *  Created on: Apr 29, 2013
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

#ifndef INTERSECTIONOFTWOSORTEDARRAYS_H_
#define INTERSECTIONOFTWOSORTEDARRAYS_H_

vector<int> IntersectionOfTwoSortedArray(int userInput1[],int sizeOfArray1,int userInput2[],int sizeOfArray2){
	if(sizeOfArray1 == 0 || sizeOfArray2 == 0){
		return NULL;
	}

	int crawler1=0,crawler2=0;
	vector<int> intersectionOfArrays;
	while(crawler1 >= 0 && crawler2 >= 0){
		if(userInput1[crawler1] == userInput2[crawler2]){
			intersectionOfArrays.push_back(userInput1[crawler1]);
		}else{
			if(userInput1[crawler1] > userInput2[crawler2]){
				crawler2++;
			}else{
				crawler1++;
			}
		}
	}
}

#endif /* INTERSECTIONOFTWOSORTEDARRAYS_H_ */

/*
 * SortArrayOf0s1s2s.h
 *
 *  Created on: Jul 29, 2013
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

#ifndef SORTARRAYOF0S1S2S_H_
#define SORTARRAYOF0S1S2S_H_

void SortArrayOf0s1s2sON(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return;
	}
	int buckets[3] = {0};
	for(int counter =0;counter < sizeOfArray;counter++){
		switch (userInput[counter]) {
			case 0:
				buckets[0]++;
				break;
			case 1:
				buckets[1]++;
				break;
			case 2:
				buckets[2]++;
				break;
		}
	}
	for(int counter =0;counter < 3;counter++){
		if(buckets[0]>0){
			userInput[counter] = 0;
		}else if(buckets[1] > 0){
			userInput[counter] = 1;
		}else if(buckets[2] > 0){
			userInput[counter] = 2;
		}
	}
}

void SortArrayOf0s1s2sONLOGN(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return;
	}
	sort(userInput,userInput+sizeOfArray);
}

#endif /* SORTARRAYOF0S1S2S_H_ */

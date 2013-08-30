/*
 * AddOneToArrayAndIncreaseSize.h
 *
 *  Created on: Aug 30, 2013
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

#ifndef ADDONETOARRAYANDINCREASESIZE_H_
#define ADDONETOARRAYANDINCREASESIZE_H_

int *AddOneToArrayNaiveMethod(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	int *result = (int *)calloc(sizeOfArray,sizeof(int));
	int carry = 1,sum;
	for(int counter = sizeOfArray-1;counter >=0&&carry>0;counter--){
		sum = userInput[counter] + carry;
		result[counter] = sum%10;
		carry = sum/10;
	}
	if(carry > 0){
		//Allocating only one extra int ... because the max sum can be 18 (9+9) even in that
		//case only one integer can be in carry
		result = (int *)realloc(result,sizeOfArray+1*sizeof(int));
		for(int counter = sizeOfArray;counter >0;counter--){
			result[counter] = result[counter-1];
		}
		result[0] = carry;
	}

	return result;
}

int *AddOneToArrayPreAllocateMemory(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	int *result = (int *)calloc(sizeOfArray+1,sizeof(int));
	int carry = 1,sum;
	for(int counter = sizeOfArray-1;counter >= 0 && carry > 0;counter--){
		sum = userInput[counter] + carry;
		result[counter - sizeOfArray +1] = sum%10;
		carry = sum/10;
	}
	if(carry > 0){
		result[sizeOfArray] =carry;
		ReverseArrayAuxSpace(result,sizeOfArray+1);
	}else{
		result = (int *)realloc(sizeOfArray*sizeof(int));
		ReverseArrayAuxSpace(result,sizeOfArray);
	}
	return result;
}

#endif /* ADDONETOARRAYANDINCREASESIZE_H_ */

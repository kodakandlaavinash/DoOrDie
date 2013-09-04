/*
 * ProductWithoutDivisionOperator.h
 *	http://www.careercup.com/question?id=5436643691462656
 *  Created on: Sep 4, 2013
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

#ifndef PRODUCTWITHOUTDIVISIONOPERATOR_H_
#define PRODUCTWITHOUTDIVISIONOPERATOR_H_

int *ProductArrayWithoutDivisionOperator(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	int *productArray = (int *)calloc(sizeOfArray,sizeof(int));
	productArray[0] = 1;
	for(int counter = 1;counter < sizeOfArray;counter++){
		productArray[counter] = productArray[counter-1]*userInput[counter-1];
	}
	int productFromRight = 1;
	for(int counter = sizeOfArray-2;counter>=0;counter++){
		productFromRight *= userInput[counter+1];
		productArray[counter] *= productFromRight;
	}
	return productArray;
}

int *ProductArrayWithoutDivisionOperatorON2(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	int *productArray = (int *)calloc(sizeOfArray,sizeof(int));
	int productFromLeft,productFromRight;
	for(int counter = 0;counter <= sizeOfArray;counter++){
		productFromLeft = 1;productFromRight = 1;
		for(int leftCounter = 0;leftCounter < counter;leftCounter++){
			productFromLeft *= userInput[leftCounter];
		}
		for(int rightCounter = counter+1;rightCounter < sizeOfArray;rightCounter++){
			productFromRight *= userInput[rightCounter];
		}
		productArray[counter] = productFromLeft*productFromRight;
	}
	return productArray;
}

#endif /* PRODUCTWITHOUTDIVISIONOPERATOR_H_ */

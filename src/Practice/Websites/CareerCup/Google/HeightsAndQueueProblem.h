/*
 * HeightsAndQueueProblem.h
 *	http://www.careercup.com/question?id=24532662
 *  Created on: Aug 23, 2013
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

#ifndef HEIGHTSANDQUEUEPROBLEM_H_
#define HEIGHTSANDQUEUEPROBLEM_H_

struct indexValue{
	int value;
	int index;
};

void HeightsAndQueueProblem(int heights[],int noOfPersonsAhead[],int sizeOfArray){
	if(heights == NULL || noOfPersonsAhead == NULL || sizeOfArray == 0){
		return;
	}
	int outerCounter = 0,innerCounter = 0;
	int auxSpace[sizeOfArray];
	for(outerCounter = 0;outerCounter < sizeOfArray;outerCounter++){

	}
}


#endif /* HEIGHTSANDQUEUEPROBLEM_H_ */

/*
 * ImplementTwoStacksInGivenArray.h
 *
 *  Created on: Jul 30, 2013
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

#ifndef IMPLEMENTTWOSTACKSINGIVENARRAY_H_
#define IMPLEMENTTWOSTACKSINGIVENARRAY_H_

#define SIZE_OF_ARRAY_FOR_TWO_STACKS 100

int topStack1 = -1;
int topStack2 = SIZE_OF_ARRAY_FOR_TWO_STACKS;
int arrayForStacks[SIZE_OF_ARRAY_FOR_TWO_STACKS];

void InsertAnElement(bool ontoStack1,int value){
	if(abs(topStack1 - topStack2) == 1){
		printf("ARRAY IS FULL");
		return;
	}
	if(ontoStack1){
		arrayForStacks[++topStack1] = value;
	}else{
		arrayForStacks[--topStack2] = value;
	}
}

int topElement(bool fromStack1){
	if(fromStack1){
		if(topStack1 == -1){
			printf("Stack 1 is empty");
			return;
		}
		return arrayForStacks[topStack1];
	}else{
		if(topStack2 == SIZE_OF_ARRAY_FOR_TWO_STACKS){
			printf("Stack 2 is empty");
			return;
		}
		return arrayForStacks[topStack2];
	}
}

void pop(bool fromStack1){
	if(fromStack1){
		if(topStack1 == -1){
			printf("Stack 1 is empty");
			return;
		}
		arrayForStacks[topStack1]=0;
		topStack1--;
	}else{
		if(topStack2 == SIZE_OF_ARRAY_FOR_TWO_STACKS){
			printf("Stack 2 is empty");
			return;
		}
		arrayForStacks[topStack2] = 0;
		topStack2++;
	}
}

int sizeOfStack(bool forStack1){
	if(forStack1){
		return topStack1+1;
	}else {
		return topStack2-SIZE_OF_ARRAY_FOR_TWO_STACKS;
	}
}

bool isEmpty(bool forStack1){
	if(fromStack1){
		if(topStack1 == -1){
			return true;
		}
	}else{
		if(topStack2 == SIZE_OF_ARRAY_FOR_TWO_STACKS){
			return true;
		}
	}
	return false;
}

#endif /* IMPLEMENTTWOSTACKSINGIVENARRAY_H_ */

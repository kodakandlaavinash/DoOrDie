/*
 * CheckForSmallEndianOrBigEndian.h
 *
 *  Created on: Aug 28, 2013
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

#ifndef CHECKFORSMALLENDIANORBIGENDIAN_H_
#define CHECKFORSMALLENDIANORBIGENDIAN_H_

bool IsMachineBigOrSmallEndian(){
	unsigned int one = 1;
	char *pointerToUnsignedInt = (char *)&one;
	if(*c){
		printf("Little Endian");
	}else{
		printf("Big Endian");
	}
}

void PrintMemoryLayout(int userInput){
	char *ptrToUserInput = (char *)&userInput;
	for(int counter = 0;counter < sizeof(int);counter++){
		printf("%d ",*ptrToUserInput);
		ptrToUserInput++;
	}
}

#endif /* CHECKFORSMALLENDIANORBIGENDIAN_H_ */

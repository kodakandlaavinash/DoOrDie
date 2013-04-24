/*
 * CommonUtils.h
 *
 *  Created on: Apr 22, 2013
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

#ifndef COMMONUTILS_H_
#define COMMONUTILS_H_

void PrintStackContents(stack<tNode *> auxSpace){
	tNode *currentNode;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		printf("%d\t",currentNode->value);
		auxSpace.pop();
	}
	PRINT_NEW_LINE;
}

void PrintVectorContents(vector<tNode *> auxSpace){
	vector<tNode *>::iterator itToInputVector;
	for(itToInputVector = auxSpace.begin();itToInputVector != auxSpace.end();itToInputVector++){
		if((*itToInputVector) != NULL){
			printf("%d\t",(*itToInputVector)->value);
		}else{
			printf("NULL");
		}
	}
}

#endif /* COMMONUTILS_H_ */

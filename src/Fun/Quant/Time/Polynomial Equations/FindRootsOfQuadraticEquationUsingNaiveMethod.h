/*
 * FindRootsOfQuadraticEquationUsingNaiveMethod.h
 *
 *  Created on: Jun 12, 2013
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

struct quadraticEquation{
	int x2CoEfficient;
	int xCoEfficient;
	int constant;
};

struct complexRoots{
	int realPart;
	int imaginaryPart;
};

#ifndef FINDROOTSOFQUADRATICEQUATIONUSINGNAIVEMETHOD_H_
#define FINDROOTSOFQUADRATICEQUATIONUSINGNAIVEMETHOD_H_

complexRoots *GetRootsOfQuadraticEquation(quadraticEquation *userInput){
	if(userInput == NULL){
		return NULL;
	}

	int productOfCoefficient = userInput->x2CoEfficient * userInput->constant;
	if(productOfCoefficient < 0){

	}else{

	}
}

#endif /* FINDROOTSOFQUADRATICEQUATIONUSINGNAIVEMETHOD_H_ */

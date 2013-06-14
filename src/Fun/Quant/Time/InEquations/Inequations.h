/*
 * Inequations.h
 *
 *  Created on: Jun 13, 2013
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

#ifndef INEQUATIONS_H_
#define INEQUATIONS_H_

int GreatestAmongTwoNumbers(int firstUserInput,int secondUserInput){
	return firstUserInput - secondUserInput > 0?firstUserInput:secondUserInput;
}

void AllPossibleInequalitiesWithKConstant(int firstUserInput,int secondUserInput,int k){
	if(k == 0){
		printf("This makes both of them equal except for certain cases");
		return;
	}
	if(k > 0){
		if(a > b){

		}else{

		}
	}else{

	}
}
#endif /* INEQUATIONS_H_ */

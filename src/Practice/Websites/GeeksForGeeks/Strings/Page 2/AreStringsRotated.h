/*
 * AreStringsRotated.h
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

#ifndef ARESTRINGSROTATED_H_
#define ARESTRINGSROTATED_H_

bool AreStringsRotated(char *inputString1,char *inputString2){
	if(inputString1 == NULL && inputString2 == NULL){
		return true;
	}
	if(inputString1 == NULL || inputString2 == NULL){
		return false;
	}
}

bool AreStringsRotatedON(char *inputString,char *inputString2){

}


#endif /* ARESTRINGSROTATED_H_ */

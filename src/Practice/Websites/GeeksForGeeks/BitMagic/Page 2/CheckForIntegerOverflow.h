/*
 * CheckForIntegerOverflow.h
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

#ifndef CHECKFORINTEGEROVERFLOW_H_
#define CHECKFORINTEGEROVERFLOW_H_

bool CheckForIntegerOverflow(int a,int b){
	if(a > 0 && b > 0){
		if(a+b < 0){
			return true;
		}
		return false;
	}
	if(a<0&&b<0){
		if(a+b > 0){
			return true;
		}
		return false;
	}
}

bool CheckForIntegerOverFlow(int a,int b){
	if(a > 0){
		if(a > INT_MAX - b){
			return false;
		}
	}else{
		if(a < INT_MIN + b){
			return false;
		}
	}
	if(b > 0){
		if( b > INT_MAX + a){
			return false;
		}
	}else{
		if(b < INT_MIN + a){
			return false;
		}
	}
	return true;
}
#endif /* CHECKFORINTEGEROVERFLOW_H_ */

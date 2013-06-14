/*
 * Stack.cpp
 *
 *  Created on: May 20, 2013
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

#include "Stack.h"

Stack::Stack() {
	// TODO Auto-generated constructor stub

}

Stack::Stack(int size){
	sizeOfStack = size;
}

Stack::~Stack() {
	// TODO Auto-generated destructor stub
}

Stack::push(int value){
	if(topOfStack+1 == sizeOfStack){
		throw new exception();
	}
	stack[++topOfStack] = value;
}

void Stack::pop(){
	if(topOfStack == -1){
		throw new exception();
	}
	stack[topOfStack] =0;
	topOfStack--;
}

int Stack::top(){
	return stack[topOfStack];
}

bool Stack::isEmpty(){
	return topOfStack == -1?true:false;
}

int Stack::sizeOfStack(){
	return topOfStack+1;
}

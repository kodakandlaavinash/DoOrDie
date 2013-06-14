/*
 * Stack.h
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

#ifndef STACK_H_
#define STACK_H_

class Stack {
private:
	int sizeOfStack = 1024;
	int topOfStack = -1;
	int stack[sizeOfStack];
public:
	Stack();
	Stack(int size);
	void push(int value);
	void pop();
	int top();
	int sizeOfStack();
	bool isEmpty();
	virtual ~Stack();
};

#endif /* STACK_H_ */

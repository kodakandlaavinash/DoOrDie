/*
 * Queue.h
 *
 *  Created on: May 21, 2013
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

#ifndef QUEUE_H_
#define QUEUE_H_

class Queue {
public:
	Queue();
	virtual ~Queue();
	void enqueue(int value);
	void dequeue();
	int front();
	int sizeOfQueue();
	bool isQueueEmpty();

};

#endif /* QUEUE_H_ */

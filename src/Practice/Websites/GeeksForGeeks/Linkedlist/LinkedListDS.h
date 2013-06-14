/*
 * LinkedListDS.h
 *
 *  Created on: Apr 18, 2013
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

//int main(){
//	return -1;
//}

#ifndef LINKEDLISTDS_H_
#define LINKEDLISTDS_H_

struct linkedListNode{
	int value;
	linkedListNode *next;

	linkedListNode(){
		value =0;
		next = null;
	}

	linkedListNode(int value){
		this->value = value;
		next = null;
	}
};

struct doublyLinkedList{
	int value;
	doublyLinkedList *next;
	doublyLinkedList *prev;
};

struct arbitLinkedList{
	int value;
	arbitLinkedList *next;
	arbitLinkedList *arbit;
};

#endif /* LINKEDLISTDS_H_ */

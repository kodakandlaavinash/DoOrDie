/*
 * LinkedList.cpp
 *
 *  Created on: Apr 17, 2013
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


int main(){
	linkedListNode *head = null;
	CreateLinkedList(&head,10);
	CreateLinkedList(&head,20);
	CreateLinkedList(&head,30);
	CreateLinkedList(&head,40);
	PrintLinkedList(head);


	printf("\n");
	PrintLinkedList(head);
	return -1;
}

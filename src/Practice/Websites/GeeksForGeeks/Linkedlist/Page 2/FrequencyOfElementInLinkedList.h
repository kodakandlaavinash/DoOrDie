/*
 * FrequencyOfElementInLinkedList.h
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

#include "../LinkedListDS.h"

using namespace std;
using namespace __gnu_cxx;

#define null NULL

//int main(){
//	return -1;
//}

#ifndef FREQUENCYOFELEMENTINLINKEDLIST_H_
#define FREQUENCYOFELEMENTINLINKEDLIST_H_

/*
 * Tested
 */
int FrequencyOfElement(linkedListNode *ptr,int value){
	if(ptr == NULL){
		return INT_MIN;
	}
	int count = 0;
	linkedListNode *crawler = ptr;
	while(crawler != NULL){
		if(crawler->value == value){
			count++;
		}
		crawler = crawler->next;
	}
	return count;
}

/*
 * Tested
 */
int FrequencyOfElementUsingRecursion(linkedListNode *ptr,int value){
	if(ptr == NULL){
		return 0;
	}
	if(ptr->value == value){
		return 1+FrequencyOfElementUsingRecursion(ptr->next,value);
	}else{
		return FrequencyOfElementUsingRecursion(ptr->next,value);
	}
}

#endif /* FREQUENCYOFELEMENTINLINKEDLIST_H_ */

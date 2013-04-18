/*
 * GetNthNodeOfLinkedList.h
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

#ifndef GETNTHNODEOFLINKEDLIST_H_
#define GETNTHNODEOFLINKEDLIST_H_

/*
 *Tested
 */
linkedListNode *GetNthNodeOfLinkedList(linkedListNode *ptr,int nValue){
	linkedListNode *crawler = ptr;
	while(nValue--){
		crawler = crawler->next;
	}
	return crawler;
}

/*
 * Tested
 */
linkedListNode *GetNthNodeOfLinkedListRecursive(linkedListNode *ptr,int value){
	if(ptr == NULL){
		return NULL;
	}
	if(value == 0){
		return ptr;
	}
	return GetNthNodeOfLinkedListRecursive(ptr->next,value-1);
}


#endif /* GETNTHNODEOFLINKEDLIST_H_ */

/*
 * GetIntersectionOfLinkedList.h
 *
 *  Created on: Apr 19, 2013
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

#ifndef GETINTERSECTIONOFLINKEDLIST_H_
#define GETINTERSECTIONOFLINKEDLIST_H_

linkedListNode *GetIntersectionOfLinkedList(linkedListNode *ptr1,linkedListNode *ptr2){
	set<linkedListNode *> visitedNodes;
	linkedListNode *crawler1 = ptr1,*crawler2 = ptr2;
	set<linkedListNode *>::iterator keyPtr;
	while(crawler1 != NULL){
		visitedNodes.insert(crawler1);
		crawler1 = crawler1->next;
	}
	while(crawler2 != NULL){
		if((keyPtr = visitedNodes.find(crawler2)) != visitedNodes.end()){
			return *keyPtr;
		}
		crawler2 = crawler2->next;
	}
	return NULL;
}

linkedListNode *GetIntersectionOfLinkedList(linkedListNode *ptr1,linkedListNode *ptr2){
	if(ptr1 == NULL || ptr2 == NULL){
		return NULL;
	}
	linkedListNode *crawler1 = ptr1,*crawler2 = ptr2;
	while(crawler1 != NULL){
		crawler2 = ptr2;
		while(crawler2 != NULL){
			if(crawler1 == crawler2){
				return crawler1;
			}
		}
	}
	return NULL;
}

linkedListNode *GetIntersectionOfLinkedListUsingEquation(linkedListNode *ptr1,linkedListNode *ptr2){

}

linkedListNode *GetIntersectionOfLinkedListUsingLengths(linkedListNode *ptr1,linkedListNode *ptr2){

}
#endif /* GETINTERSECTIONOFLINKEDLIST_H_ */

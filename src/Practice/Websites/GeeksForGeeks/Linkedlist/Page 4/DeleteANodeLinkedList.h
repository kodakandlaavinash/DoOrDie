/*
 * DeleteANodeLinkedList.h
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

#ifndef DELETEANODELINKEDLIST_H_
#define DELETEANODELINKEDLIST_H_

/*
 * Tested
 */
void DeleteANodeGivenAPointer(linkedListNode *ptr){
	if((ptr) == NULL){
		return;
	}
	if((ptr)->next == NULL){
		ptr = NULL;
	}else{
		linkedListNode *temp;
		linkedListNode *ptrToNode =ptr;
		temp = ptrToNode->next;
		ptrToNode->value = ptrToNode->next->value;
		ptrToNode->next = ptrToNode->next->next;
		free(temp);
	}
}

/*
 * Tested
 */
void DeleteANodeGivenPointerIterative(linkedListNode *ptr){
	linkedListNode *crawler;
	while(crawler->next != ptr){
		crawler = crawler->next;
	}
	linkedListNode *temp;
	temp = crawler->next;
	if(crawler->next->next != NULL){
		crawler->next = crawler->next->next;
	}else{
		crawler->next = NULL;
	}
	free(temp);
}


#endif /* DELETEANODELINKEDLIST_H_ */

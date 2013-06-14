/*
 * RemoveTheLoopInLinkedList.h
 *
 *  Created on: May 12, 2013
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

#ifndef REMOVETHELOOPINLINKEDLIST_H_
#define REMOVETHELOOPINLINKEDLIST_H_

linkedListNode *DetectTheLoopInLinkedList(linkedListNode *ptr){

}

void RemoveTheLoopInLinkedList(linkedListNode *ptr){
	if(ptr == NULL){
		return;
	}
	linkedListNode *meetingPoint = DetectTheLoopInLinkedList(ptr);
	if(meetingPoint == NULL){
		return;
	}

	linkedListNode *crawler = meetingPoint;
	int lengthOfLoop  = 1;
	crawler = crawler->next;
	while(crawler != meetingPoint){
		lengthOfLoop++;
		crawler = crawler->next;
	}

	linkedListNode *crawlerTail= ptr;
	while(lengthOfLoop--){
		crawlerTail = crawlerTail->next;
	}

	linkedListNode *prev;
	while(crawler != crawlerTail){
		crawler = crawler->next;
		crawlerTail = crawlerTail->next;
		prev = crawlerTail;
	}

	prev->next = NULL;
}

void RemoveTheLoopInTheLinkedList(linkedListNode *ptr){
	if(ptr == NULL){
		return;
	}
	linkedListNode *meetingPoint = DetectTheLoopInLinkedList(ptr);
	if(meetingPoint == NULL){
		return;
	}

	linkedListNode *crawler = ptr,*innerCrawler;
	bool loopBreaked = false;
	while(1){
		innerCrawler = meetingPoint;
		while(innerCrawler->next != meetingPoint){
			if(innerCrawler->next == crawler){
				innerCrawler->next = NULL;
				loopBreaked = true;
			}
			innerCrawler = innerCrawler->next;
		}
		if(loopBreaked){
			break;
		}
		crawler = crawler->next;
	}

}

#endif /* REMOVETHELOOPINLINKEDLIST_H_ */

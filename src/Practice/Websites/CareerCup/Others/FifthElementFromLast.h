/*
 * FifthElementFromLast.h
 *	http://www.careercup.com/question?id=5614430641455104
 *  Created on: Aug 20, 2013
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

#ifndef FIFTHELEMENTFROMLAST_H_
#define FIFTHELEMENTFROMLAST_H_

linkedListNode *FindFifthElementFromEnd(linkedListNode *ptr){
	if(ptr == NULL){
		return NULL;
	}
	linkedListNode *frontCrawler = ptr,*tailCrawler= ptr;
	int counter = 5;
	while(counter){
		if(frontCrawler->next != NULL){
			frontCrawler = frontCrawler->next;
		}else{
			return NULL;
		}
	}
	while(frontCrawler->next!= NULL){
		frontCrawler = frontCrawler->next;
		tailCrawler = tailCrawler->next;
	}
	return tailCrawler;
}

linkedListNode *FindFifthElementFromEndUsingLength(linkedListNode *ptr){
	if(ptr == NULL){
		return NULL;
	}
	linkedListNode *crawler = ptr;
	int lengthOfLinkedList = 0;
	while(crawler != NULL){
		lengthOfLinkedList++;
		crawler = crawler->next;
	}
	if(lengthOfLinkedList < 5){
		return null;
	}
	lengthOfLinkedList -= 5;
	crawler = ptr;
	while(lengthOfLinkedList--){
		crawler = crawler->next;
	}
	return crawler;
}

linkedListNode *FindFifthElementFromEndHashMap(linkedListNode *ptr){
	if(ptr == NULL){
		return NULL;
	}
	hash_map<int,int> nodeIndexMap;
	int counter = -1;
	linkedListNode *crawler= ptr;
	while(crawler != NULL){
		nodeIndexMap.insert(pair<int,int>(++counter,ptr->value));
		crawler = crawler->next;
	}
	if(counter < 4){
		return NULL;
	}
	return nodeIndexMap[counter-4];
}

#endif /* FIFTHELEMENTFROMLAST_H_ */

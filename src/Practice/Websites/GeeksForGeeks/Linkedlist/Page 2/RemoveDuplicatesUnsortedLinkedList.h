/*
 * RemoveDuplicatesUnsortedLinkedList.h
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

#ifndef REMOVEDUPLICATESUNSORTEDLINKEDLIST_H_
#define REMOVEDUPLICATESUNSORTEDLINKEDLIST_H_


void RemoveDuplicatesUnsortedListON2(linkedListNode *ptr){
	linkedListNode *outerCrawler = ptr;
	linkedListNode *innerCrawler;
	linkedListNode *nodeToBeDeleted;
	while(outerCrawler->next != NULL){
		while(innerCrawler->next != NULL){
			if(outerCrawler->value == innerCrawler->value){
				nodeToBeDeleted = innerCrawler;
				innerCrawler = innerCrawler->next;
				free(nodeToBeDeleted);
			}else{
				innerCrawler = innerCrawler->next;
			}
		}
		outerCrawler = outerCrawler->next;
	}

}

void RemoveDuplicatesUnsortedListAuxSpace(linkedListNode *ptr){
	hash_map<int,int> frequencyElements;
	linkedListNode *crawler = ptr;
	hash_map<int,int>::iterator itToFrequencyElements;
	linkedListNode *crawler = ptr;
	while(crawler != NULL){
		if((itToFrequencyElements = frequencyElements.find(crawler->value)) != frequencyElements.end()){
			itToFrequencyElements->second += 1;
		}else{
			frequencyElements.insert(pair<int,int>(crawler->value,1));
		}
	}

	crawler = ptr;

	while(crawler != NULL){
		if((itToFrequencyElements = frequencyElements.find(crawler->value))->second > 1){
			frequencyElements[crawler->value]--;
			// We can copy the next element data to this node
			// There wont be any problem with the tail node because by the time the we reach
			// tail node we will have the value as 1
			crawler->value = crawler->next->value;
			linkedListNode *nodeToBeDeleted = crawler->next;
			crawler->next = crawler->next->next;
			free(nodeToBeDeleted);
		}else{
			crawler = crawler->next;
		}
	}
}

void RemoveDuplicatesUnsortedListSorting(linkedListNode *ptr){

}

#endif /* REMOVEDUPLICATESUNSORTEDLINKEDLIST_H_ */

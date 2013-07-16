/*
 * SwapKthNodeFromFirstWithKthFromEnd.h
 *
 *  Created on: Jul 16, 2013
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

#ifndef SWAPKTHNODEFROMFIRSTWITHKTHFROMEND_H_
#define SWAPKTHNODEFROMFIRSTWITHKTHFROMEND_H_

void SwapKthNodeFromStartWithKthFromEnd(linkedListNode *ptr,int k){
	if(ptr == NULL){
		return;
	}
	int lengthOfLinkedList = 0;
	linkedListNode *crawler = ptr;
	while(crawler != NULL){
		lengthOfLinkedList += 1;
		crawler = crawler->next;
	}
	if(k > lengthOfLinkedList){
		return;
	}
	if(k == lengthOfLinkedList-k+1){
		return;
	}
	linkedListNode *kthNodeFromBegin,*kthNodeFromEnd;
	crawler = ptr;
	int requiredLength = k;
	while(requiredLength--){
		crawler = crawler->next;
	}
	kthNodeFromBegin = crawler;
	linkedListNode *crawlerFromStart = ptr;
	while(crawler->next != NULL){
		crawler = crawler->next;
		crawlerFromStart = crawlerFromStart->next;
	}
	kthNodeFromEnd = crawlerFromStart;
	int temp;
	temp = kthNodeFromBegin->value;
	kthNodeFromBegin->value = kthNodeFromEnd->value;
	kthNodeFromEnd->value = temp;
}

void SwapKthNodeFromFirstWithKthFromEndAuxSpace(linkedListNode *ptr,int k){
	if(ptr == NULL){
		return;
	}
	int lengthOfLinkedList = 0;
	linkedListNode *crawler = ptr;
	while(crawler != NULL){
		lengthOfLinkedList += 1;
		crawler = crawler->next;
	}
	if(k > lengthOfLinkedList){
		return;
	}
	if(k == lengthOfLinkedList-k+1){
		return;
	}
	vector<int> auxSpace;
	crawler = ptr;
	while(crawler != NULL){
		auxSpace.push_back(crawler->value);
		crawler = crawler->next;
	}
	int tempForSwap;
	tempForSwap = auxSpace[k-1];
	auxSpace[k-1] = auxSpace[lengthOfLinkedList - k -1];
	auxSpace[lengthOfLinkedList -k-1]= tempForSwap;

	crawler = ptr;
	int vectorCrawler = 0;
	while(crawler != NULL){
		crawler->value = auxSpace[vectorCrawler];
		vectorCrawler++;
		crawler = crawler->next;
	}

}

#endif /* SWAPKTHNODEFROMFIRSTWITHKTHFROMEND_H_ */

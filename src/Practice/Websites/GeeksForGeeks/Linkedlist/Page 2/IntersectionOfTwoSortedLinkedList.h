/*
 * IntersectionOfTwoSortedLinkedList.h
 *
 *  Created on: May 3, 2013
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

#ifndef INTERSECTIONOFTWOSORTEDLINKEDLIST_H_
#define INTERSECTIONOFTWOSORTEDLINKEDLIST_H_

vector<int> IntersectionOfTwoSortedLinkedList(linkedListNode *ptr1,linkedListNode *ptr2){
	if(ptr1 == NULL || ptr2 == NULL){
		return NULL;
	}

	vector<int> intersectionOfLinkedList;
	while(ptr1 != NULL && ptr2 != NULL){
		if(ptr1->value == ptr2->value){
			intersectionOfLinkedList.push_back(ptr1->value);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}else{
			if(ptr1->value > ptr2->value){
				ptr2 = ptr2->next;
			}else{
				ptr1 = ptr1->next;
			}
		}
	}
	return intersectionOfLinkedList;
}

void IntersectionOfLinkedListRecursion(linkedListNode *ptr1,linkedListNode *ptr2,vector<int> &intersection){
	if(ptr1 == NULL || ptr2 == NULL){
		return NULL;
	}
	if(ptr1->value == ptr2->value){
		intersection.push_back(ptr1->value);
		IntersectionOfLinkedListRecursion(ptr1->next,ptr2->next,intersection);
	}else{
		if(ptr1->value > ptr2->value){
			IntersectionOfLinkedListRecursion(ptr1,ptr2->next,intersection);
		}else{
			IntersectionOfLinkedListRecursion(ptr1->next,ptr2,intersection);
		}
	}
}

vector<int> IntersectionOfLinkedListON2(linkedListNode *ptr1,linkedListNode *ptr2){
	if(ptr1 == NULL || ptr2 == NULL){
		return NULL;
	}
	vector<int> intersectionOfLinkedList;
	linkedListNode *firstListCrawler = ptr1;
	linkedListNode *secondListCrawler = ptr2;

	while(firstListCrawler != NULL){
		secondListCrawler = ptr2;
		while(secondListCrawler != NULL){
			if(secondListCrawler == firstListCrawler){
				continue;
			}
			if(secondListCrawler->value == firstListCrawler){
				intersectionOfLinkedList.push_back(firstListCrawler->value);
				break;
			}
			secondListCrawler = secondListCrawler->next;
		}
		firstListCrawler = firstListCrawler->next;
	}

}

set<int> IntersectionOfLinkedListBuiltInFunction(linkedListNode *ptr1,linkedListNode *ptr2){
	set<int> elementsInList1,elementsInList2,intersectionOfList;
	linkedListNode *crawler1 = ptr1,*crawler2 = ptr2;
	while(ptr1 != NULL){
		elementsInList1.insert(ptr1->value);
	}
	while(ptr2 != NULL){
		elementsInList2.insert(ptr2->value);
	}

	set_intersection(elementsInList1.begin(),elementsInList1.end(),elementsInList2.begin(),elementsInList2.end(),intersectionOfList);
	return intersectionOfList;
}

#endif /* INTERSECTIONOFTWOSORTEDLINKEDLIST_H_ */

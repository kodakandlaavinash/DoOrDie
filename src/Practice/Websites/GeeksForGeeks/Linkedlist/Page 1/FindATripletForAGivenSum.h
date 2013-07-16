/*
 * FindATripletForAGivenSum.h
 *
 *  Created on: May 13, 2013
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

#ifndef FINDATRIPLETFORAGIVENSUM_H_
#define FINDATRIPLETFORAGIVENSUM_H_

int *FindTripletForAGivenSumON3(linkedListNode *firstLinkedList,linkedListNode *secondLinkedList,linkedListNode *thirdLinkedList,int key){
	if(firstLinkedList == NULL || secondLinkedList ==  NULL || thirdLinkedList == NULL){
		return NULL;
	}
	linkedListNode *firstLinkedListCrawler,*secondLinkedListCrawler = secondLinkedList,*thirdLinkedListCrawler = thirdLinkedList;
	while(firstLinkedListCrawler != NULL){
		while(secondLinkedListCrawler != NULL){
			while(thirdLinkedListCrawler != NULL){
				if(firstLinkedListCrawler->value + secondLinkedListCrawler->value + thirdLinkedList->value == key){
					int result[3];
					result[0] = firstLinkedListCrawler->value;
					result[1] = secondLinkedListCrawler->value;
					result[2] = thirdLinkedListCrawler->value;
					return result;
				}
				thirdLinkedListCrawler = thirdLinkedListCrawler->next;
			}
			secondLinkedListCrawler = secondLinkedListCrawler->next;
		}
		firstLinkedListCrawler = firstLinkedListCrawler->next;
	}
	return NULL;
}

int *FindTripletForAGivenSumON2(linkedListNode *firstLinkedList,linkedListNode *secondLinkedList,linkedListNode *thirdLinkedList,int key){

}

#endif /* FINDATRIPLETFORAGIVENSUM_H_ */

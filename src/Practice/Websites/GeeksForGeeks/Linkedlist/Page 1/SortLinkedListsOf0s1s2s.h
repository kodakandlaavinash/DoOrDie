/*
 * SortLinkedListsOf0s1s2s.h
 *
 *  Created on: May 10, 2013
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

#ifndef SORTLINKEDLISTSOF0S1S2S_H_
#define SORTLINKEDLISTSOF0S1S2S_H_

void SortLinkedListsOf0s1s2s(linkedListNode *ptr){
	if(ptr == NULL){
		return;
	}
	int zeros=0,ones=0,twos=0;
	linkedListNode *crawler = ptr;
	while(crawler != NULL){
		switch(crawler->value){
		case 0:
			zeros++;
			break;
		case 1:
			ones++;
			break;
		case 2:
			twos++;
			break;
		}
	}

	crawler = ptr;
	while(zeros--){
		crawler->value = 0;
		crawler = crawler->next;
	}
	while(ones--){
		crawler->value = 1;
		crawler = crawler->next;
	}
	while(twos--){
		crawler->value = 2;
		crawler = crawler->next;
	}
}

void SortLinkedListsOf0s1s2s(linkedListNode *ptr){
	if(ptr == NULL){
		return;
	}
	linkedListNode *crawler = ptr;
	linkedListNode *insertionCrawler = ptr;
	for(int numChecker = 0;numChecker < 3;numChecker++){
		crawler = insertionCrawler;
		while(crawler != NULL){
			if(crawler->value == numChecker){
				crawler->value = insertionCrawler->value;
				insertionCrawler->value = numChecker;
				insertionCrawler = insertionCrawler->next;
			}
			crawler = crawler->next;
		}
	}
}


#endif /* SORTLINKEDLISTSOF0S1S2S_H_ */

/*
 * QuickSortOfSingleLinkedList.h
 *
 *  Created on: Jul 15, 2013
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

#ifndef QUICKSORTOFSINGLELINKEDLIST_H_
#define QUICKSORTOFSINGLELINKEDLIST_H_

linkedListNode *DivideStepQuickSortSingleLinkedList(linkedListNode *startPtr,linkedListNode *endPtr){
	if(startPtr == endPtr){
		return NULL;
	}
	int pivotValue = endPtr->value;
	linkedListNode *tailCrawler = endPtr;
	while(startPtr != endPtr){
		while(startPtr->value < pivotValue){
			startPtr = startPtr->next;
		}

	}

}

void QuickSortOfLinkedList(linkedListNode *startPtr,linkedListNode *endPtr){
	if(ptr == NULL){
		return;
	}
	linkedListNode *middlePtr = DivideStepQuickSortSingleLinkedList(startPtr,endPtr);
	QuickSortOfLinkedList(startPtr,middlePtr);
	QuickSortOfLinkedList(middlePtr->next,endPtr);
}

#endif /* QUICKSORTOFSINGLELINKEDLIST_H_ */

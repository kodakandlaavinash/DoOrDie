/*
 * QuickSortDoublyLinkedLisst.h
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

#ifndef QUICKSORTDOUBLYLINKEDLISST_H_
#define QUICKSORTDOUBLYLINKEDLISST_H_

doublyLinkedList *DivideStepDoublyLinkedList(doublyLinkedList *startPtr,doublyLinkedList *lastPtr){
	int pivotValue = lastPtr->value;
	while(startPtr != lastPtr && startPtr->next != lastPtr){
		while(startPtr->value < pivotValue){
			startPtr = startPtr->next;
		}
		while(lastPtr->value > pivotValue && startPtr != lastPtr){
			lastPtr = lastPtr->prev;
		}
		if(startPtr != ptr){
			int temp = startPtr->value;
			startPtr->value = lastPtr->value;
			lastPtr->value = temp;
			startPtr = startPtr->next;
			lastPtr = lastPtr->prev;
		}else{
			return lastPtr;
		}
	}
}

void QuickSortDoublyLinkedList(doublyLinkedList *startPtr,doublyLinkedList *lastPtr){
	if(startPtr == NULL||lastPtr == NULL||startPtr == lastPtr || startPtr->next == lastPtr){
		return;
	}
	doublyLinkedList *dividePtr = DivideStepDoublyLinkedList(startPtr,lastPtr);
	QuickSortDoublyLinkedList(startPtr,dividePtr);
	QuickSortDoublyLinkedList(dividePtr->next,lastPtr);
}


#endif /* QUICKSORTDOUBLYLINKEDLISST_H_ */

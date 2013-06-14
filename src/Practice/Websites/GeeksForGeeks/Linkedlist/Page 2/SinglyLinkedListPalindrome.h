/*
 * SinglyLinkedListPalindrome.h
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
#include "../LinkedListUtil.h"
#include "../Page 3/GetMiddleOfLinkedList.h"
#include "ReverseALinkedList.h"

using namespace std;
using namespace __gnu_cxx;

#define null NULL

//int main(){
//	return -1;
//}

#ifndef SINGLYLINKEDLISTPALINDROME_H_
#define SINGLYLINKEDLISTPALINDROME_H_

bool isSinglyLinkedListAPalindrome(linkedListNode *ptr){
	int length = lengthOfLinkedList(ptr);
	if(length == 0){
		return true;
	}
	int middleIndex = length/2;
	stack<linkedListNode *> auxSpace;
	linkedListNode *crawler = ptr;
	while(middleIndex--){
		auxSpace.push(crawler);
		crawler = crawler->next;
	}

	if(length%2 == 0){
		crawler = crawler->next;
	}

	while(!auxSpace.empty() && crawler != NULL){
		if(crawler->value != auxSpace.top()->value){
			return false;
		}
		crawler = crawler->next;
		auxSpace.pop();
	}

	if(!auxSpace.empty() || crawler != NULL){
		return false;
	}
	return true;
}

bool SinglyLinkedListPalindrome(linkedListNode *ptr,linkedListNode **frontPtr){
	if(ptr == NULL){
		return true;
	}
	bool statusTillHere = SinglyLinkedListPalindrome(ptr->next,frontPtr);
	if(!statusTillHere){
		return false;
	}

	if(ptr->next == NULL){
		if(ptr->value == (*frontPtr)->value){
			(*frontPtr) = (*frontPtr)->next;
			return true;
		}else{
			return false;
		}
	}
}

bool SinglyLinkedListPalindromeHashMap(linkedListNode *ptr){
	hash_map<int,linkedListNode *> auxSpace;
	linkedListNode *crawler = ptr;
	int counter = 0;
	while(crawler != NULL){
		auxSpace.insert(pair<int,linkedListNode *>(counter,crawler));
		counter++;
		crawler = crawler->next;
	}
	counter--;
	int middle = counter/2;
	int flagMiddle = middle;
	if(middle%2 == 1){
		middle--;
	}
	while(middle--){
		if(auxSpace[middle] != auxSpace[counter]){
			return false;
		}
	}
	if(middle != -1 && counter != flagMiddle){
		return false;
	}
	return true;
}

bool SinglyLinkedListPalindromeReverse(linkedListNode *ptr){
	if(ptr == NULL){
		return false;
	}
	linkedListNode *middle = GetMiddleListUsingRunningPtrs(ptr);
	linkedListNode *reverse = ReverseLinkedListNewList(middle->next);
	linkedListNode *crawler = ptr;
	while(ptr != middle->next && reverse != NULL){
		if(ptr->value != reverse->value){
			return false;
		}
		ptr = ptr->next;
		reverse = reverse->next;
	}
	if(ptr != middle->next || reverse != NULL){
		return false;
	}
	return true;
}
#endif /* SINGLYLINKEDLISTPALINDROME_H_ */

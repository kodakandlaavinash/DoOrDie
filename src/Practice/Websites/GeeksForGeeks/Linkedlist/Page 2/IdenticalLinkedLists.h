/*
 * IdenticalLinkedLists.h
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

#ifndef IDENTICALLINKEDLISTS_H_
#define IDENTICALLINKEDLISTS_H_

bool AreTwoLinkedListIdenticalRecursion(linkedListNode *ptr1,linkedListNode *ptr2){
	if(ptr1 == NULL && ptr2 == NULL){
		return true;
	}
	if(ptr1 == NULL || ptr2 == NULL){
		return false;
	}
	if(ptr1->value != ptr2->value){
		return false;
	}
	return AreTwoLinkedListIdenticalRecursion(ptr1->value,ptr2->value);
}

bool AreTwoLinkedListIdentical(linkedListNode *ptr1,linkedListNode *ptr2){
	if(ptr1 == NULL && ptr2 == NULL){
		return true;
	}
	if(ptr1 == NULL || ptr2 == NULL){
		return false;
	}

	linkedListNode *crawler1 = ptr1,*crawler2 = ptr2;

	while(ptr1 != NULL && ptr2 != NULL){
		if(ptr1->value != ptr2->value){
			return false;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	if(ptr1 != NULL || ptr2 != NULL){
		return false;
	}
	return true;
}


#endif /* IDENTICALLINKEDLISTS_H_ */

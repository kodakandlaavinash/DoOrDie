/*
 * PairwiseElementSwap.h
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

#ifndef PAIRWISEELEMENTSWAP_H_
#define PAIRWISEELEMENTSWAP_H_

void PairWiseElementSwapLinkedList(linkedListNode *ptr){
	if(ptr == NULL){
		return;
	}

	while(ptr->next != NULL || ptr != NULL){
		int temp;
		temp = ptr->value;
		ptr->value = ptr->next->value;
		ptr->next->value = temp;
		ptr = ptr->next->next;
	}

	return;
}

void PairWiseElementSwapRecursion(linkedListNode *ptr){
	if(ptr == NULL || ptr->next == NULL){
		return;
	}

	int temp;
	temp = ptr->value;
	ptr->value = ptr->next->value;
	ptr->next->value = temp;
	PairWiseElementSwapRecursion(ptr->next->next);
}
#endif /* PAIRWISEELEMENTSWAP_H_ */

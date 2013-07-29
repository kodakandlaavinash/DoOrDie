/*
 * DeleteMNodesAfterNNodes.h
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

#ifndef DELETEMNODESAFTERNNODES_H_
#define DELETEMNODESAFTERNNODES_H_

void DeleteMNodesAfterNNodes(linkedListNode *ptr,int M,int N){
	if(ptr == NULL){
		return;
	}
	int crawlerIncrement = M,deleteIncrement = N;
	linkedListNode *crawler = ptr;
	linkedListNode *linkedListToBeDeleted;
	linkedListNode *nextCrawler;
	while(crawler != NULL && crawlerIncrement > 0){
		crawler=crawler->next;
		crawlerIncrement--;
	}
	deleteIncrement = N;
	nextCrawler = crawler->next;
	if(nextCrawler == NULL){
		return;
	}
	while(nextCrawler != NULL && deleteIncrement > 0){
		nextCrawler = nextCrawler->next;
		deleteIncrement--;
	}
	if(nextCrawler == NULL){
		linkedListToBeDeleted = crawler->next;
		crawler->next = NULL;

	}
}

#endif /* DELETEMNODESAFTERNNODES_H_ */

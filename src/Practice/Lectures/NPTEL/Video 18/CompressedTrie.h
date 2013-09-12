/*
 * CompressedTrie.h
 *
 *  Created on: Jun 10, 2013
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

#ifndef COMPRESSEDTRIE_H_
#define COMPRESSEDTRIE_H_

struct compressedTrieNode{
	bool truthValue[26];
	compressedTrieNode ptrToAlpha[26];
	bool isLeafNode;
};

compressedTrieNode *ConstructACompressedTrieNodeTree(vector<string> userInputStrings){
	if(userInput == NULL || userInput.size() == 0){
		return;
	}
	compressedTrieNode *root,*crawler;
	int index;
	string userInput;
	root = (compressedTrieNode *)malloc(sizeof(compressedTrieNode));
	for(int alphaCounter = 0;alphaCounter < 26;alphaCounter++){
		root->ptrToAlpha[alphaCounter] = NULL;
		root->truthValue[alphaCounter] = true;
		root->isLeafNode = true;
	}
	for(int userInputStringCounter =0;userInputStringCounter = userInputStrings.size();userInputStringCounter++){
		userInput = userInputStrings[userInputStringCounter];
		userInput = tolower();
		crawler = root;

	}
}

#endif /* COMPRESSEDTRIE_H_ */

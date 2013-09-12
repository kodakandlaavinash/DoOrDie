/*
 * Trie.h
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
#include <locale>
using namespace std;
using namespace __gnu_cxx;

#define null NULL
#define PRINT_NEW_LINE printf("\n")
//int main(){
//	return -1;
//}

#ifndef TRIE_H_
#define TRIE_H_

struct trieNode;


struct trieNode{
	bool truthValue[26] = {false};
	trieNode *alphabets[26] = {NULL};
};

trieNode *BuildTrieForUserInputStrings(vector<string> userInput){
	if(userInput.size() == 0){
		return null;
	}
	trieNode *root = null;
	string userInputAtomString;
	int index;
	trieNode *trieCrawler;
	root = (trieNode *)malloc(sizeof(trieNode));
	for(int crawler =0;crawler < userInput.size();crawler++){
		userInputAtomString = userInput[crawler];
		userInputAtomString = tolower(userInputAtomString);
		trieCrawler = root;
		for(int stringCounter = 0;stringCounter < userInputAtomString.length();stringCounter++){
			index = userInputAtomString[stringCounter]-'a';
			if(trieCrawler->truthValue[index]){
				trieCrawler = trieCrawler->alphabets[index];
			}else{
				trieCrawler->alphabets[index] = (trieNode *)malloc(sizeof(trieNode));
				for(int pointerCounter = 0;pointerCounter < 26;pointerCounter++){
					trieCrawler->alphabets[index]->alphabets[pointerCounter] = NULL;
					trieCrawler->alphabets[index]->truthValue[pointerCounter] = false;
				}
				trieCrawler->alphabets[index]->truthValue[index] = true;
				trieCrawler = trieCrawler->alphabets[index];
			}
		}
	}
}

bool SearchStringInTrie(trieNode *ptr,string searchString){
	if(searchString == NULL || searchString.length() == 0){
		return true;
	}
	if(ptr  == NULL){
		return false;
	}
	trieNode *crawler = ptr;
	int userInputCrawler,index;
	searchString = tolower(searchString);
	for(userInputCrawler = 0;userInputCrawler < searchString.length();userInputCrawler++){
		index = searchString[userInputCrawler] - 'a';
		if(!crawler->truthValue[index]){
			return false;
		}
		crawler = crawler->alphabets[index];
	}
	return true;
}
#endif /* TRIE_H_ */

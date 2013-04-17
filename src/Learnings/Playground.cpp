/*
 * Playground.cpp
 *
 *  Created on: Apr 17, 2013
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

void sample(int *ptr){
	int j =40;
	printf("%d\n",*ptr);
	printf("%p\n",ptr);
	ptr = &j;
	printf("%d\n",*ptr);
	printf("%p\n",ptr);
	printf("%p\n",&ptr);
}


//int main(){
//	int i = 32;
//	int *ptr = &i;
//	printf("Hello world\n");
//	printf("%d\n",*ptr);
//	printf("%p\n",ptr);
//	printf("%p\n",&ptr);
//	sample(ptr);
//	printf("%d\n",*ptr);
//	printf("%p\n",ptr);
//	printf("%p\n",&ptr);
//	return -1;
//}


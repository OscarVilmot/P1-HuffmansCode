/*
 * structures.h
 *
 *  Created on: 21 oct. 2020
 *      Author: pasarco
 */

#ifndef HEADERS_STRUCTURES_H_
#define HEADERS_STRUCTURES_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
} Node;

#endif /* HEADERS_STRUCTURES_H_ */

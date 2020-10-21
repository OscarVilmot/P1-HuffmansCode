/*
 * treesActions.h
 *
 *  Created on: 21 oct. 2020
 *      Author: pasarco
 */

#ifndef HEADERS_TREESACTIONS_H_
#define HEADERS_TREESACTIONS_H_

int max(int a, int b);

Node* createNode(int value);
void deleteTree(Node* tree);

int heightTree(Node* tree);
int balFactorTree(Node* tree);

void rightRotation(Node** tree);
void leftRotation(Node** tree);

#endif /* HEADERS_TREESACTIONS_H_ */

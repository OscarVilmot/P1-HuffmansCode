/*
 * occurrence.h
 *
 *  Created on: 2 nov. 2020
 *      Author: ksauvee
 */

#ifndef OCCURRENCE
#define OCCURRENCE

typedef struct OccurrenceLetter{
    char letter;
    int occurrence;
}OccurrenceLetter;

typedef struct Node {
    OccurrenceLetter* letterAndOccurrence;
    struct Node* right;
    struct Node* left;
}Node;

typedef struct ElementOccurrenceLetter{
    Node* data;
    struct ElementOccurrenceLetter* next;
}ElementOccurrenceLetter;

extern Node* createNode(char letter);
extern ElementOccurrenceLetter* createElementOccurrenceLetter(char letter);
extern void findOccurrenceLettersInText(ElementOccurrenceLetter** listOccurrenceLetters, char* text);

#endif
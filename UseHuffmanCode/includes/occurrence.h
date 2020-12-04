/*
 * occurrence.h
 *
 *  Created on: 2 nov. 2020
 *      Author: ksauvee
 */

#ifndef OCCURRENCE
#define OCCURRENCE

#include "huffmanTree.h"

typedef struct OccurrenceLetter{
    char letter;
    int occurrence;
}OccurrenceLetter;

typedef struct ElementOccurrenceLetter{
    Node* data;
    struct ElementOccurrenceLetter* next;
}ElementOccurrenceLetter;

extern void findOccurrenceLettersInText(ElementOccurrenceLetter** listOccurrenceLetters, char* text);

#endif
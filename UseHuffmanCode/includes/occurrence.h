/*
 * huffmanCode.h
 *
 *  Created on: 2 nov. 2020
 *      Author: ksauvee
 */

#ifndef OCCURRENCE
#define OCCURRENCE

#include <stdlib.h>

typedef struct OccurrenceLetter{
    char letter;
    int occurrence;
}OccurrenceLetter;

typedef struct ElementOccurrenceLetter{
    OccurrenceLetter* data;
    struct ElementOccurrenceLetter* next;
}ElementOccurrenceLetter;

extern void findOccurrenceLettersInText(ElementOccurrenceLetter** listOccurrenceLetters, char* text);

#endif
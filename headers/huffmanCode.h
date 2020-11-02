/*
 * huffmanCode.h
 *
 *  Created on: 2 nov. 2020
 *      Author: ksauvee
 */

#ifndef HUFFMAN_CODE
#define HUFFMAN_CODE

typedef struct OccurrenceLetter{
    char letter;
    int occurrence;
}OccurrenceLetter;

typedef struct ElementSimplyLinkedList {
    OccurrenceLetter data;
    struct ElementSimplyLinkedList* next;
}ElementSimplyLinkedList;

#endif
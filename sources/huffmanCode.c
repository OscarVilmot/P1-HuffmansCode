/**
 * \file huffmanCode.c
 * \brief Source where all tree-related function take places
 * \date 21 oct. 2020
 * \author Kylian.S, Tommy Lee.A, Joel.G, Jules.R, Oscar.V
 * \version 0.1
 *
 * Compression program using Huffman Algorith, with trees and queues
 *
 */

#include "../headers/huffmanCode.h"

static OccurrenceLetter* createOccurrenceLetter(char letter){
    OccurrenceLetter* newOccurrenceLetter = malloc(sizeof(OccurrenceLetter));

    newOccurrenceLetter->letter = letter;
    newOccurrenceLetter->occurrence = 0;

    return newOccurrenceLetter;
}

static ElementOccurrenceLetter* createElementOccurrenceLetter(char letter){
    ElementOccurrenceLetter* newElementOccurrenceLetter = malloc(sizeof(ElementOccurrenceLetter));
    
    newElementOccurrenceLetter->data = createOccurrenceLetter(letter);
    newElementOccurrenceLetter->next = NULL;

    return newElementOccurrenceLetter;
}

void findOccurrenceLettersInText(ElementOccurrenceLetter** listOccurrenceLetters, char* text){

}
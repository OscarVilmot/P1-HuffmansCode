/**
 * \file occurrence.c
 * \brief Source where all occurrence-related function take places
 * \date 21 oct. 2020
 * \author Kylian.S, Tommy Lee.A, Joel.G, Jules.R, Oscar.V
 * \version 0.1
 *
 * Compression program using Huffman Algorith, with trees and queues
 *
 */

#include <stdlib.h>
#include "../includes/occurrence.h"

static OccurrenceLetter* createOccurrenceLetter(char letter){
    OccurrenceLetter* newOccurrenceLetter = (OccurrenceLetter*) malloc(sizeof(OccurrenceLetter));

    newOccurrenceLetter->letter = letter;
    newOccurrenceLetter->occurrence = 1;

    return newOccurrenceLetter;
}

static ElementOccurrenceLetter* createElementOccurrenceLetter(char letter){
    ElementOccurrenceLetter* newElementOccurrenceLetter = (ElementOccurrenceLetter*) malloc(sizeof(ElementOccurrenceLetter));
    
    newElementOccurrenceLetter->data = createOccurrenceLetter(letter);
    newElementOccurrenceLetter->next = NULL;

    return newElementOccurrenceLetter;
}

static void actualizeOccurrenceLetter(ElementOccurrenceLetter** listOccurrenceLetters, char letter){
    if (*listOccurrenceLetters == NULL){
        // the letter doesn't exist, so we add it at the queue
        ElementOccurrenceLetter* newLetter = createElementOccurrenceLetter(letter);
        *listOccurrenceLetters = newLetter;
    }else{
        if ((*listOccurrenceLetters)->data->letter == letter){
            ++(*listOccurrenceLetters)->data->occurrence;
        }else{
            actualizeOccurrenceLetter(&(*listOccurrenceLetters)->next, letter);
        }
    }
}

void findOccurrenceLettersInText(ElementOccurrenceLetter** listOccurrenceLetters, char* text){
    int i = 0;
    if (text != NULL) {
        while (text[i] != '\0'){
            actualizeOccurrenceLetter(listOccurrenceLetters, text[i]);
            ++i;
        }
    }
}

int findSizeOccurrences(ElementOccurrenceLetter* occurrences) {
    if (occurrences == NULL) {
        return 0;
    } else {
        return 1 + findSizeOccurrences(occurrences->next);
    }
}

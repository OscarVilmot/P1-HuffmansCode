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

Node* createNode(char letter) {
    Node* newNode = malloc(sizeof(Node));

    newNode->letterAndOccurrence = createOccurrenceLetter(letter);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

ElementOccurrenceLetter* createElementOccurrenceLetter(char letter){
    ElementOccurrenceLetter* newElementOccurrenceLetter = (ElementOccurrenceLetter*) malloc(sizeof(ElementOccurrenceLetter));
    
    newElementOccurrenceLetter->data = createNode(letter);
    newElementOccurrenceLetter->next = NULL;

    return newElementOccurrenceLetter;
}

static void actualizeOccurrenceLetter(ElementOccurrenceLetter** listOccurrenceLetters, char letter){
    if (*listOccurrenceLetters == NULL){
        // the letter doesn't exist, so we add it at the queue
        ElementOccurrenceLetter* newLetter = createElementOccurrenceLetter(letter);
        *listOccurrenceLetters = newLetter;
    }else{
        if ((*listOccurrenceLetters)->data->letterAndOccurrence->letter == letter){
            ++(*listOccurrenceLetters)->data->letterAndOccurrence->occurrence;
        }else{
            actualizeOccurrenceLetter(&(*listOccurrenceLetters)->next, letter);
        }
    }
}

void findOccurrenceLettersInText(ElementOccurrenceLetter** listOccurrenceLetters, char* text){
    int i = 0;

    while (text[i] != '\0'){
        actualizeOccurrenceLetter(listOccurrenceLetters, text[i]);
        ++i;
    }
}

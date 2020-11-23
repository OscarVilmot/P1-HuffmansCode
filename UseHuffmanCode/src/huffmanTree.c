/**
 * \file huffmanCode.c
 * \brief Source where all huffmanTree-related function take places
 * \date 23 nov. 2020
 * \author Kylian.S, Tommy Lee.A, Joel.G, Jules.R, Oscar.V
 * \version 0.1
 *
 * Compression program using Huffman Algorith, with trees and queues
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "../includes/huffmanTree.h"

static void deleteElementInList(ElementOccurrenceLetter** listOccurrences, OccurrenceLetter* element) {
    ElementOccurrenceLetter* refToHead = malloc(sizeof(ElementOccurrenceLetter));
    refToHead->next = *listOccurrences;
    ElementOccurrenceLetter* current = refToHead;

    while (current->next->data != element) {
        current = current->next;
    }

    current->next = current->next->next;
    current->next->next = NULL;
    *listOccurrences = refToHead->next;
    free(refToHead);
}

static OccurrenceLetter* findMinListOccurrences(ElementOccurrenceLetter* listOccurrences) {
    OccurrenceLetter* min = malloc(sizeof(OccurrenceLetter));
    min = listOccurrences->data;
    ElementOccurrenceLetter* current = listOccurrences;

    while (current != NULL) {
        if (current->data->occurrence < min->occurrence) {
            min = current->data;
        }
        current = current->next;
    }
    
    return min;
}

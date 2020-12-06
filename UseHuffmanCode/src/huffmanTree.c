/**
 * \file huffmanTree.c
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

static void deleteElementInList(ElementOccurrenceLetter** listOccurrences, ElementOccurrenceLetter* element) {
    if (*listOccurrences != NULL) {
        // we use a pointer to the listOccurrences (refToHead) in order to test the data of the next element
        ElementOccurrenceLetter* refToHead = malloc(sizeof(ElementOccurrenceLetter));
        ElementOccurrenceLetter* current = NULL;

        refToHead->next = *listOccurrences;
        current = refToHead;

        while (current->next->data != element->data) {
            current = current->next;
        }
        
        current->next = current->next->next;
        element->next = NULL;
        *listOccurrences = refToHead->next;
        free(refToHead);
    }
}

static ElementOccurrenceLetter* findMinListOccurrences(ElementOccurrenceLetter** listOccurrences) {
    if (listOccurrences == NULL) {
        return NULL;
    } else {
        ElementOccurrenceLetter* min = malloc(sizeof(ElementOccurrenceLetter));
        ElementOccurrenceLetter* current = NULL;

        min = *listOccurrences;
        current = *listOccurrences;

        while (current != NULL) {
            if (current->data->letterAndOccurrence->occurrence < min->data->letterAndOccurrence->occurrence) {
                min = current;
            }
            current = current->next;
        }

        // we isolate the element from the list
        deleteElementInList(listOccurrences, min);
        return min;
    }
}

Node* createHuffmanTree(ElementOccurrenceLetter** listOccurrences) {
    // we store the two minimums of the occurrences list
    ElementOccurrenceLetter* min = findMinListOccurrences(listOccurrences);
    ElementOccurrenceLetter* min2 = findMinListOccurrences(listOccurrences);
    ElementOccurrenceLetter* huffmanTree = NULL;

    while (min != NULL && min2 != NULL) {
        // we create the new node
        huffmanTree = createElementOccurrenceLetter('\0');
        huffmanTree->data->left = min->data;
        huffmanTree->data->right = min2->data;
        huffmanTree->data->letterAndOccurrence->occurrence = min->data->letterAndOccurrence->occurrence + min2->data->letterAndOccurrence->occurrence;

        // the node become the root
        huffmanTree->next = *listOccurrences;
        *listOccurrences = huffmanTree;
        
        min = findMinListOccurrences(listOccurrences);
        min2 = findMinListOccurrences(listOccurrences);
    }

    return huffmanTree->data;
}

static void freeNode(Node** node) {
    if (*node != NULL) {
        free((*node)->letterAndOccurrence);
        (*node)->letterAndOccurrence = NULL;
        free(*node);
        *node = NULL;
    }
}

void freeHuffmanTree(Node** huffmanTree) {
    // we use double pointer in order to affect pointer to NULL
    if (*huffmanTree != NULL) {
        freeHuffmanTree(&(*huffmanTree)->left);
        freeHuffmanTree(&(*huffmanTree)->right);
        freeNode(huffmanTree);
        *huffmanTree = NULL;
    }
}

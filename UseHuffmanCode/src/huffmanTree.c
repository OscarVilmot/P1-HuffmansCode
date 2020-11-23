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
#include "../includes/occurrence.h"

static Node* createNode() {
    OccurrenceLetter* newOccurrenceLetter = malloc(sizeof(OccurrenceLetter));
    Node* newNode = malloc(sizeof(Node));

    newOccurrenceLetter->letter = '\0';
    newOccurrenceLetter->occurrence = 0;
    newNode->letterAndOccurrence = newOccurrenceLetter;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

static void deleteElementInList(ElementOccurrenceLetter** listOccurrences, OccurrenceLetter* element) {
    ElementOccurrenceLetter* refToHead = malloc(sizeof(ElementOccurrenceLetter));
    refToHead->next = *listOccurrences;
    ElementOccurrenceLetter* current = refToHead;

    while (current->next->data != element) {
        current = current->next;
    }

    current->next = current->next->next;
    *listOccurrences = refToHead->next;
    free(refToHead);
}

static OccurrenceLetter* findMinListOccurrences(ElementOccurrenceLetter** listOccurrences) {
    if (*listOccurrences == NULL) {
        return NULL;
    } else {
        OccurrenceLetter* min = malloc(sizeof(OccurrenceLetter));
        min = (*listOccurrences)->data;
        ElementOccurrenceLetter* current = *listOccurrences;

        while (current != NULL) {
            if (current->data->occurrence < min->occurrence) {
                min = current->data;
            }
            current = current->next;
        }
        deleteElementInList(listOccurrences, min);
        return min;
    }
}

Node* createHuffmanTree(ElementOccurrenceLetter** listOccurrences) {
    OccurrenceLetter* min = findMinListOccurrences(listOccurrences);
    if (min != NULL) {
        Node* huffmanTree = createNode();
        huffmanTree->letterAndOccurrence = min;

        min = findMinListOccurrences(listOccurrences);
        while (min != NULL) {
            Node* newNode = createNode();
            newNode->right = huffmanTree;
            huffmanTree = newNode;

            huffmanTree->left = createNode();
            huffmanTree->left->letterAndOccurrence = min;
            huffmanTree->letterAndOccurrence->occurrence = huffmanTree->left->letterAndOccurrence->occurrence + huffmanTree->right->letterAndOccurrence->occurrence;     
            min = findMinListOccurrences(listOccurrences);
        }

        return huffmanTree;
    }
    return NULL;
}

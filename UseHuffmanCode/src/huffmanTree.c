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

static Node* createNode() {
    // first we allocate the memory for the OccurrenceLetter structure in order to avoid segmentation fault later on
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
    // we use a pointer to the listOccurrences (refToHead) in order to test the data of the next element
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

        // we isolate the element from the list
        deleteElementInList(listOccurrences, min);
        return min;
    }
}

Node* createHuffmanTree(ElementOccurrenceLetter** listOccurrences) {
    OccurrenceLetter* min = findMinListOccurrences(listOccurrences);

    // we verify that the list isn't empty (first condition in findMinListOccurrences)
    if (min != NULL) {
        // we add the first node
        Node* huffmanTree = createNode();
        huffmanTree->letterAndOccurrence = min;

        min = findMinListOccurrences(listOccurrences);

        // we construct the tree while the list isn't empty
        while (min != NULL) {
            // first we create the new root
            Node* newNode = createNode();
            newNode->right = huffmanTree;
            huffmanTree = newNode;

            // then we add a node to the left child
            huffmanTree->left = createNode();
            huffmanTree->left->letterAndOccurrence = min;
            huffmanTree->letterAndOccurrence->occurrence = huffmanTree->left->letterAndOccurrence->occurrence + huffmanTree->right->letterAndOccurrence->occurrence;     
            min = findMinListOccurrences(listOccurrences);
        }

        return huffmanTree;
    }
    return NULL;
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

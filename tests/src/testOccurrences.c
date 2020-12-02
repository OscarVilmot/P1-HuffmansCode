/**
 * \file testOccurrences.c
 * \brief Source where all occurrences-related tests take places
 * \date 2 dec. 2020
 * \author Kylian.S, Tommy Lee.A, Joel.G, Jules.R, Oscar.V
 * \version 0.1
 *
 * Compression program using Huffman Algorith, with trees and queues
 *
 */
#include <stdio.h>
#include "../../UseHuffmanCode/includes/occurrence.h"

void testFindListOccurrenceLettersNull() {
    ElementOccurrenceLetter* occurrences = NULL;
    findOccurrenceLettersInText(&occurrences, NULL);

    if (occurrences == NULL) {
        printf("TEST 1 : SUCCESS");
    } else {
        printf("TEST 1 : FAILURE");
    }
    printf("\n");
}

void testFindListOccurrenceLettersInCharacter() {
    char* text = "a";
    ElementOccurrenceLetter* occurrences = NULL;
    findOccurrenceLettersInText(&occurrences, text);

    if (occurrences->data->letter == 'a' && occurrences->data->occurrence == 1) {
        printf("TEST 2 : SUCCESS");
    } else {
        printf("TEST 2 : FAILURE");
    }
    printf("\n");
}

void testFindListOccurrenceLettersInWord() {
    char* text = "word";
    ElementOccurrenceLetter* occurrences = NULL;
    findOccurrenceLettersInText(&occurrences, text);

    if (findSizeOccurrences(occurrences) == 4) {
        printf("TEST 3 : SUCCESS");
    } else {
        printf("TEST 3 : FAILURE");
    }
    printf("\n");
}

void testFindListOccurrenceLettersInSentence() {
    char* text = "Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do";
    ElementOccurrenceLetter* occurrences = NULL;
    findOccurrenceLettersInText(&occurrences, text);

    if (findSizeOccurrences(occurrences) == 22) {
        printf("TEST 4 : SUCCESS");
    } else {
        printf("TEST 4 : FAILURE");
    }
    printf("\n");
}

int main() {
    testFindListOccurrenceLettersNull();
    testFindListOccurrenceLettersInCharacter();
    testFindListOccurrenceLettersInWord();
    testFindListOccurrenceLettersInSentence();
    return 0;
}

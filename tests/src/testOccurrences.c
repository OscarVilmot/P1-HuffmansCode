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

void testFindListOccurrenceLettersNull(ElementOccurrenceLetter* occurrences) {
    findOccurrenceLettersInText(&occurrences, NULL);

    if (occurrences == NULL) {
        printf("Test 1 : SUCCESS");
    } else {
        printf("Test 1 : FAILURE");
    }
    printf("\n");
}

int main() {
    ElementOccurrenceLetter* listOccurrences = NULL;
    testFindListOccurrenceLettersNull(listOccurrences);
    return 0;
}

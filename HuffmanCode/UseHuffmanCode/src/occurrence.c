#include <stdlib.h>
#include "../includes/occurrence.h"

static void swapElement(ElementOccurrenceLetter* first, ElementOccurrenceLetter* second) {
    OccurrenceLetter* temp = first->data;
    first->data = second->data;
    second->data = temp;
}

void bubbleSortListOccurrences(ElementOccurrenceLetter* occurrences, int sizeListOccurrences) {
    if (occurrences != NULL) {
        int isSwap;
        ElementOccurrenceLetter* current;
        ElementOccurrenceLetter* limit = NULL;

        do {
            isSwap = 0;
            current = occurrences;

            while (current->next != limit) {
                if (current->data->occurrence > current->next->data->occurrence) {
                    swapElement(current, current->next);
                    isSwap = 1;
                }
                current = current->next;
            }
            limit = current;
        } while (isSwap);
    }
}

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

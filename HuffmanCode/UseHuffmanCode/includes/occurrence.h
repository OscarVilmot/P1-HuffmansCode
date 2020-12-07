/**
 * \file occurrence.h
 * \brief Header of the module creating the occurrence list.
 * \date November 2020
 * \author Kylian.S, Tommy Lee.A, Joel.G, Jules.R, Oscar.V
 * \version 1.0
 */

#ifndef OCCURRENCE
#define OCCURRENCE

/**
 * \typedef struct OccurrenceLetter
 * \brief An OccurrenceLetter is a letter associated with its number of occurrences in the text.
*/
typedef struct OccurrenceLetter{
    char letter;
    int occurrence;
}OccurrenceLetter;

/**
 * \typedef struct Node
 * \brief A Node is a binary tree element containing a struct OccurrenceLetter as the data.
*/
typedef struct Node {
    OccurrenceLetter* letterAndOccurrence;
    struct Node* left;
    struct Node* right;
} Node;

/**
 * \typedef struct ElementOccurrenceLetter
 * \brief An ElementOccurrenceLetter is a linked list element containing a struct Node as the data.
*/
typedef struct ElementOccurrenceLetter{
    Node* data;
    struct ElementOccurrenceLetter* next;
}ElementOccurrenceLetter;

/**
 * \brief Function to create a node.
 *        \n Example :
 *         \code{.c}
 *         Node* newNode = createNode('A');
 *         \endcode
 * \param letter the letter which contain the node.
 * \return the Node's pointer.
*/
extern Node* createNode(char letter);

/**
 * \brief Function to create a struct ElementOccurrenceLetter.
 *        \n Example :
 *         \code{.c}
 *         ElementOccurrenceLetter* Element = createElementOccurrenceLetter('A');
 *         \endcode
 * \param letter the letter which contain the Element->data.
 * \return the ElementOccurrenceLetter's pointer.
*/
extern ElementOccurrenceLetter* createElementOccurrenceLetter(char letter);

/**
 * \brief Function to create an occurrences list based on the text.
 *        \n Example :
 *         \code{.c}
 *         findOccurrenceLettersInText(occurrences, "This is a sentence");
 *         \endcode
 * \param listOccurrenceLetters the list of occurrences which is created with the text.
 * \param text the text which help to create the list of occurrences.
*/
extern void findOccurrenceLettersInText(ElementOccurrenceLetter** listOccurrenceLetters, char* text);

#endif
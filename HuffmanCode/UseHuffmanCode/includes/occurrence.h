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
 * \typedef struct ElementOccurrenceLetter
 * \brief An ElementOccurrenceLetter is a linked list element containing a struct OccurrenceLetter as the data.
*/
typedef struct ElementOccurrenceLetter{
    OccurrenceLetter* data;
    struct ElementOccurrenceLetter* next;
}ElementOccurrenceLetter;

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
///\file header.h
///\brief Header file where we can find the head declaration of our functions are.
///
#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>

 /** A Struct type.
     *  Where we can store our array.
     */

struct dictionary {
    char word[100]; /**< The word dictionary will store. */
    char definition[100][100]; /**< An array of definitions that our word will have. */
    struct dictionary *nextWord;  /**< Memory address of the next word. */


}dictionary; /**< Our main dictionary. */


void add_word (struct dictionary *dictionary, char word[100]); /**< Head declaration of function that adds a word to the dictionary*/
void add_definition (struct dictionary *dictionary, char word[100], char definition[100]); /**< Head declaration of function that adds a definition for a word */
void change_word (struct dicitonary *dictionary, char word[100], char new_word[100]); /**< Head declaration of function that changes a current word with a new one */
void change_definition (struct dicitonary *dictionary, char word[100], char definition[100], char new_definition[100]); /**< Head declaration of function that changes a current definition of a word with a new one */
void show_all_words (struct dictionary *dictionary); /**< Head declaration of a function that prints to the console all words including ther definitions*/
void show_all_definitions (struct dictionary *dictionary, char word[100]); /**< Head declaration of a function that prints to the console definitions of a given word */
void delete_word (struct dictionary *dictionary, char word[100]); /**< Head declaration of a function deletes from dictionary the given word*/
void delete_definition (struct dictionary *dictionary, char word[100], char definition[100]); /**< Head declaration of a function that deletes a given definition of a word*/
void save_to_file(struct dictionary *dictionary); /**< Head declaration of a function that prints our dictionary to a file*/
#endif

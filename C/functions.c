///\file functions.c
///\brief File where all functions are found.
///
#include "header.h"

/*! \fn void add_word (struct dictionary *dictionary, char word[100])
    \brief Adds a word to the dictionary.
    \param dictionary is the linked list where the word will be added.
	\param word is the word that will be added.
*/

void add_word (struct dictionary *dictionary, char word[100]) {

    struct dictionary *iterator = dictionary;
    struct dictionary *newWord = malloc (sizeof (struct dictionary));
    char yon;
    char definition[100];

    while (iterator->nextWord != NULL) {
        if (strcmp (iterator->nextWord, word) == 0) {
            printf("\nWord already exists.");
            return;
        }
        iterator = iterator->nextWord;
    }

    iterator->nextWord = newWord;
    newWord->nextWord = NULL;
    strcpy(newWord->word, word);
    printf("\nYou've added a new word \"%s\" do you want to add a definition(Y/N)? ", word);
    yon = getch();
    if (yon == 'n' || yon == 'N')
        return;
    printf("\nEnter the word first definition: ");
    scanf(" %79[^\n]", definition);
    strcpy(newWord->definition[0], definition);

}

/*! \fn void add_definition (struct dictionary *dictionary, char word[100], char definition[100])
    \brief Adds a definition to a current word in our dictionary.
    \param dictionary is the linked list where the definition array is stored.
	\param word is the word for which the definition will be added.
	\param definition is the definition that will be added for the given word.
*/

void add_definition (struct dictionary *dictionary, char word[100], char definition[100]) {

    int i;
    struct dictionary *iterator = dictionary;

    while (iterator->nextWord != NULL) {
        if (strcmp (iterator->nextWord->word, word) == 0) {
            for (i = 0; strlen(iterator->nextWord->definition[i]) != 0; i++);
            strcpy(iterator->nextWord->definition[i], definition);
            printf("\nDefinition added successfully.");
            return;
        }
        iterator = iterator->nextWord;
    }
    printf("\nGiven word does not exists in dictionary.");
}

/*! \fn void change_word (struct dicitonary *dictionary, char word[100], char new_word[100])
    \brief Change a current word with a new one.
    \param dictionary is the linked list where the word is searched.
	\param word is the word that we search for.
	\param new_word is the word that will replace the old one.
*/

void change_word (struct dictionary *dictionary, char word[100], char new_word[100]) {

    struct dictionary *iterator = dictionary;

    while (iterator->nextWord != NULL) {
        if (strcmp (iterator->nextWord->word, word) == 0) {
            strcpy(iterator->nextWord->word, new_word);
            printf("\nWord \"%s\" successfully replaced with \"%s\".", word, new_word);
            return;
        }
        iterator = iterator->nextWord;
    }
    printf("\nGiven word does not exists in dictionary.");
}

/*! \fn void change_definition (struct dicitonary *dictionary, char word[100], char definition[100], char new_definition[100])
    \brief Change a current definition of a word with a new one.
    \param dictionary is the linked list where the definition is searched.
	\param word is the word that we search for in order to find his definition.
	\param definition is the definition we search for in order to replace it.
	\param new_definition is the new definition that will replace the old one.
*/

void change_definition (struct dictionary *dictionary, char word[100], char definition[100], char new_definition[100]) {

    int i;
    struct dictionary *iterator = dictionary;

    while (iterator->nextWord != NULL) {
        if (strcmp (iterator->nextWord->word, word) == 0) {
            for (i = 0; strlen(iterator->nextWord->definition[i]) != 0; i++)
                if ( strcmp(iterator->nextWord->definition[i], definition) == 0) {
                    strcpy(iterator->nextWord->definition[i], new_definition);
                    printf("\nDefinition \"%s\" successfully replaced with \"%s\".", definition, new_definition);
                    return;
                }
            return;
        }
        iterator = iterator->nextWord;
    }
    printf("\nGiven word does not exists in dictionary.");
}


/*! \fn void show_all_words (struct dictionary *dictionary)
    \brief Prints to the console all words and their definitions.
    \param dictionary is the linked list from where data will be printed.
*/

void show_all_words (struct dictionary *dictionary) {

    int i;
    struct dictionary *iterator = dictionary;

        while (iterator->nextWord != NULL) {
            printf("\n\nWord: %s", iterator->nextWord->word);
            for (i = 0; strlen(iterator->nextWord->definition[i]) != 0; i++)
                printf("\nDefinition %d: %s", i + 1, iterator->nextWord->definition[i]);
            printf("\n");
            iterator = iterator->nextWord;
        }

}

/*! \fn void show_all_definitions (struct dictionary *dictionary, char word[100])
    \brief Prints to the console all definitions of a given word.
    \param dictionary is the linked list from where data will be printed.
	\param word is the word that we will print definitions for.
*/

void show_all_definitions (struct dictionary *dictionary, char word[100]) {

    int i;
    struct dictionary *iterator = dictionary;

    while (iterator->nextWord != NULL) {
        if (strcmp (iterator->nextWord->word, word) == 0) {
            printf("\nWord: %s", word);
            for (i = 0; strlen(iterator->nextWord->definition[i]) != 0; i++)
                printf("\nDefinition %d: %s", i + 1, iterator->nextWord->definition[i]);
            printf("\n");
            return;
        }
        iterator = iterator->nextWord;
    }
    printf("\nGiven word does not exists in dictionary.");


}

/*! \fn void delete_word (struct dictionary *dictionary, char word[100])
    \brief Deletes from the dictionary the given word.
    \param dictionary is the linked list from where data will be deleted.
	\param word is the word that we search for in order to delete it.
*/

void delete_word (struct dictionary *dictionary, char word[100]) {

    int i;
    struct dictionary *iterator = dictionary;
    struct dictionary *deleteWord = malloc (sizeof (struct dictionary));

    while (iterator->nextWord != NULL) {
        if (strcmp (iterator->nextWord->word, word) == 0) {
            deleteWord = iterator->nextWord;
            iterator->nextWord = iterator->nextWord->nextWord;
            free(deleteWord);
            printf("\nWord \"%s\" successfully deleted.", word);
            return;
        }
        iterator = iterator->nextWord;
    }
    printf("\nGiven word does not exists in dictionary.");


}

/*! \fn void delete_definition (struct dictionary *dictionary, char word[100], char definition[100])
    \brief Deletes a definition of an existing word.
    \param dictionary is the linked list from where data will be deleted.
	\param word is the word that we search for in order to delete it's definition.
	\param definition is the definition that we search in order to delete it.
*/

void delete_definition (struct dictionary *dictionary, char word[100], char definition[100]) {

    int i;
    struct dictionary *iterator = dictionary;

    while (iterator->nextWord != NULL) {
        if (strcmp (iterator->nextWord->word, word) == 0) {
            for (i = 0; strlen(iterator->nextWord->definition[i]) != 0; i++)
                if ( strcmp(iterator->nextWord->definition[i], definition) == 0) {
                    strcpy(iterator->nextWord->definition[i], "");
                    printf("\nDefinition \"%s\" successfully deleted.", definition);
                    return;
                }
            printf("\nGiven definition does not exist.");
            return;
        }
        iterator = iterator->nextWord;
    }
    printf("\nGiven word does not exists in dictionary.");


}

/*! \fn void save_to_file(struct dictionary *dictionary)
    \brief Prints our dictionary to a file
    \param dictionary is the linked list from where data will be printed.
*/

void save_to_file (struct dictionary *dictionary) {




    FILE *f = fopen("dictionary.txt", "a+");

    if (f == NULL)
    {
        printf("\nError saving to file!");
        return;
    }

    int i;
    struct dictionary *iterator = dictionary;

	while (iterator->nextWord != NULL) {
		fprintf(f, "\n\nWord: %s", iterator->nextWord->word);
		for (i = 0; strlen(iterator->nextWord->definition[i]) != 0; i++)
			fprintf(f, "\nDefinition %d: %s", i + 1, iterator->nextWord->definition[i]);
		fprintf(f, "\n");
		iterator = iterator->nextWord;
	}
	fclose(f);

	printf("\nYour content has been saved to file \"%s\".", "dictionary.txt");
}

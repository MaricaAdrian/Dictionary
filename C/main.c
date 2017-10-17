///\file main.c
///\brief Our main file where the menu is.
///

#include "header.h"


/*! \fn void main
	\brief This is our main function where we can find the menu and the loop that forces the user to choose an option along with the function calling for the option selected.
*/

int main () {

    struct dictionary *dictionary = malloc ((sizeof (struct dictionary)));
    dictionary->nextWord = NULL;
    unsigned int decision;
    char decision_1[100];
    char decision_2[100];
    char decision_3[100];

    while (1) {
        printf("\n\t Menu");
        printf("\n1.Add a word to the dictionary");
        printf("\n2.Add a definition for a word");
        printf("\n3.Show definitions of a word");
        printf("\n4.Show all dictionary");
        printf("\n5.Delete a word.");
        printf("\n6.Delete a definition of a word");
        printf("\n7.Change word");
        printf("\n8.Change definition of a word");
		printf("\n9.Print dictionary to a file");
        printf("\n10.Exit");
        printf("\n\nChose your option: ");
        scanf("%d", &decision);

        switch (decision) {

            case 1:
                printf("\nEnter the word you want to add: ");
                scanf("%s", &decision_1);
                add_word (dictionary, decision_1);
                break;
            case 2:
                printf("\nEnter the word for which you will insert a new definition: ");
                scanf("%s", &decision_1);
                printf("\nEnter the definition: ");
                scanf(" %100[^\n]", &decision_2);
                add_definition (dictionary, decision_1, decision_2);
                break;
            case 3:
                printf("\nEnter the word for which you want to see the definitions: ");
                scanf("%s", &decision_1);
                show_all_definitions (dictionary, decision_1);
                break;
            case 4:
                show_all_words (dictionary);
                break;
            case 5:
                printf("\nEnter the word you want to delete: ");
                scanf("%s", &decision_1);
                delete_word (dictionary, decision_1);
                break;
            case 6:
                printf("\nEnter the word for which you want to delete the definition: ");
                scanf("%s", &decision_1);
                printf("\nEnter the definition you want to delete: ");
                scanf("%s", &decision_2);
                delete_definition (dictionary, decision_1, decision_2);
                break;
            case 7:
                printf("\nEnter the word you want to change: ");
                scanf("%s", &decision_1);
                printf("\nEnter the new word: ");
                scanf("%s", &decision_2);
                change_word (dictionary, decision_1, decision_2);
                break;
            case 8:
                printf("\nEnter the word for which you want to change the definition: ");
                scanf("%s", &decision_1);
                printf("\nEnter the old definition: ");
                scanf("%s", &decision_2);
                printf("\nEnter the new definition: ");
                scanf("%s", &decision_3);
                change_definition (dictionary, decision_1, decision_2, decision_3);
                break;
            case 9:
                save_to_file (dictionary);
				break;
			case 10:
				return 0;
                break;
            default:
                printf("\nInvalid option. Please try again.");
                break;

        }
    }

}

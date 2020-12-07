#include <stdio.h>
#include <stdlib.h>

static void findLetterCode(char* letterCode, char letter, FILE* dictionary) {

    while (fgetc(dictionary) != letter) {
    	// we pass to the next letter in the next line
    	while (fgetc(dictionary) != '\n') {
    	}
    }

    // we set the cursor to the code
    fseek(dictionary, 1, SEEK_CUR);

    fscanf(dictionary, "%s", letterCode);
}

void findTextEncoded(char* text, FILE* textEncoded, FILE* dictionary) {
    int i = 0;

	char* letterCode = (char*)malloc(sizeof(char) *100);

    while (text[i] != '\0') {
        findLetterCode(letterCode, text[i], dictionary);
        fprintf(textEncoded, "%s", letterCode);
        // we reset the dictionary's cursor at the beginning in order to check the letters before the last text's letter encoded
        fseek(dictionary, 0, SEEK_SET);
        ++i;
    }
    free(letterCode);
}

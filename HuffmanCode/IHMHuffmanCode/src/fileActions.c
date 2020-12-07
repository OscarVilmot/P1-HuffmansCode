#include <stdio.h>
#include <stdlib.h>

int findSizeText(FILE* file){
    int size = 0;
    char c = fgetc(file);
    
    while (c != EOF) {
        c = fgetc(file);
        ++size;
    }
    fseek(file, 0, SEEK_SET);

    return size;
}

char* readTxtFile(FILE* fileToRead) {
    char* text = malloc(sizeof(char) * findSizeText(fileToRead));
    fread(text, sizeof(char), findSizeText(fileToRead), fileToRead);

    return text;
}

void writeInTxtFile(char* textToWriteInFile, FILE* fileToWrite) {
    fputs(textToWriteInFile, fileToWrite);
}

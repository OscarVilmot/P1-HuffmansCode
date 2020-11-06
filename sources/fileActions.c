/**
 * \file filesActions.c
 * \brief Source where all tree-related function take places
 * \date 21 oct. 2020
 * \author Kylian.S, Tommy Lee.A, Joel.G, Jules.R, Oscar.V
 * \version 0.1
 *
 * Compression program using Huffman Algorith, with trees and queues
 *
 */

#include "../headers/structures.h"

int size_text(FILE* file){
    int size = 0;
    char c;
    /*
    do{
        c = fgetc(file);
        if (c != EOF)	size++;
    }while(c != EOF);
    rewind(file);
    */
    return size;
}

char* read_txt(){
    FILE* file = NULL;
    char* string = "";
    printf("test1\n\n\n");
    file = fopen("../text.txt", "r");

    printf("%d\n\n\n", size_text(file));

    if (file != NULL){
    	printf("%d\n\n\n", size_text(file));
        string = malloc(sizeof(char)*size_text(file));
        fread(string, sizeof(char), size_text(file), file);
        fclose(file);
    }
    return string;
}

void write_txt(char* binary){
    FILE* file = NULL;
    file = fopen("../binary.txt", "w+");
    if (file != NULL){
        fwrite(binary, sizeof(char), size_text(file), file);
        fclose(file);
    }
}

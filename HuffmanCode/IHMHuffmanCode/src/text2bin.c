static void char2bin(char letter, char decToBin[9]) {
    int letterToDec = (int) letter;
    int i = 7;

    // we convert the letter to binary
    while (letterToDec != 0) {
        decToBin[i] = (char) letterToDec % 2 + 48;
        letterToDec /= 2;
        --i;
    }

    // then we add the zeros
    while (i >= 0) {
        decToBin[i] = '0';
        --i;
    }
}

void text2bin(char* text, char* textInBinary) {
	int i = 0;
    char characterInBinary[9];

	while (text[i] != '\0') {
		char2bin(text[i], characterInBinary);
        // we fill each character of characterInBinary to the text by using this loop
		for (int j = 0; j < 8; ++j) {
            textInBinary[8 * i + j] = characterInBinary[j];
        }
        ++i;
	}
}

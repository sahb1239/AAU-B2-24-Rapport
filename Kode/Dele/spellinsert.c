int insert (const char *input, char** output, int startIndex) {
	int i, j, k, l;
	for (j = 0, i = startIndex, l = 0; j < strlen(ALPHABET); j++) {
		for (k = 0; k < strlen(input) + 1; k++, i++, l++) {
			output[i] = (char *)malloc((strlen(input) + 2) * sizeof(char)); /* Plads til 0 tegnet og et ekstra tegn */
			
			/* Tjek pointeren */
			checkPTRALLOC((void **)&output[i]);
			
			/* Kopierer input */
			strcpy(output[i], input);
			
			/* Rykker memory og indsætter bogstav */
			memmove(output[i] + (k + 1) * sizeof(char), output[i] + k * sizeof(char), strlen(input) - k);
			output[i][k] = ALPHABET[j];
			
			/* Indsætter \0 tegnet */
			output[i][strlen(input) + 1] = '\0';
		}
	}
	
	return l;
}
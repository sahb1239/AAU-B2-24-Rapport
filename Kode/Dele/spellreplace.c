int replace(const char *input, char **output, int startIndex) {
	int i, j, k, l;
	for (j = 0, i = startIndex, l = 0; j < strlen(ALPHABET); j++) {
		for (k = 0; k < strlen(input); k++, i++, l++) {
			output[i] = (char *)malloc((strlen(input) + 1) * sizeof(char)); /* Plads til \0 */
			/* Tjek pointeren */
			checkPTRALLOC((void **) &output[i]);
			
			/* Kopierer input */
			strcpy(output[i], input);
			
			output[i][k] = ALPHABET[j];
		}
	}
		
	return l;
}
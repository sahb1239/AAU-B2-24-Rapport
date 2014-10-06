int deletion (const char *input, char **output, int startIndex) {
	int i, j;
	for (i = startIndex, j = 0; j < strlen(input); i++, j++) {
		output[i] = (char *)malloc(strlen(input) * sizeof(char));
		/* Tjek pointeren */
		checkPTRALLOC((void **)&output[i]);
		
		/* Kopierer input (uden 0 tegnet) */
		strncpy(output[i], input, strlen(input));
		
		memmove(output[i] + (j * sizeof(char)), output[i] + ((j + 1) * sizeof(char)), strlen(input) - j - 1);
		
		/* Indsætter 0 tegnet */
		output[i][strlen(input) - 1] = '\0';
	}
	
	return j;
}
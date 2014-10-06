int transpose(const char *input, char **output, int startIndex) {
	int outLen = findTranspotionsLen(input), i, j;
	for (i = startIndex, j = 0; j < outLen; i++, j++) {
		output[i] = (char *)malloc((strlen(input) + 1) * sizeof(char)); /* Plads til \0 */
		
		/* Tjek pointeren */
		checkPTRALLOC((void **) &output[i]);
		
		/* Kopierer input */
		strcpy(output[i], input);
		
		char tmp = output[i][j];
		output[i][j] = output[i][j + 1];
		output[i][j + 1] = tmp;
	}
	
	return j;
}
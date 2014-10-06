char **database_extract (int *len) {
	int i, alloc_size = DATABASE_SIZE;
	FILE *file = fopen(FILE_WORDS, "r");
	char **out = malloc(alloc_size * sizeof(char *));
	
	/* Tjek pointeren */
	checkPTRALLOC((void **) &out);
	
	for (i = 0; !feof(file); i++) {
		out[i] = malloc(DATABASE_SIZE_WORD * sizeof(char));
		fscanf(file, " %s", out[i]);
		
		if (i >= alloc_size) {
			out[i] = realloc(out[i], sizeof(char *) * (alloc_size += DATABASE_SIZE));
			
			/* Tjek pointeren */
			checkPTRALLOC((void **) &out[i]);	
		}
	}
	
	fclose(file);
	
	/* Output */
	*len = i;
	return out;
}
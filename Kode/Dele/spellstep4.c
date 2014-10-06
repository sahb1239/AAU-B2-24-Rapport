  	/* Punkt 4: Redigering af input til redigeringsafstand 2. */
  	/* Find total mængde der skal allokeres af plads */
  	int totalLen2 = 0;
  	for (j = 0; j < totalLen; j++) {
  		totalLen2 += findInsertLen(combinations[j]) + findDeletionLen(combinations[j]) + 
  					  findReplaceLen(combinations[j]) + findTranspotionsLen(combinations[j]);
  	}
  	
  	char **combinations2 = malloc(totalLen2 * sizeof(char *));
  	/* Tjek pointeren */
  	checkPTRALLOC((void **) &combinations2);
  	
	int startIndex2 = 0;
  	for (i = 0; i < totalLen; i++) {
  		startIndex2 += insert(combinations[i], combinations2, startIndex2);
  		startIndex2 += deletion(combinations[i], combinations2, startIndex2);
  		startIndex2 += replace(combinations[i], combinations2, startIndex2);
  		startIndex2 += transpose(combinations[i], combinations2, startIndex2);

		/* Fjerner gammel memory */
		free(combinations[i]);
  	}
	free(combinations);
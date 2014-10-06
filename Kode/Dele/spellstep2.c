  	/* Punkt 2: redigering af input */
  	int totalLen = findInsertLen(input) + findDeletionLen(input) + findReplaceLen(input) + findTranspotionsLen(input);
  	char **combinations = malloc(totalLen * sizeof(char *));
	int startIndex = 0;
	
	/* Tjek pointeren */
	checkPTRALLOC((void **) &combinations);
	
  	startIndex += insert(input, combinations, startIndex);
  	startIndex += deletion(input, combinations, startIndex);
  	startIndex += replace(input, combinations, startIndex);
  	startIndex += transpose(input, combinations, startIndex);
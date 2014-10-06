  	/* Punkt 3: sammenligning af output fra edit1 med input. Tjek om der er flere match og returner det første element. */
  	int matchingWordsNum = 0;
  	char *matchingWords[20];
  	for (i = 0; i < totalLen; i++) {
  		for (j = 0; j < num_words; j++) {
  	 		if (strcmpI(combinations[i], db_words[j]) == 0) {
  	 			matchingWords[matchingWordsNum] = malloc(strlen(combinations[i]) * sizeof(char));
  	 			
  	 			/* Tjek pointeren */
  	 			checkPTRALLOC((void **) &matchingWords[matchingWordsNum]);
  	 			
  	 			strcpy(matchingWords[matchingWordsNum++], combinations[i]);
  			}
  		}
  	}
  	
  	if (matchingWordsNum > 0) {
  		*likeness = 60;
  		
  		/* Tjek om der er flere der er lig med hinanden */
  		for (i = 0; i < matchingWordsNum; i++)
  			for (j = 0; j < matchingWordsNum; j++)
  				if (i != j && strcmpI(matchingWords[i], matchingWords[j]) != 0)
  					*likeness = 30;
  	
  		char *tmp = malloc((strlen(matchingWords[0]) + 1) * sizeof(char));
  		
  		/* Tjek pointeren */
  		checkPTRALLOC((void **) &tmp);
  		
  		strcpy(tmp, matchingWords[0]);
  		
  		for (j = 0; j < num_words; j++)
			free(db_words[j]);
		free(db_words);
  	 	
  		for (j = 0; j < totalLen; j++)
  			free(combinations[j]);
  		free(combinations);
  		
  		return tmp;
  	}
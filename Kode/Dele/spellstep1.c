	/* Punkt 1: compare af input og database ord. */
  	for (i = 0; i < num_words; i++) {
    	if (strcmpI(input, db_words[i]) == 0) {
	  		/* Rydder op og returnerer */
	  		for (j = 0; j < num_words; j++)
	  			free(db_words[j]);
			free(db_words);
			
			*likeness = 100;
	  		
	  		char *tmp = malloc((strlen(input) + 1) * sizeof(char));
	  		/* Tjek pointeren */
	  		checkPTRALLOC((void **) &tmp);
	  		
  			strcpy(tmp, input);
  			return tmp;
		}
  	}
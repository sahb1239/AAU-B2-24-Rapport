  	/* Punkt 5: sammenligning af output fra edit2 med input. Returnering hvis match. */
  	for (i = 0; i < totalLen2; i++) {
  		for (j = 0; j < num_words; j++) {
  	 		if (strcmpI(combinations2[i], db_words[j]) == 0) {
  	 			char *out = malloc((strlen(combinations2[i]) + 1) * sizeof(char));
  	 			
  	 			/* Tjek pointeren */
  	 			checkPTRALLOC((void **) &out);
  	 			
  	 			strcpy(out, combinations2[i]);
  	 			
  	 			/* Rydder op */
  	 			for (j = 0; j < num_words; j++)
	  				free(db_words[j]);
				free(db_words);
  	 			
  	 			for (j = 0; j < totalLen2; j++)
  	 				free(combinations2[j]);
  	 			free(combinations2);
  	 		
  	 			*likeness = 20;
  	 			/* Returnerer */
  				return out;
  			}
  		}
  	}
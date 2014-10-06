  	/* Rydder op */
  	for (j = 0; j < num_words; j++)
		free(db_words[j]);
	free(db_words);
  	 			
  	for (j = 0; j < totalLen2; j++)
  	 	free(combinations2[j]);
  	free(combinations2);
  	
  	/* Punkt 6: Hvis enden nås uden at en korrektion findes returneres en null pointer. */
  	return NULL;
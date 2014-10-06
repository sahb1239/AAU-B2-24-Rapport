	int i, j, numactions;
	
	/* Generer actions */
	ACTIONTYPE type;
	char* controlScenarieTmp[5]; 
	char position[POSITION_NAME_LEN];
	
	/* Find kommando */
	for (i = 0, numactions = 0; i < len; i++) { /* *** Burde denne også splittes op i en bette funktion? *** */
		/* Find keyword */
		if (strcmpI(input[i], "tænd") == 0 || strcmpI(input[i], "taend") == 0)
			type = turn_on;
		else if /* ... */
		
		/* Find controllers */
		for (j = 0; j < *controllersLen; j++) {
			if (strcmpI(input[i], controllers[j].unit) == 0)
				controlScenarieTmp[numactions++] = input[i];
				
			if (strcmpI(input[i], controllers[j].position) == 0)
				strcpy(position, input[i]);
		}
		
		/* Find scenarier */
		for (j = 0; j < *scenarierLen; j++) {
			if (strcmpI(input[i], scenarier[j].desc) == 0)
				controlScenarieTmp[numactions++] = input[i];
		}
	}
int findAndExecuteCommand(char *input[], int len, CONTROLLERS controllers[], int *controllersLen, SCENARIE scenarier[], int *scenarierLen, USERS users[], int *usersLen, USERS *currentUser) {
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
		else if (strcmpI(input[i], "sluk") == 0)
			type = turn_off;
		else if (strcmpI(input[i], "status") == 0)
			type = status;
        ...
        else if (strcmpI(input[i], "hjælp") == 0 || strcmpI(input[i], "hjaelp") == 0)
            type = help;
        ...
		
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
	
	if (numactions > 0)
        return executeNormalCommand(controllers, scenarier, controlScenarieTmp, position, controllersLen, scenarierLen, numactions, type, currentUser);
	else
        return executeSpecialCommand(controllers, scenarier, users, controlScenarieTmp, position, controllersLen, scenarierLen, usersLen, numactions, type, currentUser);
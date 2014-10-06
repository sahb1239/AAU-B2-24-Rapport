int findAndExecuteCommand(char *input[], int len, CONTROLLERS controllers[], int *controllersLen, SCENARIE scenarier[], int *scenarierLen, USERS users[], int *usersLen, USERS *currentUser) {
	int i, j, numactions;
    
    /* Generer actions */
	ACTIONTYPE type;
	char* controlScenarieTmp[5];                                                        /* Dette er en double pointer til controlScenarie[5] (Indeholder alle controllere eller senarier) */
	char position[POSITION_NAME_LEN];                                                   /* Position må være en pointer til den symbolske konstant POSITION_NAME_LEN */
	
	/* Find kommando */                                                                 /* strcmpI er en funktion som vi selv har lavet for at lave lowercase */
	for (i = 0, numactions = 0; i < len; i++) {                                         /* For-løkken bruges til at gå igennem hvert ord i strengen "jarvis tænd computer på kontor */
                                                                                        /* Find keyword (Nedenstående kode betyder at den ud fra strcmpI sammenligner input[i] med tænd og hvis de er ens så er typen = turn-on og dette er fælles for alle nedenstående i switch-casen */
		if (strcmpI(input[i], "tænd") == 0 || strcmpI(input[i], "taend") == 0)
			type = turn_on;
		else if (strcmpI(input[i], "sluk") == 0)
			type = turn_off;
		else if (strcmpI(input[i], "status") == 0)
			type = status;
		else if (strcmpI(input[i], "scenarie") == 0)
			type = scenarie;
        ...    
        else if (strcmpI(input[i], "hjælp") == 0 || strcmpI(input[i], "hjaelp") == 0)
            type = help;
        ...    
      
		
		/* Find controllers */ 
		for (j = 0; j < *controllersLen; j++) {                                         /* Kører for-løkken igennem ved at j < *controllersLen (*controllersLen = "længden af controllerne/antal fastlagte controllere */
			if (strcmpI(input[i], controllers[j].unit) == 0)                            /* input[i] bliver sammenlignet med controllers[j].unit og hvis de er = med hinanden */
				controlScenarieTmp[numactions++] = input[i];                            /* numaction++ bliver talt op med en */
				
			if (strcmpI(input[i], controllers[j].position) == 0)                        /* Her kører der det samme igennem, bare for controllers[j].position */
				strcpy(position, input[i]);                                             /* Her kopieres position ind */
		}
		
		/* Find scenarier */
		for (j = 0; j < *scenarierLen; j++) {                                           /* Her køres der igen igennem en for-løkke på samme måde som ved controllers */
			if (strcmpI(input[i], scenarier[j].desc) == 0)                              /* Igen bliver der sammenlignet, dog er det describtion af senarier (scenarier[j].desc) */
				controlScenarieTmp[numactions++] = input[i];
		}
	}
	
	if (numactions > 0)                                                                 /* Her står der at hvis numaction > 0 skal funktionen executeNormalCommand kører ellers skal executeSpecialCommand funktionen */
        return executeNormalCommand(controllers, scenarier, controlScenarieTmp, position, controllersLen, scenarierLen, numactions, type, currentUser);
	else
        return executeSpecialCommand(controllers, scenarier, users, controlScenarieTmp, position, controllersLen, scenarierLen, usersLen, numactions, type, currentUser);

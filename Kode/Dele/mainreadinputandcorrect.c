	while(1) {
		printf("Indtast input => ");
		if (scanf(" %[^\n]s", voiceinput)) {
			/* Split input string (char *) op til et string array (char **) efter ord */
			char *splittedInput[SPLITTED_INPUT_LEN], **selIndex = NULL;
			int numwords = splitString(voiceinput, splittedInput, SPLITTED_INPUT_LEN),
				totalwords = numwords,
				likeness,
				acceptcorrection = 0;
			
			/* Udfør stavekontrol på input - ignorerer output */
			correctInput(splittedInput, &likeness, numwords);
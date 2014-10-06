			/* Tjekker hvilket index ordet UNIT_NAME ligger i og sætter pointeren selIndex til positionen */
			for (i = 0; i < numwords; i++) {
				if (strcmpI(splittedInput[i], UNIT_NAME) == 0) {
					numwords -= i + 1;
					selIndex = splittedInput + (i + 1) * sizeof(char); /* Sizeof char is 1 */
					break;
				}
			}
			
			if (selIndex != NULL) {
				/* Udfør stavekontrol igen og fortsæt kun denne gang hvis at alle ord kunne findes - vi bruger likeness fra tidligere kørsel af stavekontrollen */
				int tmp;
				if (correctInput(selIndex, &tmp, numwords)) {
					/* Kopirer rettet input hvis lighedsgraden er mindre end lighedsgraden tilladt */
					if (!(likeness > PERCENT_UNDERSTOOD_OK)) {
						for (i = 0; i < numwords; i++) {
							strcpy(voiceInputPtr, selIndex[i]);
							
							voiceInputPtr += (strlen(selIndex[i]) * sizeof(char));
							
							/* Tilføj mellemrum */
							voiceInputPtr[0] = ' ';
							
							/* Tæl pointeren op */
							voiceInputPtr += sizeof(char);
						}
						
						/* Afslut med \0 tegnet */
						voiceInputPtr[0] = '\0';
					}
					
					/* Finder ud af om rettelsen skal accepteres */
					acceptcorrection = likeness > PERCENT_UNDERSTOOD_OK || 
										yesno(voiceinput);
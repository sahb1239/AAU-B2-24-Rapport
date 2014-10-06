				/* Udfør kommandoen */
				if (acceptcorrection) {
					if (!findAndExecuteCommand(selIndex, numwords, controllers, &controller_len, scenarier, &scenarie_len, users, &users_len, &currentUser))
						printf(NOTUNDERSTOOD_TEXT, aa);
				}
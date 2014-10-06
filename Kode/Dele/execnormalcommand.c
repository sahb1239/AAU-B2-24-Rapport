int executeNormalCommand (CONTROLLERS controllers[], SCENARIE scenarier[], char *controlScenarieTmp[], char position[], int *controllersLen, int *scenarierLen, int numactions, ACTIONTYPE type, USERS *currentUser) {
	int i, index;
   	for (i = 0; i < numactions; i++) {
        switch (type) {
            case turn_on: case turn_off:
                index = findControllerFromName(controllers, controlScenarieTmp[i], position, *controllersLen);
                
                if (index < 0)
                    return 0;
                             
                changeControllerState(controllers, index, type == turn_on ? 1 : 0, *controllersLen);
                break;
            case status:
                index = findControllerFromName(controllers, controlScenarieTmp[i], position, *controllersLen);
                                
                if (index < 0)
                    return 0;
                        
                /* Print status */
                statusControllerPrint(controllers, index);
                break;
            case scenarie:
            	index = findScenarieFromName(scenarier, controlScenarieTmp[i], *scenarierLen);
            	
            	if (index < 0)
            		return 0;
            
                if (runScenarie(scenarier[index], controllers, *controllersLen, *currentUser) == 0)
                   printf("%s", NOT_ALLOWED_TEXT);
                break;
            default:
                /* Fejl - burde være endt nede i anden gruppe */
                return 0;
            }
    }
        
    return numactions;
}
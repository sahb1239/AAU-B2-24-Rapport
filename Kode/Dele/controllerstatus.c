void statusControllerPrint (const CONTROLLERS controllers[], int index) {
	char status[STATUS_LEN];
	
	if (controllers[index].status)
    	sprintf(status, "t%sndt", ae);
	else
    	strcpy(status, "slukket");
	
	printf("%s i %s er %s\n", controllers[index].unit, controllers[index].position, status);
}

void statusControllerPrintAll (const CONTROLLERS controllers[], int len) {
    int i;
    char status[STATUS_LEN];
    
    printf("ID     GENSTAND             PLACERING                 STATUS\n\n");
    
    for (i = 0; i < len; i++) {
    	if (controllers[i].status)
    		sprintf(status, "T%sndt", ae);
    	else
    		strcpy(status, "Slukket");
    	
       	printf("#%d %-20s %-25s %s\n", controllers[i].id, controllers[i].unit, controllers[i].position, status); 
    }
}
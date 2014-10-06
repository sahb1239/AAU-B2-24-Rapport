int runScenarie (SCENARIE scenarie, CONTROLLERS controllers[], int len, USERS currentUser) {
    int i;
    char status[STATUS_LEN];
    
    /* Vi starter med at tjekke om brugeren har adgang til dette scenarie */
    switch (currentUser.priority) {
       case 1:
          if (scenarie.allow_p1 != 1) return 0;
          break;
       case 2:
          if (scenarie.allow_p2 != 1) return 0;
          break;
       case 3:
          if (scenarie.allow_p3 != 1) return 0;
          break;
    }
          
    
    if (scenarie.c1_id == 0) {
       	if (scenarie.c1_state)
          	sprintf(status, "t%sndt", ae);
       	else
    	  	strcpy(status, "slukket");
          
       	for (i = 0; i < len; i++)
          	changeControllerState(controllers, i, scenarie.c1_state, len); 
       
       	printf("Alt er nu %s\n", status);
    }
    else {
    	changeControllerState(controllers, findControllerFromId(controllers, scenarie.c1_id, len), scenarie.c1_state, len);
       	changeControllerState(controllers, findControllerFromId(controllers, scenarie.c2_id, len), scenarie.c2_state, len);
       	changeControllerState(controllers, findControllerFromId(controllers, scenarie.c3_id, len), scenarie.c3_state, len);
    }
    return 1;
}
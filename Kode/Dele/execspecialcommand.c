int executeSpecialCommand (CONTROLLERS controllers[], SCENARIE scenarier[], USERS users[], char *controlScenarieTmp[], char position[], int *controllersLen, int *scenarierLen, int *usersLen, int numactions, ACTIONTYPE type, USERS *currentUser) {
   switch (type) {
      case add_controller:                
         if (!addController(controllers, controllersLen)) 
         	return 0;
         	
         printf("Controlleren er tilf%sjet!\n", oe);
         return 1;
      case remove_controller:
         if (!removeController(controllers, controllersLen)) 
         	return 0;
         	
         printf("Controlleren er fjernet!\n");
         return 1;
      case add_scenarie:
         if (!addScenarie(scenarier, scenarierLen)) 
         	return 0;
         	
         printf("Scenariet er tilf%sjet!\n", oe);
         return 1;
      case remove_scenarie:
         if (!removeScenarie(scenarier, scenarierLen)) 
         	return 0;
         	
         printf("Scenariet er fjernet!\n"); 
         return 1;
      case add_user:
         if (addUser(users, *usersLen) == -1) return 0;
         printf("Brugeren er nu tilf%sjet!\n", oe); (*usersLen)++;
         return 1;
      case remove_user:
         if (removeUser(users, *usersLen) == -1) return 0;
         printf("Brugeren er nu slettet!\n"); (*usersLen)--;
         return 1;
      case help:
         helpMe();
         return 1;
      case status_all:
         statusControllerPrintAll(controllers, *controllersLen);
         return 1;
      case scenarie_all:
          printAllScenarier(scenarier, *scenarierLen);
         return 1;
      case switch_user:
          selectUser(users, *usersLen, currentUser);
          return 1;
      default:
         /* Fejl - burde være endt i anden gruppe */
         return 0;
        }
}
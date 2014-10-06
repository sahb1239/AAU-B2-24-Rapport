	int i, scenarie_len, controller_len, users_len;
	char voiceinput[INPUT_SIZE];
    SCENARIE scenarier[SCENARIE_SIZE];
    CONTROLLERS controllers[CONTROLLER_SIZE];
    USERS users[USERS_SIZE], currentUser;
    
    /* Indlæser scenarier og controllers og gemmer antallet af elemnter læst */
	scenarie_len = readScenarie(scenarier);
    controller_len = readControllers(controllers);
    users_len = readUsers(users);
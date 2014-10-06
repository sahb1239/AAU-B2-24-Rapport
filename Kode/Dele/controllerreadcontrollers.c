int readControllers(CONTROLLERS controllers[]) {
	int i = 0;

	FILE *pFile = fopen(FILE_CONTROLLERS, "r");
	if (pFile == NULL)
		return 0;
   
    for (i = 0; !feof(pFile); i++) {
    	fscanf(pFile, " #%d %[0-9a-zA-Z ]s", &controllers[i].id, controllers[i].unit);
       	fscanf(pFile, "; %[0-9a-zA-Z ]s", controllers[i].position);
       	controllers[i].status = 0;
    }
    
	fclose(pFile);

	return i;
}
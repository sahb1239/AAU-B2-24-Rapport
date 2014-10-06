int saveControllers(const CONTROLLERS controllers[], int len) {
    int i;
    
    FILE *pFile = fopen(FILE_CONTROLLERS, "w");
    
    if (pFile == NULL) {
	  	return 0;
	}
    
    for (i = 0; i < len; i++) {
      	fprintf(pFile, "\n#%d\t%s;\t%s",  controllers[i].id, controllers[i].unit, controllers[i].position); 
    }
	
    fclose(pFile);
    
    return 1;
}
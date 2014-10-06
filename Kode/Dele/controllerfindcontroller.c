int findControllerFromName(const CONTROLLERS controllers[], const char name[], const char room[], int len) {
   int i;
   
   for (i = 0; i < len; i++) {
      if (strcmpI(room, controllers[i].position) == 0 && strcmpI(name, controllers[i].unit) == 0) {
         return i;
      }
   }
   return ERROR_OCCURRED;
}

int findControllerFromId(const CONTROLLERS controllers[], int cid, int len) {
	int i;
	
	for (i = 0; i < len; i++) {
		if (controllers[i].id == cid)
			return i;
	}
	
	return ERROR_OCCURRED;
}
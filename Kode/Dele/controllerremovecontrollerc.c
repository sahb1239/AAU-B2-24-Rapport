int removeControllerC(CONTROLLERS controllers[], int index, int *len) {
    int i;
    
    /* Tæller længden 1 ned */
    (*len)--;
    
    /* Rykker alle efterfølgende elementer (efter index) en plads tilbage */
	for (i = index; i < *len; i++) {
    	controllers[i] = controllers[i + 1];
    }
    
    return saveControllers(controllers, *len);
}
int addController(CONTROLLERS controllers[], int *len) {
	CONTROLLERS controller;
	
	readInputController(controller.unit, controller.position);
	return addControllerC(controllers, controller, len);
}

int removeController(CONTROLLERS controllers[], int *len) {
    CONTROLLERS controller;
	
	readInputController(controller.unit, controller.position);
	
	int index = findControllerFromName(controllers, controller.unit, controller.position, *len);
	if (index != ERROR_OCCURRED)
		return removeControllerC(controllers, index , len);
	else
		return 0;
}
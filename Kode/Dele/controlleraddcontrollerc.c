int addControllerC(CONTROLLERS controllers[], CONTROLLERS controller, int *len) {
	controllers[*len].id = controllers[*len - 1].id + 1;
	controllers[*len].status = controller.status;
	strcpy(controllers[*len].unit, controller.unit);
	strcpy(controllers[*len].position, controller.position);
	
	return saveControllers(controllers, ++(*len));
}
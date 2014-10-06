void changeControllerState(CONTROLLERS controllers[], int index, int state, int len) {
	controllers[index].status = state;
	statusControllerPrint(controllers, index);
	saveControllers(controllers, len);
}
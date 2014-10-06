	if (numactions > 0)
        return executeNormalCommand(controllers, scenarier, controlScenarieTmp, position, controllersLen, scenarierLen, numactions, type, currentUser);
	else
        return executeSpecialCommand(controllers, scenarier, users, controlScenarieTmp, position, controllersLen, scenarierLen, usersLen, numactions, type, currentUser);
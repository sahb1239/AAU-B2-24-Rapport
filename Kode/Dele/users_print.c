void printUsers(const USERS users[], int len) {
    int i;
    printf("Prioritet:\tBruger:\n");
    
    for (i = 0; i < len; i++) {
    	printf("%d\t\t%s\n", users[i].priority, users[i].name);
	}
}
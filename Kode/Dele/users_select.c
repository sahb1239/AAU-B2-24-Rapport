void selectUser(const USERS users[], int len, USERS *currentUser) {
   int i;
   USERS tmpUser;
   readInputUser(tmpUser.name, 0, &tmpUser.priority);
   
   for (i = 0; i < len; i++) {
     if (strcmpI(tmpUser.name, users[i].name) == 0) {
        strcpy(currentUser->name, users[i].name);
        currentUser->priority = users[i].priority; }
   }
}
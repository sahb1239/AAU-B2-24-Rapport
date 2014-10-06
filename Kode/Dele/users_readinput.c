void readInputUser(char name[], int askPriority, int *priority) {
	printf("Hvilken person er der tale om?\nIndtast input => ");
    scanf("%s", name);    
    if (askPriority == 1) {
      printf("Hvilken prioritet?\nIndtast input => ");
      scanf("%d", priority); }
}
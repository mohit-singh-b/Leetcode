int comp(const void *a, const void *b) {
    return ( *(int*)a - *(int*)b );
}int numRescueBoats(int* people, int peopleSize, int limit) {
    int i , total = 0 ,min ,head = 0 , tail = peopleSize;

    qsort(people,peopleSize,sizeof(int),comp);

    if ( peopleSize == 1)
        return 1;

    while(head<tail){
        min = people[head++];
        while ( head< tail && min + people[tail-1] > limit  ){
            total++;
            tail--;
        }a
        tail--;
        total++;
    }

    return total;
   
}

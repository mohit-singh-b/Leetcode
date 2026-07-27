void push(int *, int * , int);
void  pop(int *,int*);

bool isValid(char* s) {
    int top=-1,max=200;
    char c;
    int *stack = calloc(max,sizeof(int));
    for (int i = 0 ; s[i] != '\0' ; i++ ){        

        if (top < 0)
        {
           push(stack,&top,s[i]);
        }
        else {
        
            if ((s[i] - stack[top]) <=2 && (s[i] - stack[top]) > 0 ){
                pop(stack,&top);
            }
            else {
                push(stack,&top,s[i]);
            }
        }

        if ( max - top <= 10){
            max+=200;
            stack = realloc(stack,max*sizeof(int));}
    }
    

    return top == -1 ? true : false;
}

void push ( int *s , int * top,int e){
    (*top)++;
    s[*top] = e;
}

void pop(int *s , int *top){
    s[*top] = 0;
    (*top)--;
}
typedef struct Stack{
    int count;
    char *str;
}Stack;

char* decodeString(char* s) {
    char *output , *cstr,c;
    int count = 0,digit, i , top = -1 ,ciout =0,cistr=0;
    int k,d;

    Stack *stack = calloc(100,sizeof(Stack));
    output = calloc(100000,sizeof(char));
    cstr = calloc(10000,sizeof(char));

    for ( i = 0 ; s[i] != 0 ; i++){
        c = s[i];

        if ( c >= '0' && c <= '9'){
            d = c-48;
            count = count*10 + d;
        }
        else if ( c == '['){
            stack[++top].count = count;
            stack[top].str = calloc(10000,sizeof(char));
            count = 0;
        }
        else if( c >= 'a' && c <= 'z'){
            if(top > -1)
                {int len = strlen(stack[top].str);
                (stack[top].str)[len] = c;
                (stack[top].str)[len+1] =0;}
            else{
                int len = strlen(output);
                output[len] = c;
                output[len+1] =0; 
            }
        }
        else if ( c == ']'){
            k = stack[top].count;
            char *s = strdup(stack[top].str);
            printf(" %d (%d , %s)\n",top,stack[top].count,stack[top].str);
            for ( int m = 0 ; m < k-1; m++){
                strcat(stack[top].str,s);
            }
            free(s);
            printf(" %d (%d , %s)\n",top,stack[top].count,stack[top].str);
            if ( top > 0){
                strcat(stack[top-1].str ,stack[top].str);
                top--;
                
            }
            else {
                strcpy(cstr,stack[top].str);
                free(stack[top].str);
                top--;
            }
    
            }
             if ( top == -1){
                strcat(output,cstr);
                cstr[0] = 0;
        }
        

    }

    return output;
    
}



typedef struct {
    int *stack;
    int top;
    int *minstack;
    
    
} MinStack;


MinStack* minStackCreate() {
    
    MinStack *obj = calloc(1,sizeof(MinStack));
    obj->stack = malloc(100000*sizeof(int));
    obj->top = -1;
    obj->minstack = malloc(100000*sizeof(int));

    return obj;
}

void minStackPush(MinStack* obj, int value) {
    if ( obj->top == -1){
        obj->top++;
        obj->minstack[obj->top] = value;
        obj->stack[obj->top] = value;
        return ;
    }   

    if( value < obj->minstack[obj->top]){
        obj->top++;
        obj->minstack[obj->top] = value;
    } 
    else {
        obj->top++;
        obj->minstack[obj->top] = obj->minstack[obj->top-1];
    }
    
    obj->stack[obj->top] = value;
    
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minstack[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->minstack);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, value);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack is Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Underflow\t cannot pop from stack\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack *sp,int i){
        int arrayInd =  sp->top -i + 1 ;
        if(arrayInd<0){
            printf("Not a valid position");
            return -1;
        }
        else{
            return sp->arr[arrayInd];
        }
    }

    int stackTop(struct stack *sp){
        return sp->arr[sp->top];
    }

     int stackBottom(struct stack *sp){
        return sp->arr[0];
    }
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");

    printf("Before pushing ,full:%d\n", isFull(sp));
    printf("Before pushing ,Empty:%d\n", isEmpty(sp));
    push(sp, 56);
    push(sp, 6);
    push(sp, 5);
    push(sp, 46);
    push(sp, 0);
    push(sp, 87);
    push(sp, 9);
    push(sp, 4);
    push(sp, 45);
    push(sp, 67);

    printf("After pushing ,full:%d\n", isFull(sp));
    printf("After pushing ,Empty:%d\n", isEmpty(sp));

    printf("Popped %d from stack:\n", pop(sp));
    for(int j=1 ;j<=sp->top+1;j++){

    printf("The value at position %d is %d\n",j,peek(sp,j));
    }
    printf("The topmost value of this stack %d\n", stackTop(sp));
    printf("The Bottommost value of this stack %d\n", stackBottom(sp));
    
    return 0;
}
#include<stdio.h>
#include<stdbool.h>
int top =-1,i;
bool expression (char exp[]){
    char stack[50];
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='{'||exp[i]=='('||exp[i]=='['){
            top++;
            stack[top]=exp[i];
        }
        else if(exp[i]=='}'||exp[i]==')'||exp[i]==']'){
            if(top==-1){
                return false;
            }
        if((exp[i]=='}'&& stack[top]=='{')||(exp[i]==']'&& stack[top]=='[')||(exp[i]==')'&& stack[top]=='(')){
            top--;
           }
            else{
            return false;
            }
        
        }
    }
return top==-1;
}


int main(){
    char exp[50];
    printf("Enter the Expression\n");
    
    scanf("%s",exp);
    if(expression(exp)){
        printf("expression is balaced and order\n");
    }
    else{
        printf("expression is not balaced and order\n");
    }
    expression(exp);
}
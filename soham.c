#include<stdio.h>
int main(){  
char a;
int x,y;

   printf("What do you want to perform;(+),(-),(*),(/):");
   scanf("%c", &a);
   if(a !='-' || a !='+' || a !='/' || a !='*'){
    printf("Invalid Operator ");
    return 1;
   }
  
    printf("Enter 1st Number:");
    if(scanf("%d",&x)!=1){
        printf("Invalid Input");
        return 1;
    }
 else {
    printf("Enter The 2nd Number:");
    if(scanf("%d",&y) !=1){
        printf("Invalid Input");
        return 1;
    }
 }
switch (a){
    case '+':
    printf("The Sum of The Two Number is:%d",x+y);
break;

    case '-':
    printf("The Subtraction of The Two Number is:%d",x-y);
break;

    case '*':
printf("The Multiplication of the Two Number is:%d",x*y);
break;

    case '/' :
printf("The Division of The Two Number is:%d",x/y);
break;
}
    
return 0;   
}














































































































































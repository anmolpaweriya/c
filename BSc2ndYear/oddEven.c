#include<stdio.h>
#include<conio.h>

main(){
int numb;
clrscr();
printf("Enter a Number : ");
scanf("%d",&numb);

numb%2 == 0 ? printf("Even Number"):printf("Odd Number");

getch();
}

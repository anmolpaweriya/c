#include<stdio.h>
#include<conio.h>

main(){
float a,b,c,max;
clrscr();
printf("Enter 3 numbers : ");
scanf("%f%f%f",&a,&b,&c);
max = a>b ? a :b;
max = c>max ? c:max;
printf("\nGreatest Number = %f",max);
getch();
}


#include<stdio.h>
#include<conio.h>

main(){
float a,b;
int choice;

clrscr();
printf("Enter 2 Numbers : ");
scanf("%f%f",&a,&b);

start :
printf("Choose an opeartion : \n");
printf("\t1.)Addition\n");
printf("\t2.)Subtraction\n");
printf("\t3.)Multiplication\n");
printf("\t4.)Division\n");
printf("Enter Your Choice : ");
scanf("%d",&choice);

switch(choice){
case 1:
printf("\nAddition = %f",a+b);
break;
case 2:
printf("\nSubstraction = %f",a-b);
break;
case 3 :
printf("\nMultiplication = %f ",a*b);
break;
case 4:
printf("\nDivision = %f",a/b);
break;
default :
printf("\n[!] Invalid Input\n");
goto start;
}
getch();
}

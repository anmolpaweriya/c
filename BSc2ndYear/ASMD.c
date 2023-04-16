
#include<stdio.h>
#include<conio.h>
#define pf printf

main(){
float a,b;
int choice;

clrscr();
pf("Enter 2 Numbers : ");
scanf("%f%f",&a,&b);

start :
pf("Choose an opeartion : \n");
pf("\t1.)Addition\n");
pf("\t2.)Subtraction\n");
pf("\t3.)Multiplication\n");
pf("\t4.)Division\n");
pf("Enter Your Choice : ");
scanf("%d",&choice);

switch(choice){
case 1:
pf("\nAddition = %f",a+b);
break;
case 2:
pf("\nSubstraction = %f",a-b);
break;
case 3 :
pf("\nMultiplication = %f ",a*b);
break;
case 4:
pf("\nDivision = %f",a/b);
break;
default :
printf("\n[!] Invalid Input\n");
goto start;
}
getch();
}

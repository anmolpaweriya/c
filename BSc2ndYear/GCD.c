#include<stdio.h>
#include<conio.h>

main(){

int a,b,i,gcd=1;
clrscr();
printf("Enter 2 Numbers : ");
scanf("%d%d",&a,&b);
for(i = 1;i<=a&&i<=b;i++){
if(a%i == 0 && b%i == 0){
gcd = i;
}
}
printf("\nGCD = %d", gcd);

getch();
}

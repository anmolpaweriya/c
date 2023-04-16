#include<stdio.h>
#include<conio.h>

int fibo(int l){

if(l == 1) return 0;
if(l == 2) return 1;
return fibo(l-1)+fibo(l-2);
}

main(){
int i = 1,len;
clrscr();
printf("Enter length of series : ");
scanf("%d",&len);
printf("\nFibbonacci series --------->");
for(;i<=len;i++){
printf("\n%d",fibo(i));
}
getch();
}

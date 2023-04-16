#include<stdio.h>
#include<conio.h>

void getValue(int a[20][20],int len){
int i,j;
for(i=0;i<len;i++)
for(j=0;j<len;j++){
printf("Enter Element (%dx%d) : ",i+1,j+1);
scanf("%d",&a[i][j]);
}
}

main(){
int a[20][20],b[20][20],result[20][20],i,j,len;
clrscr();

printf("Enter Lenght of Matrix : ");
scanf("%d",&len);
printf("Matrix 1st ------->\n");
getValue(a,len);
printf("Matrix 2nd ------->\n");
getValue(b,len);

for(i=0;i<len;i++)
for(j=0;j<len;j++)
result[i][j] = a[i][j] + b[i][j];

printf("\nResult Matrix -------->\n");
for(i = 0;i<len;i++){
for(j=0;j<len;j++){
printf("\t%d",result[i][j]);
}
printf("\n");
}
getch();
}

#include<stdio.h>
#include<conio.h>

void show(int a[20][20],int len){
int i,j;
for(i = 0;i<len;i++){
for(j = 0;j<len;j++){
printf("\t%d",a[i][j]);
}
printf("\n");
}


}

main(){
int a[20][20],b[20][20],i,j,len;
clrscr();
printf("Enter Length of Matrix : ");
scanf("%d",&len);

for(i= 0;i<len;i++)
for(j= 0;j<len;j++){
printf("Enter Element (%dx%d) : ",i+1,j+1);
scanf("%d",&a[i][j]);
}

printf("matrix --------->\n");

show(a,len);
for(i = 0 ;i<len;i++)
for(j = 0;j<len;j++)
b[i][j] = a[j][i];

printf("Transpose Matrix ---------->\n");

show(b,len);

getch();
}

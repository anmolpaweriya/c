#include<stdio.h>
#include<conio.h>
#include<math.h>
main(){
float a,b,c,d,imgPart,realPart;
clrscr();
printf("General Eq -----> \n");
printf("\t a*x*x + b*x + c = 0 \n");
printf("Enter a,b,c : ");
scanf("%f%f%f",&a,&b,&c);
realPart = -b/(2*a);
d = b*b - 4*a*c;
if(d>0){
printf("\nRoot are real but distinct");
imgPart = sqrt(d)/(2*a);
printf("\n 1st Root = %.2f",realPart+imgPart);
printf("\n 2nd Root = %.2f",realPart - imgPart);


}else if(d == 0){
printf("\nRoots are real and equal");
printf("\n Roots = %.2f",realPart)  ;

}else{
imgPart = sqrt(-d)/(2*a);

printf("\nRoots are Imaginary");
printf("\n1st Root = %.2f + i %.2f",realPart,imgPart);
printf("\n2nd Root = %.2f - i %.2f",realPart,imgPart);
}

getch();

}

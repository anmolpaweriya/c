#include<iostream.h>
#include<conio.h>

class className{
long principal,rate,time;

public :
className(int principal,int rate,int time){
this->principal = principal;
this->rate = rate;
this->time = time;

}

void getValue(){
cout<<"Principal = "<<principal<<endl;
cout<<"Rate = "<<rate<<endl;
cout<<"time = "<<time<<endl;
cout<<"Amount = "<<principal*rate*time/100<<endl;
}

};

main(){
clrscr();

className obj(2500,10,2);
obj.getValue();


 getch();
}

#include <iostream>
#include <iomanip>

using namespace std;

void input(int mpg, double price, int speed, char start, char end, int hours, int distance, int minutes, double preprice){
    cout<<"MPG: ";
    cin>>mpg;           //25
    cout<<"Price: ";
    cin>>price;         //3.79
    cout<<"Speed: ";
    cin>>speed;         //50
    for(int i=1; i<=5; i++){
        minutes=0;
        distance=0;
        cout<<i<<". ";
        cin>>start;     //A
        cout<<i<<". ";
        cin>>end;       //C
        if((start<='A')&&(end>='B')){
            distance+=450;
        }
        if((start<='B')&&(end>='C')){
            distance+=140;
        }
        if((start<='C')&&(end>='D')){
            distance+=120;
        }
        if((start<='D')&&(end>='E')){
            distance+=320;
        }
        if((start<='E')&&(end>='F')){
            distance+=250;
        }
        if((start<='F')&&(end>='G')){
            distance+=80;
        }
        cout<<distance;
        minutes=((distance*60)/speed);
        if(((double(distance)*60)/speed)-minutes>=0.5){
            minutes++;
        }
        hours=minutes/60;
        minutes=minutes%60;
        cout<<", ";
        if(hours<10){
            cout<<"0";
        }
        cout<<hours<<":";
        if(minutes<10){
            cout<<"0";
        }
        cout<<minutes;
        preprice=((double(distance)/double(mpg))*price);
        cout<<", "<<(char)36<<preprice<<endl;
        cout<<endl;
    }
}

int main(){
    cout<<setprecision(2)<<fixed;
    double price, preprice;
    int mpg, speed, hours, minutes, distance;
    char start, end;
    input(mpg, price, speed, start, end, hours, minutes, preprice, distance);
    return 0;
}

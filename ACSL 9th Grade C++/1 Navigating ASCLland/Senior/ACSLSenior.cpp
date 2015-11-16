#include <iostream>
#include <iomanip>

using namespace std;

void input(int hours, int minutes, int distance, int time1, int time2, char start, char end){
    string day1, day2;
    int Ary[2];
    distance=0;
    for(int i; i=5; i++){
        distance=0;
        cout<<"Start: ";
        cin>>start;
        cout<<"End: ";
        cin>>end;
        cout<<"Time #1: ";
        cin>>time1;
        cout<<"AM or PM: ";
        cin>>day1;
        cout<<"Time #2: ";
        cin>>time2;
        cout<<"AM or PM: ";
        cin>>day2;
        cout<<"Speed #1: ";
        cin>>Ary[0];
        cout<<"Speed #2: ";
        cin>>Ary[1];
        if((start<='A')&&(end>='B')){
            distance+=450;
        }
        if((start<='B')&&(end>='C')){
            distance+=140;
        }
        if((start<='C')&&(end>='D')){
            distance+=125;
        }
        if((start<='D')&&(end>='E')){
            distance+=365;
        }
        if((start<='E')&&(end>='F')){
            distance+=250;
        }
        if((start<='F')&&(end>='G')){
            distance+=160;
        }
        if((start<='G')&&(end>='H')){
            distance+=380;
        }
        if((start<='H')&&(end>='J')){
            distance+=235;
        }
        if((start<='J')&&(end>='K')){
            distance+=320;
        }
        cout<<distance;
    }
}

int main(){
    cout<<setprecision(2)<<fixed;
    int hours, minutes, distance, time1, time2;
    char start, end;
    string day1, day2;
    input(hours, minutes, distance, start, end, time1, time2);
    return 0;
}

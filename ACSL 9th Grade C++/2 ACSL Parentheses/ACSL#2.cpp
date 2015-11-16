#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>

using namespace std;

int main(){
    int counter2=0, counter4=0, counter5=0, startparen2, endparen2, startparen4, endparen4;
    string atom1, atom2, atom3, atom4, atom5;
    vector <int> express1;
    vector <int> express2;
    vector <int> express3;
    vector <int> express4;
    vector <int> express5;
    cout<<"First expression: ";
    getline(cin,atom1);
    atom1.erase(0,1);
    if(atom1[1]=='('){
        for(int a=1; a<atom1.length(); a++){
            if(atom1[a]!=')'){
                cout<<atom1[a];
            }
            else if(atom1[a]==')'){
                cout<<atom1[a]<<endl;
                a=atom1.length();
            }
        }
    }
    else{
        cout<<atom1[1]<<endl;
    }
    cout<<"Second expression: ";
    getline(cin,atom2);
    for(int b=0; b<atom2.length(); b++){
        if(atom2[b]=='('){
           counter2++;
        }
        if(counter2>=2){
            startparen2=b;
            b=atom2.length();
        }
    }
    for(int c=0; c<atom2.length(); c++){
        if(atom2[c]==')'){
            endparen2=c+1;
            c=atom2.length();
        }
    }
    atom2.erase(startparen2, endparen2-startparen2);
    for(int d=0; d<atom2.length();d++){
        if(atom2[2]==' '){
            atom2.erase(2,1);
        }
    }
    cout<<atom2<<endl;
    /*cout<<"Third expression: ";
    getline(cin,atom3);
    cout<<"Fourth expression: ";
    getline(cin,atom4);
    for(int d=atom4.length()-1; d>0; d--){
        if(atom4[d]=='('){
           startparen4=d;
           d=0;
        }
    }
    for(int e=atom4.length()-1; e>0; e--){
        if(atom4[e]==')'){
            counter4++;
        }
        if(counter4>1){
            endparen4=e;
            e=0;
        }
    }
    atom4.erase(startparen4, (endparen4-startparen4));
    cout<<atom4<<endl;
    cout<<"Fifth expression: ";
    getline(cin,atom5);
    atom5.erase(0,1);
    for(int a=0; a<atom5.length(); a++){
        if(atom5[a]=='('){
           counter5++;
        }
    }
    cout<<counter5-1<<endl;*/
}

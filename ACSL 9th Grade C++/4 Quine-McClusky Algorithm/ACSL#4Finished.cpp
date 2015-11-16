#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(string fin){
    string caps="ABCD";
    string lowr="abcd";
        if(fin=="NONE"){
            cout<<fin;
        }
    else{
        cout<<fin<<", ";
        for(int i=0; i<4; i++){
            if(fin[i]=='1'){
                cout<<caps[i];
            }
            else if(fin[i]=='0'){
                cout<<lowr[i];
            }
        }
    }
    cout<<endl;
}
string mult(string bin1, string bin2){
    string fin="";
    for(int i=0; i<4; i++){
        if(bin1[i]==bin2[i]){
            if(bin1[i]=='1'){
                fin=fin+"1";
            }
            else if(bin1[i]=='0'){
                fin=fin+"0";
            }
            else if(bin1[i]=='x'){
                fin=fin+"x";
             }
        }
        else{
            fin=fin+"x";
        }
    }
return(fin);
}
string validity(string bin1, string bin2){
    string bin;
    int compNum=0;
    int compX=0;
    if( (bin1=="NONE") || (bin2=="NONE") ){
        bin="NONE";
    }
    else{
        for(int i=0; i<4; i++){
            if( (bin1[i]=='x') || (bin2[i]=='x') ){
                if(bin1[i]!=bin2[i]){
                    compX=1;
                }
            }
            else if(bin1[i]==bin2[i]){
            }
            else{
                compNum=compNum+1;
            }
        }
        if( (compX==0) && (compNum<2) ){
            bin=mult(bin1, bin2);
        }
        else{
            bin="NONE";
        }
    }
return(bin);
}
string numToBin(vector<int> terms){
    string bin;
    int valid=0;
    int in;
    cin>>in;
    for(int i=0; i<terms.size(); i++){
        if(in==terms[i]){
            valid=1;
        }
    }
    if(valid==0){
        bin="NONE";
    }
    else{
        if(in==0){
            bin="0000";
        }
        if(in==1){
            bin="0001";
        }
        if(in==2){
            bin="0010";
        }
        if(in==3){
            bin="0011";
        }
        if(in==4){
            bin="0100";
        }
        if(in==5){
            bin="0101";
        }
        if(in==6){
            bin="0110";
        }
        if(in==7){
            bin="0111";
        }
        if(in==8){
            bin="1000";

        }
        if(in==9){
            bin="1001";
        }
        if(in==10){
            bin="1010";
        }
        if(in==11){
            bin="1011";
        }
        if(in==12){
            bin="1100";
        }
        if(in==13){
            bin="1101";
        }
        if(in==14){
            bin="1110";
        }
        if(in==15){
            bin="1111";
        }
    };
return(bin);
}
int main(){
    int x;
    string bin1, bin2, bin3, bin4, fin1, fin2;
    vector<int> terms;
    cout<<"True numbers: "<<endl;
    do{
        cin>>x;
        if(x!=-1){
            terms.push_back(x);
        }
    }while(x!=-1);

    cout<<endl<<"Input #1: "<<endl;
    bin1=numToBin(terms);
    bin2=numToBin(terms);
    fin1=validity(bin1, bin2);
    print(fin1);

    cout<<endl<<"Input #2: "<<endl;
    bin1=numToBin(terms);
    bin2=numToBin(terms);
    fin1=validity(bin1, bin2);
    print(fin1);

    cout<<endl<<"Input #3: "<<endl;
    bin1=numToBin(terms);
    bin2=numToBin(terms);
    fin1=validity(bin1, bin2);
    print(fin1);

    cout<<endl<<"Input #4: "<<endl;
    bin1=numToBin(terms);
    bin2=numToBin(terms);
    fin1=validity(bin1, bin2);
    print(fin1);

    cout<<endl<<"Input #5: "<<endl;
    bin1=numToBin(terms);
    bin2=numToBin(terms);
    fin1=validity(bin1, bin2);
    print(fin1);

    return 0;
}

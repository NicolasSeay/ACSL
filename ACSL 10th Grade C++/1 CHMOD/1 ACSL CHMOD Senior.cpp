#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>

using namespace std;

int main(){
    for(int i=0; i<5; i++){
        string input;
        vector <int> binchar;
        string bin1;
        string bin2;
        string bin3;
        bin1[0]='-', bin1[1]='-', bin1[2]='-';
        bin2[0]='-', bin2[1]='-', bin2[2]='-';
        bin3[0]='-', bin3[1]='-', bin3[2]='-';
        cout<<"Input: ";
        getline(cin, input);
        for(int a=0; a<input.size()-1; a++){
            if(input[a]==','){
                input.erase(a,1);
            }
        }
        for(int b=1; b<4; b++){
            string octhold;
            if(input[b]=='0'){
                octhold="000";
                binchar.push_back(0);
                binchar.push_back(0);
                binchar.push_back(0);
            }
            if(input[b]=='1'){
                octhold="001";
                binchar.push_back(0);
                binchar.push_back(0);
                binchar.push_back(1);
            }
            if(input[b]=='2'){
                octhold="010";
                binchar.push_back(0);
                binchar.push_back(1);
                binchar.push_back(0);
            }
            if(input[b]=='3'){
                octhold="011";
                binchar.push_back(0);
                binchar.push_back(1);
                binchar.push_back(1);
            }
            if(input[b]=='4'){
                octhold="100";
                binchar.push_back(1);
                binchar.push_back(0);
                binchar.push_back(0);
            }
            if(input[b]=='5'){
                octhold="101";
                binchar.push_back(1);
                binchar.push_back(0);
                binchar.push_back(1);
            }
            if(input[b]=='6'){
                octhold="110";
                binchar.push_back(1);
                binchar.push_back(1);
                binchar.push_back(0);
            }
            if(input[b]=='7'){
                octhold="111";
                binchar.push_back(1);
                binchar.push_back(1);
                binchar.push_back(1);
            }
            cout<<octhold<<" ";
        }
        cout<<"and ";
        for(int c=0; c<3; c++){
            if(input[0]=='1'){
                if(binchar[0]==1){
                    bin1[0]='r';
                }
                if(binchar[1]==1){
                    bin1[1]='w';
                }
                if(binchar[2]==1){
                    bin1[2]='s';
                }
                ///
                if(binchar[3]==1){
                    bin2[0]='r';
                }
                if(binchar[4]==1){
                    bin2[1]='w';
                }
                if(binchar[5]==1){
                    bin2[2]='x';
                }
                ///
                if(binchar[6]==1){
                    bin3[0]='r';
                }
                if(binchar[7]==1){
                    bin3[1]='w';
                }
                if(binchar[8]==1){
                    bin3[2]='x';
                }
            }
            else if(input[0]=='2'){
                if(binchar[0]==1){
                    bin1[0]='r';
                }
                if(binchar[1]==1){
                    bin1[1]='w';
                }
                if(binchar[2]==1){
                    bin1[2]='s';
                }
                ///
                if(binchar[3]==1){
                    bin2[0]='r';
                }
                if(binchar[4]==1){
                    bin2[1]='w';
                }
                if(binchar[5]==1){
                    bin2[2]='s';
                }
                ///
                if(binchar[6]==1){
                    bin3[0]='r';
                }
                if(binchar[7]==1){
                    bin3[1]='w';
                }
                if(binchar[8]==1){
                    bin3[2]='x';
                }
            }
            else if(input[0]=='4'){
                if(binchar[0]==1){
                    bin1[0]='r';
                }
                if(binchar[1]==1){
                    bin1[1]='w';
                }
                if(binchar[2]==1){
                    bin1[2]='x';
                }
                ///
                if(binchar[3]==1){
                    bin2[0]='r';
                }
                if(binchar[4]==1){
                    bin2[1]='w';
                }
                if(binchar[5]==1){
                    bin2[2]='x';
                }
                ///
                if(binchar[6]==1){
                    bin3[0]='r';
                }
                if(binchar[7]==1){
                    bin3[1]='w';
                }
                if(binchar[8]==1){
                    bin3[2]='t';
                }
            }
            else{
                if(binchar[0]==1){
                    bin1[0]='r';
                }
                if(binchar[1]==1){
                    bin1[1]='w';
                }
                if(binchar[2]==1){
                    bin1[2]='x';
                }
                ///
                if(binchar[3]==1){
                    bin2[0]='r';
                }
                if(binchar[4]==1){
                    bin2[1]='w';
                }
                if(binchar[5]==1){
                    bin2[2]='x';
                }
                ///
                if(binchar[6]==1){
                    bin3[0]='r';
                }
                if(binchar[7]==1){
                    bin3[1]='w';
                }
                if(binchar[8]==1){
                    bin3[2]='x';
                }
            }

        }
        cout<<bin1[0]<<bin1[1]<<bin1[2]<<" "<<bin2[0]<<bin2[1]<<bin2[2]<<" "<<bin3[0]<<bin3[1]<<bin3[2]<<endl<<endl;
    }
}

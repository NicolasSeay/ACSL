#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(){
    for(int a=0; a<5; a++){
        int jack=11, queen=11, king=12;
        int samesuitcounter=0;
        int samesuitabovedealtcardcounter=0;
        string dealtcard;   ///compared card
        vector <string> input;  ///the 5 cards in your hand
        vector <string> samesuit;   ///the cards in "input" that are the same suit as dealtcard
        string samesuittemp;
        string inputstring; ///used to input the 5 strings that plater is dealt
        cin>>dealtcard;
        cin>>inputstring;
        input.push_back(inputstring);
        cin>>inputstring;
        input.push_back(inputstring);
        cin>>inputstring;
        input.push_back(inputstring);
        cin>>inputstring;
        input.push_back(inputstring);
        cin>>inputstring;
        input.push_back(inputstring);
        cout<<endl;

        /*dealtcard="AC";
        input.push_back("AD");
        input.push_back("KH");
        input.push_back("AS");
        input.push_back("KS");
        input.push_back("QS");
        cout<<endl;*/

        if(dealtcard[0]=='A')
            dealtcard[0]='1';
        else if(dealtcard[0]=='T')
            dealtcard[0]='A';
        else if(dealtcard[0]=='J')
            dealtcard[0]='B';
        else if(dealtcard[0]=='Q')
            dealtcard[0]='C';
        else if(dealtcard[0]=='K')
            dealtcard[0]='D';
        for(int x=0; x<input.size(); x++){      ///converts from ATJQK to 1ABCD
            if(input[x][0]=='A')
                input[x][0]='1';
            else if(input[x][0]=='T')
                input[x][0]='A';
            else if(input[x][0]=='J')
                input[x][0]='B';
            else if(input[x][0]=='Q')
                input[x][0]='C';
            else if(input[x][0]=='K')
                input[x][0]='D';
        }
        for(int b=0; b<5; b++){         ///adds pieces from input to samesuit if they are the same suit
            if(input[b][1]==dealtcard[1]){
                samesuit.push_back(input[b]);
                samesuitcounter++;
            }
        }
        if(samesuitcounter!=0){         ///if there is anything of the same suit as dealtcard
            for(int a=0; a<samesuit.size(); a++){
                if((int)samesuit[a][0]-48>(int)dealtcard[0]-48){
                    samesuitabovedealtcardcounter++;
                }
            }
            for(int b=0; b<samesuit.size(); b++){
                for(int c=(b+1); c<samesuit.size(); c++){
                    if((int)samesuit[b][0]-48>(int)samesuit[c][0]-48){      ///bubblesorts samesuit
                        string placeholder=samesuit[b];
                        samesuit[b]=samesuit[c];
                        samesuit[c]=placeholder;
                    }
                }
            }
            if(samesuitabovedealtcardcounter!=0){       ///if there is a card of the same suit above the dealt card number
                for(int a=0; a<samesuit.size(); a++){
                    if((int)samesuit[a][0]-48>(int)dealtcard[0]-48){
                        for(int x=0; x<samesuit.size(); x++){      ///converts from 1ABCD back to ATJQK
                            if(samesuit[x][0]=='1')
                                samesuit[x][0]='A';
                            else if(samesuit[x][0]=='A')
                                samesuit[x][0]='T';
                            else if(samesuit[x][0]=='B')
                                samesuit[x][0]='J';
                            else if(samesuit[x][0]=='C')
                                samesuit[x][0]='Q';
                            else if(samesuit[x][0]=='D')
                                samesuit[x][0]='K';
                        }
                        cout<<samesuit[a];
                        a=samesuit.size();
                    }
                }
            }
            else{
                for(int x=0; x<samesuit.size(); x++){      ///converts from 1ABCD back to ATJQK
                    if(samesuit[x][0]=='1')
                        samesuit[x][0]='A';
                    else if(samesuit[x][0]=='A')
                        samesuit[x][0]='T';
                    else if(samesuit[x][0]=='B')
                        samesuit[x][0]='J';
                    else if(samesuit[x][0]=='C')
                        samesuit[x][0]='Q';
                    else if(samesuit[x][0]=='D')
                        samesuit[x][0]='K';
                }
                cout<<samesuit[0];
            }
        }
        else{                           ///if there is nothing from the same suit as dealtcard
            int samenumbercounter=0;
            for(int b=0; b<5; b++){
                for(int c=(b+1); c<5; c++){
                    if((int)input[b][0]-48>(int)input[c][0]-48){
                        string placeholder=input[b];
                        input[b]=input[c];
                        input[c]=placeholder;
                    }
                }
            }
            for(int i=1; i<4; i++){
                if(input[i][0]==input[0][0]){
                    samenumbercounter++;
                }
            }
            if(samenumbercounter==0){
                for(int x=0; x<input.size(); x++){      ///converts from 1ABCD back to ATJQK
                    if(input[x][0]=='1')
                        input[x][0]='A';
                    else if(input[x][0]=='A')
                        input[x][0]='T';
                    else if(input[x][0]=='B')
                        input[x][0]='J';
                    else if(input[x][0]=='C')
                        input[x][0]='Q';
                    else if(input[x][0]=='D')
                        input[x][0]='K';
                }
                cout<<input[0];
            }
            else{
                vector <string> samenumber;
                int counter1=0;
                for(int b=0; b<=samenumbercounter; b++){
                    samenumber.push_back(input[b]);
                }
                for(int x=0; x<samenumber.size(); x++){     ///converts from CDHS to 1234
                    if(samenumber[x][0]=='C')
                        samenumber[x][0]='1';
                    else if(samenumber[x][0]=='D')
                        samenumber[x][0]='2';
                    else if(samenumber[x][0]=='H')
                        samenumber[x][0]='3';
                    else if(samenumber[x][0]=='S')
                        samenumber[x][0]='4';
                }
                for(int b=0; b<samenumber.size(); b++){
                    for(int c=(b+1); c<samenumber.size(); c++){
                        if((int)samenumber[b][0]-48>(int)samenumber[c][0]-48){      ///bubblesorts samenumber
                            string placeholder=samenumber[b];
                            samenumber[b]=samenumber[c];
                            samenumber[c]=placeholder;
                        }
                    }
                }
                for(int x=0; x<samenumber.size(); x++){     ///converts from 1234 back to CDHS
                    if(samenumber[x][1]=='1')
                        samenumber[x][1]='C';
                    else if(samenumber[x][1]=='2')
                        samenumber[x][1]='D';
                    else if(samenumber[x][1]=='3')
                        samenumber[x][1]='H';
                    else if(samenumber[x][1]=='4')
                        samenumber[x][1]='S';
                }
                for(int x=0; x<samenumber.size(); x++){      ///converts from 1ABCD back to ATJQK
                    if(samenumber[x][0]=='1')
                        samenumber[x][0]='A';
                    else if(samenumber[x][0]=='A')
                        samenumber[x][0]='T';
                    else if(samenumber[x][0]=='B')
                        samenumber[x][0]='J';
                    else if(samenumber[x][0]=='C')
                        samenumber[x][0]='Q';
                    else if(samenumber[x][0]=='D')
                        samenumber[x][0]='K';
                }
                cout<<samenumber[0];
            }
        }
        cout<<endl<<endl;
    }
    return 0;
}

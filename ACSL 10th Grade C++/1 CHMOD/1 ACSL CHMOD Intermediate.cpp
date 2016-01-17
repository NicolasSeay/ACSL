#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>

using namespace std;

int main(){
    vector <string> charhold;
    string octinput, bininput, charinput;
    for(int b=0; b<2; b++){
        cout<<"Input: ";
        getline(cin, octinput);
        for(int i=0; i<5; i+=2){
            string octhold;
            if(octinput[i]=='0'){
                octhold="000";
            }
            if(octinput[i]=='1'){
                octhold="001";
            }
            if(octinput[i]=='2'){
                octhold="010";
            }
            if(octinput[i]=='3'){
                octhold="011";
            }
            if(octinput[i]=='4'){
                octhold="100";
            }
            if(octinput[i]=='5'){
                octhold="101";
            }
            if(octinput[i]=='6'){
                octhold="110";
            }
            if(octinput[i]=='7'){
                octhold="111";
            }
            cout<<octhold<<" ";
        }
        cout<<"and ";
        for(int a=0; a<5; a+=2){
            string charhold;
            if(octinput[a]=='0'){
                charhold="---";
            }
            if(octinput[a]=='1'){
                charhold="--x";
            }
            if(octinput[a]=='2'){
                charhold="-w-";
            }
            if(octinput[a]=='3'){
                charhold="-wx";
            }
            if(octinput[a]=='4'){
                charhold="r--";
            }
            if(octinput[a]=='5'){
                charhold="r-x";
            }
            if(octinput[a]=='6'){
                charhold="rw-";
            }
            if(octinput[a]=='7'){
                charhold="rwx";
            }
            cout<<charhold<<" ";
        }
        cout<<endl<<endl;
    }



    for(int b=0; b<2; b++){
        int binnum1=0, binnum2=0, binnum3=0;
        string binchar1;
        binchar1[0]='-', binchar1[1]='-', binchar1[2]='-';
        string binchar2;
        binchar2[0]='-', binchar2[1]='-', binchar2[2]='-';
        string binchar3;
        binchar3[0]='-', binchar3[1]='-', binchar3[2]='-';
        cout<<"Input: ";
        getline(cin, bininput);
        for(int c=0; c<bininput.size()-1; c++){
            if(bininput[c]==','){
                bininput.erase(c,1);
            }
        }
        ///
        if(bininput[0]=='1'){
            binnum1+=4;
            binchar1[0]='r';
        }
        if(bininput[1]=='1'){
            binnum1+=2;
            binchar1[1]='w';
        }
        if(bininput[2]=='1'){
            binnum1+=1;
            binchar1[2]='x';
        }
        ///
        if(bininput[3]=='1'){
            binnum2+=4;
            binchar2[0]='r';
        }
        if(bininput[4]=='1'){
            binnum2+=2;
            binchar2[1]='w';
        }
        if(bininput[5]=='1'){
            binnum2+=1;
            binchar2[2]='x';
        }
        ///
        if(bininput[6]=='1'){
            binnum3+=4;
            binchar3[0]='r';
        }
        if(bininput[7]=='1'){
            binnum3+=2;
            binchar3[1]='w';
        }
        if(bininput[8]=='1'){
            binnum3+=1;
            binchar3[2]='x';
        }
        ///
        cout<<binnum1<<binnum2<<binnum3;
        cout<<" and ";
        for(int f=0; f<3; f++)
            cout<<binchar1[f];
        cout<<" ";
        for(int g=0; g<3; g++)
            cout<<binchar2[g];
        cout<<" ";
        for(int h=0; h<3; h++)
            cout<<binchar3[h];

        cout<<endl<<endl;
    }



    string binchar1;
    string binchar2;
    string binchar3;
    binchar1[0]='0', binchar1[1]='0', binchar1[2]='0';
    binchar2[0]='0', binchar2[1]='0', binchar2[2]='0';
    binchar3[0]='0', binchar3[1]='0', binchar3[2]='0';
    int charnum1=0, charnum2=0, charnum3=0;
    cout<<"Input: ";
    getline(cin, charinput);
    for(int c=0; c<charinput.size()-1; c++){
        if(charinput[c]==','){
            charinput.erase(c,1);
        }
    }
    if(charinput[0]=='r'){
        charnum1+=4;
        binchar1[0]='1';
    }
    if(charinput[1]=='w'){
        charnum1+=2;
        binchar1[1]='1';
    }
    if(charinput[2]=='x'){
        charnum1+=1;
        binchar1[2]='1';
    }
    if(charinput[3]=='r'){
        charnum2+=4;
        binchar2[0]='1';
    }
    if(charinput[4]=='w'){
        charnum2+=2;
        binchar2[1]='1';
    }
    if(charinput[5]=='x'){
        charnum2+=1;
        binchar2[2]='1';
    }
    if(charinput[6]=='r'){
        charnum3+=4;
        binchar3[0]='1';
    }
    if(charinput[7]=='w'){
        charnum3+=2;
        binchar3[1]='1';
    }
    if(charinput[8]=='x'){
        charnum3+=1;
        binchar3[2]='1';
    }
    cout<<charnum1<<charnum2<<charnum3;
    cout<<" and ";
    for(int f=0; f<3; f++)
        cout<<binchar1[f];
    cout<<" ";
    for(int g=0; g<3; g++)
        cout<<binchar2[g];
    cout<<" ";
    for(int h=0; h<3; h++)
        cout<<binchar3[h];


    return 0;
}

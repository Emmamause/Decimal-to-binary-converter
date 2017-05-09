#include <iostream>
#include <windows.h>

using namespace std;




// Decimal to binary converter
    unsigned long long decToBinFnc(unsigned long long nrIn){
        unsigned long long baseBin[20];
        baseBin[0]=1;
        for(int i=1;i<20;i++){
            baseBin[i]=baseBin[i-1]*10;
        }
        unsigned long long baseDec[20];
        baseDec[0]=1;
        for(int i2=1;i2<20;i2++){
            baseDec[i2]=baseDec[i2-1]*2;
        }
        unsigned long long visibleBinaryNr=0;
        int rest=nrIn;
        while(rest!=0){
        int x=0;
        while(rest>=baseDec[x]){
            x++;
        }
        rest -=baseDec[x-1];
        visibleBinaryNr+=baseBin[x-1];
        }
        unsigned long long outBin=visibleBinaryNr; // output
        return outBin;
    }


// Binary to decimal converter
    unsigned long long binToDecFnc(unsigned long long nrInBin){
         unsigned long long baseBin[20];
        baseBin[0]=1;
        for(int i=1;i<20;i++){
            baseBin[i]=baseBin[i-1]*10;
        }
        unsigned long long baseDec[20];
        baseDec[0]=1;
        for(int i2=1;i2<20;i2++){
            baseDec[i2]=baseDec[i2-1]*2;
        }
        unsigned long long visibleDecimalNr=0;
        int restBin=nrInBin;
        while(restBin!=0){
            int y=0;
            while(restBin>=baseBin[y]){
                y++;
            }
            restBin-=baseBin[y-1];
            visibleDecimalNr+=baseDec[y-1];
        }
        unsigned long long outDec=visibleDecimalNr; // output
        return outDec;
    }

int main()
{
    cout.precision(20);

    // Example use:
    //cout<<decToBinFnc(30)<<endl; // output2 11110
    //cout<<binToDecFnc(101010); // outputs 42



    return 0;
}

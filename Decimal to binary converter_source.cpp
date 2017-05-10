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
    cout<<"This program allows for decimal to binary conversion and vice versa, as well as arithmetic between binary numbers. \n";
    cout<<"Select one of the following options. \n";
    int decision=0;
    cout<<"Enter 1 to select decimal to binary conversion. \nEnter 2 to select binary to decimal conversion. \nEnter 3 to select decimal arithmetic. \nEnter 4 to select binary arithmetic.\n";
    cin>>decision;
    while(decision!=5){
        if(decision==1){
            cout<<"Enter the number."<<endl;
            int decNrInput=0;
            cin>>decNrInput;
            cout<<decNrInput<<" to binary is " << decToBinFnc(decNrInput)<<endl;
        }
        if(decision==2){
            cout<<"Enter the number."<<endl;
            int binNrInput=0;
            cin>>binNrInput;
            cout<<binNrInput<<" to decimal is "<<binToDecFnc(binNrInput)<<endl;
        }
        if(decision==3){
            cout<<"Enter the first number."<<endl;
            signed long long decMathNr1=0;
            cin>>decMathNr1;
            int selectOperation=0;
            cout<<"Enter: \n1.Addition \n2.Subtraction\n3.Multiplication \n4.Division\n";
            cin>>selectOperation;
            cout<<"Enter the second number."<<endl;
            signed long long decMathNr2=0;
            cin>>decMathNr2;
            if(selectOperation==1){
                cout<<endl<<decMathNr1<< " + "<<decMathNr2<< " = "<<decMathNr1+decMathNr2<<endl<<endl;
            }
            if(selectOperation==2){
                cout<<endl<<decMathNr1<< " - "<<decMathNr2<< " = "<<decMathNr1-decMathNr2<<endl<<endl;
            }
            if(selectOperation==3){
                cout<<endl<<decMathNr1<< " * "<<decMathNr2<< " = "<<decMathNr1*decMathNr2<<endl<<endl;
            }
            if(selectOperation==4){
                signed long long resultDecimalDivision=decMathNr1/decMathNr2;
                signed long long remainderDecMath=decMathNr1%decMathNr2;
                cout<<endl<<decMathNr1<< " + "<<decMathNr2<< " = "<<resultDecimalDivision<<" Remainder = "<<remainderDecMath<<endl<<endl;
            }
        }
        if(decision==4){
            cout<<"Enter the first number in binary."<<endl;
            unsigned long long binMathNr1=0;
            cin>>binMathNr1;
            int selectOperationBinMath=0;
            cout<<"Enter: \n1.Addition \n2.Subtraction\n3.Multiplication \n4.Division\n";
            cin>>selectOperationBinMath;
            cout<<"Enter the second number in binary."<<endl;
            unsigned long long binMathNr2=0;
            cin>>binMathNr2;
            unsigned long long binToDecMathNr1=binToDecFnc(binMathNr1);
            unsigned long long binToDecMathNr2=binToDecFnc(binMathNr2);
            if(selectOperationBinMath==1){
                unsigned long long binToDecMathNr1plusNr2=binToDecMathNr1+binToDecMathNr2;
                cout<<binMathNr1<<" + "<< binMathNr2<<" = "<<decToBinFnc(binToDecMathNr1plusNr2)<<endl;
            }
            if(selectOperationBinMath==2){
                unsigned long long binToDecMathNr1minusNr2=binToDecMathNr1-binToDecMathNr2;
                cout<<binMathNr1<<" - "<< binMathNr2<<" = "<<decToBinFnc(binToDecMathNr1minusNr2)<<endl;
            }
            if(selectOperationBinMath==3){
                unsigned long long binToDecMathNr1timesNr2=binToDecMathNr1*binToDecMathNr2;
                cout<<binMathNr1<<" * "<< binMathNr2<<" = "<<decToBinFnc(binToDecMathNr1timesNr2)<<endl;
            }
            if(selectOperationBinMath==4){
                unsigned long long binToDecMathNr1dividedNr2=binToDecMathNr1/binToDecMathNr2;
                unsigned long long binToDecMathnr1moduloNr2=binToDecMathNr1%binToDecMathNr2;
                cout<<binMathNr1<<" + "<< binMathNr2<<" = "<<decToBinFnc(binToDecMathNr1dividedNr2)<<" remainder "<<binToDecMathnr1moduloNr2<<endl;
            }

        }


    cout<<"1.Decimal to binary. \n2.Binary to decimal. \n3.Decimal arithmetic. \n4.Binary arithmetic. \n5.Exit\n";
    cin>>decision;
    }
    // Example use of functions:
    //cout<<decToBinFnc(30)<<endl; // output2 11110
    //cout<<binToDecFnc(101010); // outputs 42



    return 0;
}

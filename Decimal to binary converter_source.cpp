#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    cout.precision(20);

    // Initial text
    cout<<"Decimal to binary converter, works 1 to 1048575. \n";

    int opened=1;
    // Loop program
    while(opened==1){
        cout<<"Enter a number. \n";
        unsigned long nrIn;
        cin>>nrIn; // Number to be converted into binary

        unsigned long long baseBin[20]; // Will be populated with binary bases in binary form 1,10,100,1000...
        baseBin[0]=1; // Necessary to be multiplied by 10
        for(int i=1;i<20;i++){ // Populates the array baseBin
            baseBin[i]=baseBin[i-1]*10;
        }

        unsigned long long baseDec[20]; // Will be populated with binary bases in decimal form 1,2,4,8,16...
        baseDec[0]=1; // Necessary to be multiplied by 2
        for(int i2=1;i2<20;i2++){ // Populates the array baseDec
            baseDec[i2]=baseDec[i2-1]*2;
        }

        unsigned long long visibleBinaryNr=0; // Holds the integer in binary form that will be displayed.

// This finds the biggest base in decimal form that can fit into the number from an array that holds binary
// bases in decimal form, and then adds the corresponding base in binary form to the variable that will be
//visible visibleBinaryNr
        int rest=nrIn; // This holds the initial input number, and it will hold the remainder after subtracting bases
        while(rest!=0){ // When there are no more binary bases left to be added, the algorithm stops
            int x=0;
// Finds the first base that can't fit inside our remainder(rest), will be used to access the previous element
// in the array that holds binary bases in decimal form, which is the biggest base that can fit inside the remainder
            while(rest>=baseDec[x]){
                x++;
            }
            rest -=baseDec[x-1]; //
            visibleBinaryNr+=baseBin[x-1]; // This adds the base that can fit into  number to the visible

        }
        cout<<visibleBinaryNr<<endl;
// Extra functionality
//      cout<<"Enter 1 to try again, any other number to exit. \n";
//      cin>>opened;
    }

    return 0;
}

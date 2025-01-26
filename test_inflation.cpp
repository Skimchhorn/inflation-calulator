// Name: Kimchhorn Sambath
// program to asking for inputs which are the old price and the new price
// in order to calculate the rate of inflation and it keeps asking 
// until the user enters N (No) to end the program 

#include <iostream>
using namespace std;
 
#include "inflation.h"

const int DIGITS = 2;
// set the flags of the output stream std::cout so that the decimal point
// is always displayed with DIGITS digits after the decimal point
// precondition:
//    the global constant DIGITS determines the number of digits
//    to display after the decimal point
// postcondition:
//    the output stream cout now will always show the decimal point 
//    with DIGITS digits
void setOutputParameters() {
   cout.setf(std::ios::showpoint);
   cout.setf(std::ios::fixed);
   cout.precision(DIGITS); 
}   

// this main function is using do-while loop, with the ending condition is from the user
// anwsered No(N) and using the varible check (check is false by default) for signaling the validation of the input from the user.
// if the first input is not valid (check is true),it will skip the second input and the calculation then ask for next round
// if the second input is not valid (check is true),it will skip the calculation then ask for the next round .l
// if all the inputs are valid (check is false) ,the calculation will always be excuted.
int main() {
   setOutputParameters();
   char ans = ' ';
   bool check ;
   do{

     check = false;
     double oldPrice = 0, newPrice = 0;
     cout << endl << "Enter the last year price in $: ";
     cin >> oldPrice;
     if(oldPrice <= 0){
        cout << "You enter an invalid number of price." << endl;
        check = true;
     }

     if(!check){
     cout << "Enter this current price of that item in $: ";
     cin >> newPrice;
       if(newPrice <= 0){
          cout <<"You enter an invalid number of price. " << endl;
          check = true;
       } 
     }

     if(!check){
       cout << "the rate of inflation is " << calculate(oldPrice, newPrice) <<"%" << endl;
     }

     cout<< "Do you want it again ? (Y/N) : ";
     cin >> ans;

   }while (ans == 'Y' || ans == 'y');

   return 0; 
}



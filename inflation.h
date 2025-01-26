// Name: Kimchhorn Sambath


#ifndef FCT_H
#define FCT_H

// calculate is a function that gets 2 parameters, subtract the new price with the old price, 
//then divide by the old price ,and finally converts the outcome into percentage which is the inflation rate
// precondition:
//    passed two arguments which are the price from last year and the current price,that are non-negative and non-zero
// postcondition:
//    returns the rate of inflation in percentage
double calculate(double oldPrice, double newPrice);

#endif

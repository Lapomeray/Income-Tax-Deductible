#include <stdio.h>
#include <string.h>

/*
 *
 * This program will deduct income tax according to the the employees income tax bracket
 */

/* Function Prototypes */

int getMartialStatus();
int printInstructions();
int getNumKids();
float getHours();
double calcGrossPay(float hoursWorked, float payRate);
float calcNetPay(float grossPay);
int printStub(int payRate , float hoursWorked , int numKids , double grossPay , double netPay);



int main() {

    int martialStatus;
    int numKids;
    int payRate;
    double netPay;
    float hoursWorked;
    double grossPay;



    /* Instructions on how to use the Program*/
    printInstructions();

    /*Obtaining Employee's martial Status*/
    martialStatus = getMartialStatus();
    printf("%d \n", martialStatus );

    /* Obtaining number of kids Employee's have */
    numKids = getNumKids();
    printf("%d \n ", numKids);

    /*Obtaining number of hours Employee has worked */
    hoursWorked = getHours();
    printf("%f \n", hoursWorked);

    /* Martial status affecting pay rate*/
    if (martialStatus == 0) {
        payRate = 10;

        /* Number of kids affecting pay rate*/

        if (numKids == 0){

            payRate+= 0;

        } else if (numKids == 1 ) {
            payRate+= 1;


        }  else if (numKids == 2 ) {
            payRate+= 2;


        } else if (numKids == 3 ) {
            payRate+= 3;


        } else if (numKids == 4 ){
            payRate+= 4;


        } else {
            payRate+= 4;
        }

    } else  {
        payRate = 15;

        if (numKids == 0){

            payRate+= 0;

        } else if (numKids == 1 ) {
            payRate+= 1;


        }  else if (numKids == 2 ) {
            payRate+= 2;


        } else if (numKids == 3 ) {
            payRate+= 3;


        } else if (numKids == 4 ){
            payRate+= 4;


        } else {
            payRate+= 4;
        }
    }

    /*Calculate Gross pay*/
    grossPay = calcGrossPay(hoursWorked,payRate);
//    printf("Gross pay is %f \n", grossPay);

    netPay = calcNetPay(grossPay);
//    printf("Net Pay is %f \n", netPay);
//    printf("\n");



    //Ask to print statement

        printStub(payRate, hoursWorked, numKids, grossPay, netPay);



    return 0;
}


    /* Prints instructions on how to use program */
int printInstructions() {

     printf("Hello Employee, I will help you calculate your income tax. \n \t ");
//     printf("But first im going to need some information from you \n");
//     printf("Such as your martial status, number of kids you have, and number of hours worked. \n");

    return 0;



}


   /*Get Martial Status of the Employee*/
 int getMartialStatus() {

    int martialStatusBool;
    printf("Please type 1 if you are married and 0 if you are single  \t");
    scanf("%d",&martialStatusBool);


    return martialStatusBool;

}

 /* Obtaining number of kids Employee's have */
int getNumKids() {
    int kids;
    printf("How many kids do you have? \t");
    scanf("%d",&kids);

    return kids;

}

    /*Obtaining number of hours Employee has worked */
    float getHours() {
        float hours;
    printf("How many hours have you worked? \t");
    scanf("%f",&hours);


    return hours;
}



    /*Calculate Employee Gross Pay*/
    double calcGrossPay( float hoursWorked, float payRate) {

        double overtimeHours;
        double overtimePay;
        double grossPay;



        /*Calculate overtime*/
        if (hoursWorked > 40) {

            /*Define regular pay with no overtime*/
            double regPay = 40 * payRate;
//            printf("Regular pay is %f \n",regPay);

            /*Define overtime hours*/
            overtimeHours = hoursWorked - 40;
//            printf("%f overtime hours \n", overtimeHours);

            /*Define Overtime pay rate*/
            double overtimePayRate = payRate * 1.5;
//            printf("Overtime pay rate is %f \n", overtimePayRate);

            overtimePay = overtimeHours * overtimePayRate;
//            printf("Overtime pay is %f \n", overtimePay);


            /*Define Gross Pay*/
             grossPay = regPay + overtimePay;

        } else{

             grossPay = payRate * hoursWorked;

        }



    return grossPay;



}

/*Calculate Employee Gross Pay*/

float calcNetPay(float grossPay) {

    double incomeTax;
    float netPay;



    /*Calculate Income Tax*/

    if (grossPay < 300) {

        incomeTax  = 0;

    } else if ( 300 < grossPay && grossPay < 399.99) {

        incomeTax = grossPay * (.05);

    } else if (400 < grossPay && grossPay < 599.99){

        incomeTax = grossPay * (.08);

    } else  {

        // Gross Pay is greater than 600
        incomeTax = grossPay * (.1);
    }



    /*Calculate Net Pay*/
    netPay = grossPay - incomeTax;



    return netPay;


}


int printStub(int payRate, float hoursWorked,int numKids, double grossPay, double netPay) {

    printf("Pay Stub: \n");
    printf("Employee pay rate: %d \n", payRate);
    printf("Employee hours worked: %f \n", hoursWorked);
    printf("Employee number of kids: %d \n", numKids);
    printf("Employee gross pay: %f \n", grossPay);
    printf("Employee net pay: %f \n", netPay);





    return 0;


}
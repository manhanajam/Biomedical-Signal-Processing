#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "Lab2.h"

void initialize(double& k, int& n0) {
    // Asking the user to enter the growth factor and initial population 
    cout << "Enter the value for K (growth factor): ";
    cin >> k;
    cout << "Enter the value for N0 (initial population): ";
    cin>> n0;
}

void calculate( const double k, const int n0, double array[]){
    // Fill the array with the population values for each time/ t value 
    for (int i=0; i < 11; i++) {
        array[i] = n0 * exp(k*i); // Calculate N(t) = N0 * e^ (k*t)
        
    }
}

void display(const double array[]) {
// Formatting for the table output 
    cout << endl;
    cout << "\t Growth Summary" << endl;
    cout << setw(8) << "Hour" << setw(13) << "Population" << endl;
    cout << setw(8) << "====" << setw(13) << "==========";
    cout << endl;
    cout << setprecision(3) << fixed;
    for (int i = 0; i < 11; i++) {
        cout << setw(8) << i << setw(13) << array[i] << endl;
    }
}

void twoDdisplay(int num, const double arr[][11]) {
    // The output table formatting for multiple populations
    cout << endl;
    cout << setw(8) << "Hour";
    for (int i = 0; i < num; i++) {
        cout << setw(15) << ("Population " + to_string(i + 1));
    }
    cout << endl;
    
    // The lines for under the titles
    cout << setw(8) << "====";
    for (int i = 0; i < num; i++) {
        cout << setw(15) << "===========";
    }
    cout << endl;

    cout << setprecision(3) << fixed; // Allows the output to only have 3 decimal places
    
    // Loop for hours
    for (int j = 0; j < 11; j++) {
        cout << setw(8) << j;
        
    // Loop for populations
        for (int i = 0; i < num; i++) {
            cout << setw(15) << arr[i][j];
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
double k;
int n0;

// For Part 1 where the user is asked to enter the growth factor and initial population 
if (1 == argc) {
    initialize(k,n0);
    double arr[11];
    calculate(k,n0,arr);
    display(arr);   

}
else if (2 == argc) { 
    // User gives number of populations
    
    int convInt = atoi(argv[1]); // Convert arg to int
    
    // Creates a 2D array 
    double arr[convInt][11];
    
    for (int i = 0; i < convInt; i++){
        cout <<"Population " << (i+1) << ": ";
        
        // Asks the user for growth factor and initial population
        initialize(k,n0);
        
        // Filling the row for the population 
        calculate(k,n0, arr[i]);
    }
    
    // Displays the multiple populations in one table 
    twoDdisplay(convInt, arr);
    
}
else if (3 == argc) { 
    // User has the growth factor and initial population
    
    k = atof(argv[1]); // String is converted double
    n0 = atoi(argv[2]); //  String converted to int
    
    cout << "Growth Factor (k) = " << k << endl;
    cout << "Initial population (N0) = " << n0 << endl; 
    
    double arr[11];
    calculate(k, n0, arr);
    display(arr); 
}
    
else {
cout << "Number of command-line arguments "
<< "(including the name of the program) "
<< "should be three or less." << endl;
}
} //end of main


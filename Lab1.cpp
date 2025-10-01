#include "Lab1.h"

string enterDNAString() 
{
    string inputDna;
    cout << "Enter A DNA string: ";
    cin >> inputDna;
    return inputDna;
}

bool checkValidity(string s) 
{
    for (char dnaStrand : s) 
    {
        if (dnaStrand != 'A' && dnaStrand != 'a' && dnaStrand != 'c' && dnaStrand != 'C' &&
            dnaStrand != 'G' && dnaStrand != 'g' && dnaStrand != 't' && dnaStrand != 'T') {
            return false;
        }
    }
    return true;
}


void compliment(string s) 
{
    if (!checkValidity(s)) 
    {
        return;  
    }

    cout << " : compliment(" << s << ") = ";
    for (char dnaStrand : s) 
    {
        switch (dnaStrand) 
        {
            case 'A': cout << 'T'; break;
            case 'T': cout << 'A'; break;
            case 'G': cout << 'C'; break;
            case 'C': cout << 'G'; break;
            case 'a': cout << 't'; break;
            case 't': cout << 'a'; break;
            case 'g': cout << 'c'; break;
            case 'c': cout << 'g'; break;
        }
    }
}

int main() {
    while(true) {
        cout << "Please choose an option:" << endl;
        cout << "1. Enter DNA string, echo it" << endl;
        cout << "2. Enter DNA string, echo it, validate it" << endl;
        cout << "3. Enter DNA string, echo it, validate it, compliment it if valid" << endl;
        cout << "4. Exit" << endl;

        int option;
        cout << ">> ";
        cin >> option;

        if ( !cin )  {
            cin.clear();
            cin.ignore( INT_MAX, '\n' );
            cout << "Non-numeric option! Try again." << endl;
            continue;
        }

        if (1 == option) {
            string str1 = enterDNAString();
            cout << str1 << " (" << str1.size() << " chars)";
            cout << endl;
        }
        else if (2 == option) {
            string str1 = enterDNAString();
            cout << str1 << " (" << str1.size() << " chars)";
            bool b = checkValidity(str1);
            if(b == true)
                cout << " : VALID DNA";
            else
                cout << " : INVALID DNA";
            cout << endl;
        }
        else if (3 == option) {
            string str1 = enterDNAString();
            cout << str1 << " (" << str1.size() << " chars)";
            bool b = checkValidity(str1);
            if(b == true)
                cout << " : VALID DNA";
            else
                cout << " : INVALID DNA";
            compliment(str1);
            cout << endl;
        }
        else if (4 == option) {
            return 0;
        }
        else {
            cout << "Integer option, but incorrect! Try again." << endl;
        }
    }
    return 0;
    
}

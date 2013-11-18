#include <string>
#include <iostream>

int main() {
    using namespace std;
    const int THISYEAR(2011);  
    string yourName;
    int birthYear;

    cout << "What is your name? "  << flush;
    //cin >> yourName;
    getline(cin, yourName);

    cout << "What year were you born? " ;
    cin >> birthYear;

    cout << "Your name is " << yourName << " Your year " << birthYear
            << " and you are approximately " 
            << (THISYEAR - birthYear)
            << " years old. " << endl;
}

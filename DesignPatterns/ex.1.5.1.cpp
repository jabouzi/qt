#include <iostream>

double toCelsius(double fahrenheitTemp)
{
    return (fahrenheitTemp  -  32)  *  5/9;
}

double toFahrenheit(double celsiusTemp)
{
    return celsiusTemp  *  9/5 + 32;
}

int main()
{
    using namespace std;
    double celsius, fahrenheit;
    cout << "Celsius : " << flush;
    cin >> celsius;
    cout << "Fahrenheit : ";
    cin >> fahrenheit;
    cout << "2F " << toFahrenheit(celsius) << endl;
    cout << "2C " << toCelsius(fahrenheit) << endl;
    
    return 0;
}

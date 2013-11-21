#include <QtGui>
#include <cstdlib>

double toCelsius(double fahrenheitTemp)
{
    return (fahrenheitTemp  -  32)  *  5/9;
}

double toFahrenheit(double celsiusTemp)
{
    return celsiusTemp  *  9/5 + 32;
}

long int generate_rand()
{
    QTextStream cout(stdout);
    int n1 = rand() % 6 + 1;
    int n2 = rand() % 6 + 1;
    cout << "n1 : " << n1 << endl;
    cout << "n2 : " << n2 << endl;
    
    return n1+n2;
} 

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    QTextStream cout(stdout);
    int answer = 0;    
    srand(time(0));
    do {
        // local variables to the loop:
        double celcius = 0;
        double fahrenheit(0);
        bool ok = false;
        celcius = QInputDialog::getInt(0, "Fahrenheit calculators", "Celcius value:", 1, -2147483647, 2147483647, 1, &ok);
        cout << "User entered: " << celcius << endl;
        if (!ok) return EXIT_SUCCESS;
        fahrenheit = toFahrenheit(celcius);
        QString response = QString("Fahrenheit value is %1 and rand is %2 \n\n%3").arg(fahrenheit).arg(generate_rand()).arg("Compute another Fahrenheit ?");   
        answer = QMessageBox::question(0, "Play again?", response, QMessageBox::Yes | QMessageBox::No);
    } while (answer == QMessageBox::Yes);
    return EXIT_SUCCESS;
}


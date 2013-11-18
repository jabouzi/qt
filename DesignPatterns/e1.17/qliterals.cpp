#include <QTextStream>
#include <QString>

int main() {
    const char* charstr = "GNU STANDS FOR \"GNU'S NOT UNIX\"";

    QTextStream cout(stdout);  
    QString str = charstr; /* C-style strings can be converted to QString. */
    cout << str << endl;
    cout << "\n\tTitle 1\t\"Cat Clothing\"\n\tTitle 2\t\"Cat Dancing\"\n" << endl;
    return 0;
}


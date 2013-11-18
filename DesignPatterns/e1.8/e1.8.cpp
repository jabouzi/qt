#include <QString>
#include <QTextStream>

QTextStream out(stdout);  /* Define QTextStreams that look like C++ 
                            standard iostreams. */
QTextStream in(stdin);

int main() {
    QString s1("This "), s2("is a "), s3("string.");
    s1 += s2;  // concatenation
    QString s4 = s1 + s3;
    out << s4 << endl;
    out << "The length of that string is " << s4.length() << endl;
    out << "Enter a sentence with whitespaces: " << endl;
    s2 = in.readLine();   /* not iostream, QTextStream::readLine()! */
    out << "Here is your sentence: \n" << s2 << endl;
    out << "The length of your sentence is: " << s2.length() << endl;
    return 0;
}


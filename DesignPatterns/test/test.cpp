#include <QApplication>
#include <QCoreApplication>
#include <QProcess>
#include <QString>
#include <QTextStream>
  /* Define QTextStreams that look like C++ 
                            standard iostreams. */
//QTextStream cin(stdin);

int main(int argc, char* argv[])
{    
    QApplication app(argc, argv);
    QTextStream cout(stdout);
    QString path = QCoreApplication::applicationDirPath();
    if (path.data()[path.size() - 1] != '/') path += "/";
    QProcess::startDetached(path+"Notepad");
    
    return 0;
}


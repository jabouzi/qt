//start id="writing"
#include <iostream>
#include <sstream>
#include <fstream>

int main() {
    using namespace std;
    ostringstream strbuf;

    int lucky = 7;
    float pi=3.14;
    double e=2.71;
    string filename = "";
    char yesno = 'n';
    
    cout << "get file name : " << flush;
    cin >> filename;

    cout << "An in-memory stream" << endl;
    strbuf << "luckynumber: " << lucky << endl
           << "pi: " << pi << endl
           << "e: " << e << endl;

    string strval = strbuf.str(); /* Convert the stringstream to a string. */
    cout << strval;

    ofstream outf;                /* An output file stream. */
    outf.open(filename.c_str());          /* Creates (or overwrites) a disk file for output. */
    if (outf)
    {
        cout << "file " << filename << " alrady exists overwrite it ?  y / n " << flush;
        cin >> yesno;
        if (yesno == 'y')
        {
            outf << strval ;
        }
        else
        {
            return 0;
        }
    }
    
    outf.close();
//end

//start id="reading"
    cout << "Read data from the file - watch for errors." << endl;
    int newstr;
    ifstream inf;  /* An input file stream */
    inf.open(filename.c_str());
    if(inf) {  /* Make sure the file exists before attempting to read. */
      int lucky2;
      inf >> newstr >> lucky2;
      if (lucky != lucky2)
        cerr << "ERROR! wrong " << newstr << lucky2  << endl;
      else
        cout << newstr << " OK" << endl;

      int pi2;
      inf >> newstr >> pi2;
      if (pi2 != pi)
        cerr << "ERROR! Wrong " << newstr << pi2 << endl;
      else
        cout << newstr << " OK" << endl;

      int e2;
      inf >> newstr >> e2;
      if (e2 != e)
        cerr << "ERROR: Wrong " << newstr << e2 <<  endl;
      else
        cout << newstr << " OK" << endl;
      inf.close();
    }
//end
//start id="getline"
    /*cout << "Read from file line-by-line" << endl;
    inf.open("mydata");
    if(inf) {
      while (not inf.eof()) {
        getline(inf, newstr);
        cout << newstr << endl;
      }
      inf.close();
    }*/
    return 0;
}
//end


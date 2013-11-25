#include <iostream>
using namespace std;

int main() {
 int* ip = 0;               /* null pointer */
 delete ip;                 /* has no effect at all - ip is still null. */
 if(ip) cout << "non-null" << endl;
 else cout << "null" << endl;
 ip = new int;              /* allocate space for an int */
 int* jp = new int(13);     /* allocate and initialize */
 //[...]      
 cout << *ip << endl;
 cout << *jp << endl;
 delete ip;                 /* Without this, we have a memory leak. */
 delete jp;
 cout << *ip << '\t' << ip << endl;
 cout << *jp << '\t' << jp << endl;
 char c('k' + 5);
 cout << c << endl;
}

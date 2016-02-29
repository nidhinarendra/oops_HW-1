#include <iostream>
using namespace std;
int main()
{
double one = 1.000,two = 1.414,three = 1.732,four = 2.000,five = 2.236;
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision (3);
cout << "\tN\t" << "Square Root" << endl 
	<< "\t1\t"  << one << endl
	<< "\t2\t"  << two <<endl
	<< "\t3\t"  << three << endl
	<< "\t4\t"  << four << endl
	<< "\t5\t"  << five << endl;
return 0;

}

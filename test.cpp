#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int main(int argc, char *argv[])
{
cout << argc << endl << argv[0]<<endl;
double i;
double a=0;
char input_data[100];
double number;
string stream1;
string stream2;
	if (argc <= 2) 
	{
	ifstream file;
	file.open(argv[1]);
	cout << "File opened"<<endl;
		while(!file.eof()){
			file >> stream1;
			stringstream stream2(stream1);
			while ( getline (stream2, stream1, ',')){
				stringstream ss(stream1);
				ss >> i;
				if ( ss ) cout << i <<endl;
				
			}
		
		}
file.close();
	}
	else
	{
	cerr << "invalid input" <<endl;
	}
return 0;
}


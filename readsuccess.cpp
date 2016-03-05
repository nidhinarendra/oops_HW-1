#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int main(int argc, char *argv[])
{
cout << argc << endl << argv[0]<<endl;
int i;
int a=0;
char input_data[100];
int number;
string stream1;
string stream2;
	if (argc <= 2) 
	{
	ifstream file;
	file.open(argv[1]);
	cout << "File opened"<<endl;
		while(!file.eof()){
			file >> stream1;
			istringstream stream2(stream1);
			while ( getline (stream2, stream1, ',')){
			if ( file.eof()) break;
			cout << stream1 <<endl;
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


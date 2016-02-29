#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct vehicle
{
int wheels;
double price;
char *color;
int horsepower;
};


int main()
{
  string car;
  cout << "You want the details of bmw or honda?\n";
  cin >> car;
  cout<< "The details for " << car << " are as below\n";
  if (car == "bmw")
   {	
	int a;
	int *a;
	a = new int [4];
	
	int **a;
	*a = new int [4];

	vehicle **car;
	*car = new vehicle (sizeof(struct vehicle)));

	for (i=0; i<=2; i++)
		{
		 cars[i] 
	
//	vehicle *bmw;
//	bmw = new vehicle (sizeof(struct vehicle));	
	bmw->wheels = 456565;
	bmw->price =  45.50;
	bmw->color = (char*)"Black";
	bmw->horsepower = 300;
 	cout << "It has " << bmw->wheels << " wheels" << endl << "It is " << bmw->price << "Lacs" <<endl << "Its color is " << bmw->color << endl << "The horsepower is " 		<< bmw->horsepower << "hp" << endl;
	
    }
   else if (car == "honda")
    {
	vehicle honda;	
	honda.wheels = 3;
	honda.price = 10.98;
	honda.color = (char*)"White";
	honda.horsepower = 100;
 	cout << "It has " << honda.wheels << " wheels" << endl << "It is " << honda.price << "Lacs" 	<<endl << "Its color is " << honda.color << endl << "The horsepower is " 
	<< honda.horsepower << "hp" << endl;

    }

return 0;
}

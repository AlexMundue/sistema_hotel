// extract to string
#include <iostream>
#include <string>
using namespace std;

int main ()
{
  string name;

  cout << "Please, enter your full name: ";
  getline (cin,name);
  cout << "Hello, " << name << "!\n"<<endl<<endl;
	string other;
	getline (cin,name);
	other = name;
	cout<<other;
	name = "Something else\n\n";
	getline (cin,name);
	cout<<endl<<other<<"This is name now: "<<name;
  return 0;
}

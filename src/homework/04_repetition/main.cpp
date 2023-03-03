//write include statements
#include "dna.h"
//write using statements
using std::cout; using std::cin;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{
	auto selection = 0;
	do
	{
		display_menu();
		cout<<"Enter Menu Option: ";
		cin>>selection;
		handle_menu_option(selection);
	}
	while(selection !=3);
	return 0;
}
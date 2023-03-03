#include "func.h"

int main() 
{
	auto choice = 0;
	do
	{
		display_menu();
		cout<<"Enter Menu Option ";
		cin>>choice;
		menu(choice);
	}
	while(choice !=3);
	return 0;
}
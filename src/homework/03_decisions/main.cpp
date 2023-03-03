//write include statements
#include "decisions.h"

int main() 
{
	auto grade = 0;
	int selection = 0;
	cout<<"MAIN MENU \n";
	cout<<"\n";
	cout<<"1-Letter Grade using if \n";
	cout<<"2-Letter Grade using switch \n";
	cout<<"3-Exit \n";
	cout<<"Please select option: \n";
	cin>> selection;
	if (selection == 1)
	{
		cout<<"Enter your grade: ";
		cin>>grade;
		if (grade >= 0 && grade <= 100)
		{
			auto result = get_letter_grade_using_if(grade);
			cout<<"Your Letter grade using if is: "<<result<<"\n";
		}
		else
		{
			cout<<"Grade is out of range \n";
		}
	}
	else if (selection == 2)
	{
		cout<<"Enter your grade: ";
		cin>>grade;
		if (grade >= 0 && grade <= 100)
		{
			auto result = get_letter_grade_using_switch(grade);
			cout<<"Your Letter grade using switch is: "<<result<<"\n";
		}
		else
		{
			cout<<"Grade is out of range \n";
		}
	}
	else if (selection == 3)
	{
		cout<<"Exiting \n";
	}
	else
	{
		cout<<"Invalid selection... Exiting";
	}
	
	return 0;
}
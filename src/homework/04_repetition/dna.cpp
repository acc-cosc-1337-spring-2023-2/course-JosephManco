//add include statements
#include "dna.h"
//add function(s) code here
int factorial(int num)
{
    auto fact = 1;
    for (auto i = num; i > 0; i--)
    {
        fact *= i;
    }
    return fact;
}

int gcd(int num1, int num2)
{
    auto gcd = 1;
    if (num1 < num2)
    {
        int temp = num2;
        num2 = num1;
        num1 = temp;
    }
    for(auto i = 1; i <= num2; i++)
    {
        if(num1 % i == 0 && num2 % i ==0)
        {
            gcd = i;
        }
    }
    return gcd;
}
void display_menu()
{
    cout<<"\n Main Menu \n";
    cout<<"\n";
    cout<<"1-Factorial \n";
    cout<<"2-Greatest Common Divisor \n";
    cout<<"3-Exit\n";
}
void handle_menu_option(int selection)
{
    int num, num1, num2; string confirm; int result;
    switch(selection)
    {
        case 1:
            cout<<"Enter positive number: ";
            cin>>num;
            if (num > 0)
            {
                result = factorial(num);
                cout<<"The factorial of "<<num<<" is "<<result<<"\n";
            }
            else
            {
                cout<<"Error factorials must be positive";
            }
            break;
        case 2:
            cout<<"Enter First number: ";
            cin>>num1;
            cout<<"Enter Second Number: ";
            cin>>num2;
            result = gcd(num1, num2);
            cout<<"The greatest common Divisor is "<<result<<"\n";
            break;
        case 3:
            cout<<"Are you sure you want to Exit(Y/N): ";
            cin>>confirm;
            break;
        default:
            cout<<"Please select valid option ";
            break;
    }
}
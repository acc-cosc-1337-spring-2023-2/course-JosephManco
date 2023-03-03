#include "expressions.h"
#include "hwexpressions.h"
//example
int add_numbers(int num1, int num2)
{
	return num1 + num2;
}

//write function code here
double get_sales_tax_amount(double meal_amount)
{
	auto sales_tax_amount = meal_amount * tax_rate;
	return sales_tax_amount; 
}

double get_tip_amount(double tip_rate, double meal_amount)
{
	auto tip_amount = tip_rate * meal_amount;
	return tip_amount;
}


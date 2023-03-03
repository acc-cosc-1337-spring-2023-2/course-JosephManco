//write include statement for decisions header
#include "decisions.h"
//Write code for function(s) code here
string get_letter_grade_using_if(int grade)
{
    string result;
    if(grade >= 0 && grade <= 59)
    {
        result = "F";
    }
    else if(grade >=  60 && grade <= 69)
    {
        result = "D";
    }
    else if(grade >= 70 && grade <= 79)
    {
        result = "C";
    }
    else if(grade >= 80 && grade <=89)
    {
        result = "B";
    }
    else if(grade >= 90 && grade <= 100)
    {
        result = "A";
    }

    return result;
}
string get_letter_grade_using_switch(int grade)
{
    string result;
    switch(grade)
    {
        case 0 ... 59:
            result = "F";
            break;
        case 60 ...69:
            result = "D";
            break;
        case 70 ... 79:
            result = "C";
            break;
        case 80 ... 89:
            result = "B";
            break;
        case 90 ... 100:
            result = "A";
            break;
        default:
            break;
    }

    return result;
}
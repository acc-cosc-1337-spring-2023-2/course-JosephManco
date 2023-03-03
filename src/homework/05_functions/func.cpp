//add include statements
#include "func.h"
double get_gc_content(const string& dna)
{
    double result = 0.0;
    int length = dna.length();
    double gc_count = 0;
    for(int i = 0; i < length; i++)
    {
        char count = dna[i];
        if (count == 'G' || count == 'C')
        {
            gc_count++;
        }
    }
        result = gc_count / length;
        return result;
}
string reverse_string(string dna)
{
    string rev = "";

    for(int i = dna.length() -1; i >= 0; i--)
    {
        rev = rev + dna[i];
    }
    return rev;
    
}

string get_dna_complement(string dna1)
{
    dna1 = reverse_string(dna1);
    for(size_t i = 0; i < dna1.length(); i++)
    {
      switch (dna1[i])
      {
        case 'A':
        dna1[i] = 'T';
        break;
        case 'T':
        dna1[i] = 'A';
        break;
        case 'G':
        dna1[i] = 'C';
        break;
        case 'C':
        dna1[i] = 'G';
        break;
      default:
        break;
      }
    }
    return dna1;
}
void display_menu()
{
    cout<<"\n Menu \n";
    cout<<"\n";
    cout<<"1.Get GC Content\n";
    cout<<"2.Get DNA Complement\n";
    cout<<"3.Exit\n";
    cout<<"\n";
}
void menu(int choice)
{
    string dna = "";
    string dna1;
        switch(choice)
        {
            case 1: 
                cout<<"Enter DNA string: ";
                cin>> dna;
                cout<<"The GC content is "<< get_gc_content(dna);

                //cout<<"Will run GC content Function \n";
            break;
            case 2:
                cout<<"Enter DNA string: ";
                cin>> dna1;
                cout<<"The DNA complement is "<< get_dna_complement(dna1);
            break;
            case 3:
                cout<<"Exiting";
            break;
            default:
                cout<<"Please Select Valid option \n";
            break;
        }
}

//add function code here
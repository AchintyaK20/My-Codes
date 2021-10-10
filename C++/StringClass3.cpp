// C++ code to demonstrate the working of
// begin(), end(), rbegin(), rend()
#include<iostream>
#include<string> // for string class
using namespace std;
int main()
{
    // Initializing string`
    int c=0;
    string str = "geeksforgeeks";

    // Declaring iterator
    string::iterator it;

    // Declaring reverse iterator
    string::reverse_iterator it1;

    // Displaying string
    cout << "The string using forward iterators is : ";
    for (it=str.begin(); it!=str.end(); it++)
    cout << *it;
    cout << endl;

    // Displaying reverse string
    cout << "The reverse string using reverse iterators is : ";
    for (it1=str.rbegin(); it1!=str.rend(); it1++)
    cout << *it1;
    cout << endl;
    
    //Number of words in string
    for(it = str.begin() ; it!=str.end() ; it++)
    {
        if (*it == ' ')
        {
            c++;
        }
    }
    printf("Number of words are %d",c+1);

    return 0;

}

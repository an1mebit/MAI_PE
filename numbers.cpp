#include <iostream>
 
using namespace std;
 
int main()
{
    int val, del = 1;
    int i = 0;
    cout << "Enter number: " << endl;
    cin >> val;

    while (del < abs(val))
    {
        i++;
        del = del * 10;
    }
    if (del > 10)
    {
        del = del / 10;
    }
    cout << val << " = ";
    while (del > 0)
    {
        cout << val / del;
        val = val % del;
        del = del / 10;
        i--;
        cout << "*10^" << i;
        if (del > 0)
            cout << " + ";
    }
    return 0;
}
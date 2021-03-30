#include <iostream>
#include <string>
using namespace std;

int pow(int n,int s)
{
    int res = 1;
    for(size_t i = 0; i != s; ++i)
        res*=n;
    return res;
}

void ten_base (int in, int base)
{
    if (in < base) {
        if (in % base < 10){
        cout << char (in % base + '0');
    }
    else {
        cout << char (in % base + 'A'- 10);
    }
        return;
    }
    ten_base (in / base, base);
    if (in % base < 10){
        cout << char(in % base + '0');
    }
    else {
        cout<< char (in % base + 'A'- 10);
    }
}
 
 
int main()
{
    int basein, baseout, sum=0, a, rank = 0;
    string str;
	cout << "Enter num & base for in n out" << endl;
	cin >> basein >> str >> baseout;
    rank = str.size() - 1;
	for (int i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) {
            a = str[i] - '0';
        }
        if (isalpha(str[i])) {
            a = str[i] - 'A' + 10;
        }
        sum += a * pow (basein , rank);
        rank--;
    }
    cout << sum << endl;
    ten_base (sum , baseout);
    return 0;
}
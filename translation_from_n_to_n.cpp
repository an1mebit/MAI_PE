#include <iostream>

using namespace std;
int desit = 0;

int Demical(int sistem1)
{
    char num;
    cin >> num >> num;
    while (num != ';')
    {
        desit *= sistem1;
        if (num >= '0' && num <= '9') {
            desit += static_cast<int>(num) - '0';
        }
        else if (num >= 'A') {
            desit += static_cast<int>(num) - 'A' + 10;
        }
        cin >> num;
    }
    return num;
}

void translate(int sistem2) {
    int max = 1;
    char num;
    int k;
    while (max <= desit) {
        max *= sistem2;
    }
    max /= sistem2;

    while (max >= 0)
    {
        int m = desit / max;
        desit = desit - m * max;
        k = m;
        if (k <= 9) {
            num = '0' + k;
        }
        else {
            num = 'A' + k - 10;
        }
        cout << num;
        max /= sistem2;
    }
}

int main() {
    int sistem1, sistem2;
    char num = 0;
    cin >> sistem1;
    num = Demical(sistem1);
    cin >> sistem2;
    cout << desit << endl;
    translate(sistem2);
}

#include <iostream>

using namespace std;
#define size 37000
uint16_t*mas = (uint16_t*)malloc(size);

void qsort (int l, int r)
{
    int w,x,left,right;
    left = l;
    right = r;
    x = mas[(l+r)/2];
    while (left <= right)
    {
        while (mas[left] < x)
            left++;
        while (x < mas[right])
            right--;
        if (left <= right)
        {
            w = mas[left];
            mas[left] = mas[right];
            mas[right] = w;
            left++;
            right--;
        }
    }
    if (l < right)
        qsort(l,right);
    if (left < r)
        qsort(left,r);
}
int main()
{
    int lenght, num;
    cin >> lenght >> num;
    for (int i = 0; i < lenght; i++)
        mas[i] = rand() % num + 1;
    for (int i = 0; i < lenght; i++)
        cout << mas[i] << " ";
    cout << endl;
    qsort(0,lenght-1);
    for (int i = 0; i < lenght; i++)
        cout << mas[i] << " ";
    free(mas);
    return 0;
}
//2.WAP to implement Euler's Totient function.
#include <iostream>
using namespace std;

int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main()
{
    int n;
    cout<<"Enter the number you want:";
    cin >> n;
    cout <<"The Euler's Totient function (Phi("<< n << "))= "<< phi(n) << endl;
    return 0;
}
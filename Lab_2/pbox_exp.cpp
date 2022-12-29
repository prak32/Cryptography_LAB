#include <bits/stdc++.h>
using namespace std;

vector<int> expand(vector<int> block)
{
    int pbox[] = {32, 1, 2, 3, 4, 5,
                  4, 5, 6, 7, 8, 9,
                  8, 9, 10, 11, 12, 13,
                  12, 13, 14, 15, 16, 17,
                  16, 17, 18, 19, 20, 21,
                  20, 21, 22, 23, 24, 25,
                  24, 25, 26, 27, 28, 29,
                  28, 29, 30, 31, 32, 1};

    vector<int> expanded(48);

    for (int i = 0; i < 48; i++)
        expanded[i] = block[pbox[i] - 1];

    return expanded;
}

int main()
{
    vector<int> block = {1, 0, 0, 1, 0, 0, 0, 1,
                         0, 1, 1, 0, 0, 1, 0, 0,
                         0, 0, 0, 1, 1, 0, 1, 1,
                         1, 1, 1, 0, 1, 1, 1, 1};

    vector<int> expanded = expand(block);

    for (int i = 0; i < 48; i++)
        cout << expanded[i] << " ";

    return 0;
}

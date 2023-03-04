//WAP in the language of your choice to exhaust primary memory.
#include <iostream>
using namespace std;
int main() {
    int mb = 1;
    while (true) {
        int* p = new int[mb * 1024 * 1024];
        for (int i = 0; i < mb * 1024 * 1024 / sizeof(int); i++) {
            p[i] = i;
        }
        mb++;
        cout << "Allocated " << mb << " MB of memory." << endl;
    }
    return 0;
}

#include <iostream>

using namespace std;

void Perm(int start, int End, int a[]) {

    if (start == End) {
        for (int i = 0; i < End; i++)
            cout << a[i] << ' ';
        cout << endl;
        return;
    }
    for (int i = start; i < End; i++) {
        swap(a[start], a[i]);
        Perm(start + 1, End, a);
        swap(a[i], a[start]);
    }
}

int main()
{
    int n=4,a[4]={1,2,3,4};
    Perm(0,n,a);
    //cout << "Hello world!" << endl;
    return 0;
}

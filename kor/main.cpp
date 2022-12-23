#include <iostream>

using namespace std;

void kor(int n)
{
    if(n == 1)
    {
        cout << ">" << endl;
        return;
    }

    kor(n / 2);
    for(int i = 0; i < n; i++)
    {
        cout << ">";
    }
    cout << endl;

    kor(n / 2);
}

int main()
{
    int n;
    cin >> n;

    kor(n);
}

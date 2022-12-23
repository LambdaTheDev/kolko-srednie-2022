#include <iostream>

using namespace std;

int main()
{
    int n, m;
    int possible = 0;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int p;
        cin >> p;

        possible += p;
    }

    int todo = max(0, n - possible);
    cout << todo;
}

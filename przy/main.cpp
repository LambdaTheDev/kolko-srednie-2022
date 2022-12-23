#include <iostream>

using namespace std;

int buffer[1000000];

int main()
{
    int n, m;
    cin >> n >> m;

    int magicButton = n + 1;
    int maxi = 0;
    int offset = 0;

    for(int i = 0; i < m; i++)
    {
        int p;
        cin >> p;

        if(p == magicButton)
        {
            for(int j = 0; j < n; j++)
            {
                buffer[j] = maxi;
            }
        }
        else
        {
            buffer[p - 1]++;
            maxi = max(buffer[p - 1], maxi);
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << buffer[i] << " ";
    }
}

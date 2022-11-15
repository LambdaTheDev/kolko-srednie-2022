#include <iostream>

using namespace std;

const int offset = 95;

int kWord[100];
int lWord[100];

int main()
{
    string k, l;
    cin >> k;
    cin >> l;

    if(k.length() != l.length())
    {
        cout << "NIE";
        return 0;
    }

    int maxChar = 0;

    for(int i = 0; i < k.length(); i++)
    {
        kWord[k[i] - offset]++;
        lWord[l[i] - offset]++;
        maxChar = max((int)(k[i] - offset), maxChar);
    }

    for(int i = 0; i < maxChar; i++)
    {
        if(kWord[i] != lWord[i])
        {
            cout << "NIE";
            return 0;
        }
    }

    cout << "TAK";
}

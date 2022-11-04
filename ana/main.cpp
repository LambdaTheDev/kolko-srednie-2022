#include <iostream>

using namespace std;

int kWord[100];
int lWord[100];

int main()
{
    string k, l;
    getline(cin, k);
    getline(cin, l);

    if(k.length() != l.length())
    {
        cout << "NIE" << endl;
        return 0;
    }

    int maxChar = 0;

    for(int i = 0; i < k.length(); i++)
    {
        kWord[k[i] - 95]++;
        lWord[l[i] - 95]++;
        maxChar = max((int)(k[i] - 95), maxChar);
    }

    for(int i = 0; i < maxChar; i++)
    {
        if(kWord[i] != lWord[i])
        {
            cout << "NIE" << endl;
            return 0;
        }
    }

    cout << "TAK" << endl;
}

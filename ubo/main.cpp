#include <iostream>

using namespace std;

int buffer[1000000];
int skippedIndexesCount[100000];

int binSearch(int searchedValue, int from, int to)
{
    if(from > to) return -1;

    int target = (from + to) / 2;
    if(searchedValue == buffer[target] && buffer[target + 1] > searchedValue)
        return target;

    if(searchedValue < buffer[target])
        return binSearch(searchedValue, from, target - 1);
    else return binSearch(searchedValue, target + 1, to);
}

int main()
{
    int n;
    cin >> n;

    int updatedBufferCount = 0;
    int lastValue = -1;

    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;

        if(t > lastValue)
        {
            buffer[updatedBufferCount++] = t;
        }
        else
        {
            skippedIndexesCount[updatedBufferCount]++;
        }
    }

    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int check;
        cin >> check;

        check++; // to find at least greater
        int index = binSearch(check, 0, updatedBufferCount);
        if(index == -1)
        {
            cout << "b ";
        }
        else
        {

            cout << index << " ";
        }
    }
}

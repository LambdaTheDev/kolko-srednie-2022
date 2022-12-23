#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int buffer[1000000];
int skippedIndexesCount[100000];


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
            lastValue = t;

            skippedIndexesCount[updatedBufferCount - 1] += skippedIndexesCount[updatedBufferCount - 2];
        }
        else
        {
            skippedIndexesCount[updatedBufferCount - 1]++;
        }
    }

    skippedIndexesCount[updatedBufferCount] = skippedIndexesCount[updatedBufferCount - 1];

//    cout << endl << "DEBUG OF NEW ARR: " << endl;
//    for(int i = 0; i < updatedBufferCount; i++)
//    {
//        cout << buffer[i] << " ";
//    }
//
//    cout << endl << "DEBUG OF SKIPPED: " << endl;
//    for(int i = 0; i < updatedBufferCount; i++)
//    {
//        cout << skippedIndexesCount[i] << " ";
//    }
//    cout << endl << endl;

    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int check;
        cin >> check;

        if(check > buffer[updatedBufferCount - 1])
        {
            cout << "b ";
            continue;
        }
        else if(check < buffer[0])
        {
            cout << "1 ";
            continue;
        }


        check++;
        int* ptr = upper_bound(buffer, buffer + updatedBufferCount, check);
        int index = ptr - buffer;

        int actualIndex = index + skippedIndexesCount[index];
        cout << actualIndex << " ";
    }
}

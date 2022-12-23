#include <iostream>

using namespace std;

char buffer[100];

void display(int count)
{
    for(int i = count - 1; i >= 0; i--)
    {
        cout << buffer[i];
    }
}

int main()
{
    string input = "xyz/abc/123";
    cin >> input;

    int count = 0;

    for(int i = input.length() - 1; i >= 0; i--)
    {
        if(input[i] == '/')
        {
            // Display expected value
//            cout << "DISPLAYING: " << actualOffset << "; " << count << endl;
            display(count);
            cout << '/';

            // Reset buffer
            count = 0;
        }
        else
        {
            buffer[count++] = input[i];
        }
    }

    display(count);
}

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string input;
    getline(cin, input);

//    replace(input.begin(), input.end(), ' ', '-');
//
//    cout << input;
//    return 0;

    int prevWordOffset = 0;
    int prevWordCount = 0;

    int wordOffset = 0;
    int wordCount = 0;

    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] == ' ')
        {
            // if not first word, perform modifications
            if(prevWordCount != 0)
            {
                int lastPrevWordCharPos = prevWordOffset + prevWordCount - 1;
                int firstWordCharPos = wordOffset;

                char temp = input[lastPrevWordCharPos];
                input[lastPrevWordCharPos] = input[firstWordCharPos];
                input[firstWordCharPos] = temp;
//                cout << "REPLACING " << input[lastPrevWordCharPos] << " WITH " << input[firstWordCharPos] << endl;
            }


            //region debug

//            cout << "PREV WORD: ";
//            for(int j = 0; j < prevWordCount; j++)
//            {
//                cout << input[prevWordOffset + j];
//            }
//            cout << endl;
//
//            cout << "CURRENT WORD: ";
//            for(int j = 0; j < wordCount; j++)
//            {
//                cout << input[wordOffset + j];
//            }
//            cout << endl << endl;

            // endregion

            // Set previous word & reset current
            prevWordOffset = wordOffset;
            prevWordCount = wordCount;

            wordOffset = i + 1;
            wordCount = 0;
        }
        else
        {
            wordCount++;
        }
    }

    // Last part replacement
    if(prevWordCount != 0)
    {
        char tempLastPart = input[wordOffset];
        input[wordOffset] = input[prevWordOffset + prevWordCount - 1];
        input[prevWordOffset + prevWordCount - 1] = tempLastPart;
    }

    // Finalize, replace first & last char
    char tempFinal = input[0];
    input[0] = input[input.length() - 1];
    input[input.length() - 1] = tempFinal;

    // Display
    cout << input;
    cout << endl;
}

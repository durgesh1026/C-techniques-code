/***************************************************************************************************************/
/******************************* Decryption of Caeser Cipher by frequency attack *******************************/
/***************************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Create a string to store Plain Text
    string pText = "A SIMPLE MESSAGE";
    // Create a key to convert Plain Text into Cipher Text
    int key = 3;
    // Create a vector to store Cipher Text
    vector<char> cText(pText.size());
    // Create a vector to store frequency of Cipher Text
    vector<int> frq(26);


    // Convert Plain Text into Cipher Text using Key
    /*** To Convert Text into cipher shift all plain text by key times***/
    for (int i = 0; i < pText.size(); i++)
    {
        if (pText[i] != ' ')
        {

            cText[i] = (pText[i]-'A' + key)%26+'A';
        }
        else{
            cText[i] =pText[i];
        }
    }

    // Print Cipher Text
    cout<<"Encryption of Plain Text ..."<<endl<<endl;
    for (int i = 0; i < cText.size(); i++)
    {
        cout << cText[i];
    }
    cout << endl<<endl;

    // count Frequency of cipher text
    for (int i = 0; i < cText.size(); i++)
    {
        if (cText[i] != ' ')
        {
            frq[cText[i] - 'A']++;
        }
    }

    cout << "Decryption of Cipher Text ..."<<endl<<endl;
    cout<< "Print all 10 possible outcomes: "<<endl<<endl;

    for (int i = 0; i < 26; i++)    /*iterate i for top 10 cases*/
    {
        int index = distance(frq.begin(), max_element(frq.begin(), frq.end()));            /*get a index of highest frequency */

        int new_key = index - ('E' - 'A');                       /*find key by finding the index of most occuring character and then decrease it by index of E*/
       
        string s = "";
        for (int j = 0; j < cText.size(); j++)
        {
            int idx = 0;
            if (cText[j] != ' ')
            {
                idx = (cText[j] - 'A') - new_key;
                // cout << idx << " ";
                if (idx >= 0)                       /*here idx is positive so shift all characters backward to find original character*/
                {
                    cText[j] = (idx%26 + 'A');
                }
                else
                {
                    cText[j] = idx + 26 + 'A';      /*here idx is negetive so shift all characters forward to find original character*/
                }
            }

            s = s + cText[j];                       /*here save all string who has changed*/
        }
        // cout << endl;
        frq[index] = 0;                             /*store all string to a vector and print all string */
    cout << s << endl;
    }
}
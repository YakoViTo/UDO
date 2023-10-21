#include <iostream>
#include <vector>
using namespace std;

/*
    Try This! - Write a program that "bleeps" out words that you dislike. Read words using 'cin' and
    print them, and if a word that you defined is amongst them.

*/

int main()
{
    vector <string> disliked_words = {"fuck", "shit", "acid", "yolo", "swag", ":v", "ayyy lmao"};
    
    for (string word; cin >> word;)
        for (int i = 0; i < disliked_words.size(); i++)
            if (disliked_words[i] == word) {
                 cout << "BLEEP" << " ";
                 break;
            }
            else
                if (i == disliked_words.size() - 1)
                    cout << word << " ";
        
    
    return 0;
}

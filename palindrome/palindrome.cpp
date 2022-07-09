// Program that checks if a given string is a palindrome or not
// Several ways to check: check and remove the first and last letter until the end. If equal then it is a palindrome
// Another way is to reverse a string and check if it is equal to the original string
// In this program, I will explore using the deque data structure

#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
// #include <chrono>

using namespace std;

// Function that keeps only alphabet letters in string and removes nonalphanumeric characters and spaces
string onlyAlphabet(string word){
    int j = 0;
    for(int i = 0; i<word.size(); i++){
        if((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z')){
            word[j] = word[i];
            j++;
        }
    }
    return word.substr(0, j);
}
//Function to check if string is a palindrome using deque data structure
bool palindromeDQ(string str){
    deque<char> dq;
    for(int i = 0; i<str.size(); i++){ //loads each letter into the deque
        dq.push_front(tolower(str.at(i)));
    }
    while(!dq.empty()){ //While deque is not empty
        if(dq.size() == 1){ // if size of dq is 1 then string is a palindrome
            return true;
        }
        if(dq.front() != dq.back()){ // if the first letter and last letter are not the same then the string is not a palindrome
            return false;
        }
        // If the if statements are passed then pop the front and back and repeat until dq is empty
        dq.pop_back();
        dq.pop_front();
    }

    return true; // Return true if all empty
}

int main(){
    string word;
    cout << "Enter a word to check if palindrome: ";
    getline(cin, word);
    cout << "Word entered: " << word << endl;
    word = onlyAlphabet(word);
    cout << "Word with non-alphanumeric and spaces removed: " << word << endl;
    // word.erase(remove(word.begin(), word.end(), ' '), word.end());

    bool isPalindrome = palindromeDQ(word);
    if(isPalindrome) cout << word << " is a palindrome." << endl;
    else cout << word << " is not a palindrome." << endl;
}
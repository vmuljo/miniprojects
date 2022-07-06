#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Program to reverse a string using stack data structure.
// Sets to look for another way to reverse a string instead of the iterating from last string index (although added in this program as a separate function)

//Function that reverses a string the original way (O(n) time complexity)
string reverseStringOG(string str){
    string reversed;
    
    //Loops through from the end of the string and adds each char to the new string until iterates to the front 
    for(int i = str.size()-1; i >= 0; i--){
        reversed.push_back(str.at(i));
    }
    return reversed;
}

//Function that reverses a string using a stack (O(n) time complexity)
string reverseStringStack(string word){
    stack<char> str;
    // Loops through the string to push each char into the stack
    for(int i = 0; i < word.size(); i++){
        str.push(word.at(i)); 
    }
    word.clear(); //Clears the string so it can be loaded in

    // While the stack is not empty
    while (!str.empty()){
        char letter = str.top(); // Gets the char at the end of the stack, which should be the letter at the end of string
        word.push_back(letter); // Use push_back() to add a single letter to the string. Time complexity O(1)
        str.pop(); //Removes the letter at the top
    }

    return word;
}

int main(){
    string word;
    cout << "Enter a word: ";
    cin >> word;
    cout << "Initial word: " << word << endl;

    //Prints out the reversed word using normal method
    cout << "Reversed Word OG: " << reverseStringOG(word) << endl;

    //Prints out the reversed word using stack data structure
    cout << "Reversed Word: " << reverseStringStack(word) << endl;
}
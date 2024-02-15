//CodeWars Project Kata 2 (C++)
//Uploaded to GitHub
//This code reverses the words within a string if the length of the 
//word is greater than 4. A stack is implemented which facilitates 
//reversal of the characters naturally.

#include <string>
#include <stack>
#include <iostream>
using namespace std;

//Function prototypes
std::string spinWords(const std::string& str);
std::string reverseIt(std::string& word);

int main()
{   //Set the input string.
    string ostr = "The quick brown fox";
    //Call spinWords on old string and set new string to result
    string nstr = spinWords(ostr);
    //Display result
    cout << nstr << endl;
    return 0;
}

//spinWords performs the check if the current word is greater than 4;
//and if so, passes it to reverseIt. Takes a reference to the string --
//original can't be modified.
std::string spinWords(const std::string& str) {
    auto beginIndex = 0;    //Marks the beginning of a word
    auto endIndex = 0;      //Marks the ending of a word
    string retString;
    string tempWord;

    //Iterates over each character until it finds a space
    //or until it reaches the end of the line
    for (unsigned int i = beginIndex; i <= str.size(); i++) {
        if (str[i] == ' ' || i == str.size()) {
            //Sets endIndex to the index after the last character of a word
            endIndex = i;

            //If word length is greater than 4, reverse it...
            if (endIndex - beginIndex > 4) {
                //Captures the word from the line and copies it to tempWord
                tempWord = str.substr(beginIndex, endIndex - beginIndex);
                //Call reverseIt and append the reversed word to the line
                retString += reverseIt(tempWord);
            }
            //...else append the word to the line as-is
            else
                retString += str.substr(beginIndex, endIndex - beginIndex);

            //Sets beginIndex to the first index after the last word 
            //before loop iterates over again
            beginIndex = endIndex + 1;
            //If not at the end of the line, add a space after the last word.
            if (beginIndex < str.size())
                retString += ' ';
        }
    }
    return retString;
}

//reverseIt reverses the order of the characters in the word passed to it
std::string reverseIt(std::string& word) {
    stack<char> char_stack;
    string retWord;

    //For each character in word, push it to the stack
    for (char& ch : word)
        char_stack.push(ch);

    //Until the stack is empty, pop each character in 
    //the reverse order it was pushed
    while (!char_stack.empty()) {
        retWord += char_stack.top();
        char_stack.pop();
    }
    return retWord;
}
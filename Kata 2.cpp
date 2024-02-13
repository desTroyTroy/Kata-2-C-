#include <string>
#include <stack>
#include <iostream>
using namespace std;
std::string spinWords(const std::string& str);
std::string reverseIt(std::string& word);
int main()
{
    string ostr = "The quick brown fox";
    string nstr = spinWords(ostr);
    cout << nstr << endl;


    return 0;
}

std::string spinWords(const std::string& str) {
    auto beginIndex = 0;
    auto endIndex = 0;
    string retString;
    string tempWord;
    for (int i = beginIndex; i <= str.size(); i++) {
        if (str[i] == ' ' || i == str.size()) {
            endIndex = i;
            if (endIndex - beginIndex > 4) {
                tempWord = str.substr(beginIndex, endIndex - beginIndex);
                retString += reverseIt(tempWord);
            }
            else
                retString += str.substr(beginIndex, endIndex - beginIndex);

            beginIndex = endIndex + 1;
            if (beginIndex < str.size())
                retString += ' ';
        }
    }
    return retString;
}

std::string reverseIt(std::string& word) {
    stack<char> char_stack;
    string retWord;
    for (char& ch : word)
        char_stack.push(ch);
    while (char_stack.size()) {
        retWord += char_stack.top();
        char_stack.pop();
    }
    return retWord;
}
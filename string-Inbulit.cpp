#include<iostream>
using namespace std;

is_sorted(s.begin(),s.end());
char c = tolower(a);
c = toUpper(a)

string str = "Hello World";
str.empty();
str.find("World");
str.substr(6, 5); // sub will be "World"
str.replace(6, 5, "Universe"); // str will be "Hello Universe"
str.erase(5, 6); // str will be "Hello"


bool b = isalpha(c);
b = isdigit(c);
b = isalnum(c);// alpha numeric
b = isupper(c);
b = islpper(c)
bool isVowel(char c);


bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

vector<int> parseAndFillVector(const string& numberString, char separator) {
    vector<int> numbers;
    stringstream ss(numberString);
    string token;

    while (getline(ss, token, separator)) {
        int number = stoi(token);
        numbers.push_back(number);
    }

    return numbers;
}

int main(){
    
    return 0;
}
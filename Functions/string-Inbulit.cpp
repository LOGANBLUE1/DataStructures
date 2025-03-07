#include<iostream>
using namespace std;

void character(){
    char c;
    isalpha(c);
    isdigit(c);
    isalnum(c);
    isupper(c);
    islower(c);

    tolower(c);
    toupper(c);
}

void String(){
    string s;
    s.empty();
    s.size();
    s.find("World");
    s.substr(6, 5); // pos, len
    s.replace(6, 5, "Universe"); // str will be "Hello Universe"
    s.erase(5, 6); // str will be "Hello"
}




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
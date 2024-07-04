#include <iostream>
#include <algorithm>
using namespace std;


bool check_if_sorted(string str);
vector<int> stringToNumberVector(const string& numberString, char separator);

vector<string> stringToWordsVector(const string &sentence, char separator);
vector<string> stringToWordsVector(string &sentence);//seperotor is ' ' eg. This is a school. 


bool ignore_case(char a, char b){
	// Converts both characters to lowercase and checks if a <= b
	return (tolower(a) <= tolower(b));
}

bool check_if_sorted(string str){
	return is_sorted(str.begin(), str.end(), ignore_case);
}


vector<int> stringToNumberVector(const string& numberString, char separator) {
    vector<int> numbers;
    stringstream ss(numberString);
    string token;

    while (getline(ss, token, separator)) {
        int number = stoi(token);
        numbers.push_back(number);
    }

    return numbers;
}

vector<string> stringToWordsVector(const string &sentence, char separator) {
    vector<string> result;
    stringstream ss(sentence);
    string item;
    
    while (getline(ss, item, separator)) {
        result.push_back(item);
    }

    return result;
}

vector<string> stringToWordsVector(string &sentence) {
    vector<string> v;
    istringstream iss(sentence);
    string word;
    
    while (iss >> word) {
        v.push_back(word);
    }

    return v;
}

int main(){
	
	string str = "AdHorSwZ";

	
	if (check_if_sorted(str)) {
		cout << "Sorted";
	}
	else {
		cout << "Not sorted";
	}

	return 0;
}

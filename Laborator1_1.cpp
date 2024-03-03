//Pentru conversia din Python in C++, am folosit: https://products.codeporting.app/convert/ai/python-to-cpp/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string A = "abc", B = "xyz", C = "123";

string read_string(string alphabet) {
    string s;
    while (true) {
        cout << "Introduce a string from the alphabet " << alphabet << ": ";
        cin >> s;
        if (all_of(s.begin(), s.end(), [alphabet](char c) { return alphabet.find(c) != string::npos; })) {
            return s;
        } else {
            cout << "The string isn't valid!\n";
        }
    }
}

string concatenate_strings(string s1, string s2) {
    return s1 + s2;
}

string reverse_string(string s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

string string_replace(string s, string sub, string new_sub) {
    string result = s;
    size_t pos = result.find(sub);
    if (pos != string::npos) {
        result.replace(pos, sub.length(), new_sub);
    }
    return result;
}

int string_length(string s) {
    return s.length();
}

int main() {
    string s1 = read_string(A), s2 = read_string(B), s3 = read_string(C);

    cout << "Concatenarea a două șiruri diferite: " << concatenate_strings(s1, s2) << " " << concatenate_strings(s1, s3) << " " << concatenate_strings(s2, s1)<< " " << concatenate_strings(s2, s3) << " " << concatenate_strings(s3, s1)<< " " << concatenate_strings(s3, s2) << endl;
    cout << "Inversarea șirurilor: " << reverse_string(s1) << " " << reverse_string(s2) << " " << reverse_string(s3) << endl;
    cout << "Substituția între alfabete: " << string_replace(s1, A, B) << " " << string_replace(s1, A, C) << " " << string_replace(s2, B, A) << " " << string_replace(s2, B, C) << " " << string_replace(s3, C, A) << " "<< string_replace(s3, C, B) << endl;
    cout << "Lungimea șirurilor: " << string_length(s1) << " " << string_length(s2) << " " << string_length(s3) << " " << endl;

    return 0;
}

//Pentru conversia din Python in C++, am folosit: https://products.codeporting.app/convert/ai/python-to-cpp/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

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

string repeat_string(string s, int n) {
    string result;
    for (int i = 0; i < n; ++i) {
        result += s;
    }
    return result;
}

string reverse_string(string s) {
    string reversed_s(s.rbegin(), s.rend());
    return reversed_s;
}

string extract_symbol(string s, int i, int j) {
    return s.substr(i - 1, j - i + 1);
}

string string_replace(string s, string sub, string new_sub) {
    if (s.find(sub) != string::npos) {
        s.replace(s.find(sub), sub.length(), new_sub);
    }
    return s;
}

int main() {
    string l1 = "0123456789", l2 = "abcdefghijk", l3 = "x1y1x2y2x3y3x4y4x5y5";

    string s1 = read_string(l1), s2 = read_string(l2), s3 = read_string(l3);

    cout << "Concatenarea a două șiruri diferite: " << concatenate_strings(s1, s2) << " " << concatenate_strings(s1, s3) << " " << concatenate_strings(s2, s1)<< " " << concatenate_strings(s2, s3) << " " << concatenate_strings(s3, s1)<< " " << concatenate_strings(s3, s2) << endl;
    cout << "Repetarea șirurilor: " << repeat_string(s1, 5) << " " << repeat_string(s2, 3) << " " << repeat_string(s3, 2) << endl;
    cout << "Inversarea șirurilor: " << reverse_string(s1) << " " << reverse_string(s2) << " " << reverse_string(s3) << endl;
    cout << "Extracție: " << extract_symbol(s1, 1, 9) << " " << extract_symbol(s3, 1, 3) << endl;
    cout << "Înlocuirea unor caractere: " << string_replace(s1, "2", "8") << " " << string_replace(s2, "j", "t") << " " << string_replace(s3, "5", "2") << endl;

    return 0;
}

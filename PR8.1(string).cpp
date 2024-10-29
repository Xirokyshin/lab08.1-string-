#include <iostream>
#include <string>
using namespace std;

int Count(const string s) {
    int k = 0;
    size_t pos = 0;
    while ((pos = s.find('n', pos)) != string::npos) {
        if (pos + 2 < s.length() && s[pos + 2] == 'o') {
            k++;
        }
        pos++; // ���������� �� ���������� �������
    }
    return k;
}

string Change(string& s) {
    size_t pos = 0;
    while ((pos = s.find('n', pos)) != string::npos) {
        if (pos + 2 < s.length() && s[pos + 2] == 'o') {
            s.replace(pos, 3, "**");
            pos += 2; // ���������� �������� ������
        }
        else {
            pos++; // ���������� �� ���������� �������
        }
    }
    return s;
}

int main() {
    string str;
    cout << "Enter string:" << endl;

    getline(cin, str);
    cout << "String contained " << Count(str) << " groups of 'n?o'" << endl;
    Change(str); // ����������� �����
    cout << "Modified string (result): " << str << endl; // �������� ����� ������������ �����

    return 0;
}

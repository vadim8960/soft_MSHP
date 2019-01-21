#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int bin2dec(string s) {
    int num = 0;
    for (int i = 0; i < s.size(); i++)
        num += ((int)(s[i] - 48) * pow(2, s.size() - 1 - i));
    return num;
}

string invertStr(string str) {
    string s;
    for (int i = str.size() - 1; i >= 0; i--)
        s += str[i];
    return s;
}


string add0(string s) {
    s = invertStr(s);
    while (s.size() % 8)
        s += '0';
    s = invertStr(s);
    return s;
}

int main() {
    string s_begin, s_read;
    cout << "Enter your alias-string:" << endl;
    getline(cin, s_read);
    for (int i = 0; i < s_read.size(); i++)
        if (s_read[i] != ' ')
            s_begin += s_read[i];
    cout << s_begin << endl;
    char first_bit = s_begin[0];
    vector <int> len_series;
    for (int i = 1; i < s_begin.size();) {
        int count = 0;
        while (s_begin[i] == '0') {
            count++;
            i++;
        }
        string bin_num;
        for (int j = 0; j <= count; j++, i++)
            bin_num += s_begin[i];
        len_series.push_back(bin2dec(bin_num));
    }
    for (int i = 0; i < len_series.size(); i++)
        cout << len_series[i] << " ";
    cout << endl;
    string s_bin_answer;
    for (int i = 0; i < len_series.size(); i++) {
        for (int j = 0; j < len_series[i]; j++)
            s_bin_answer += first_bit;
        first_bit = (first_bit == '0') ? '1' : '0';
    }
    s_bin_answer = add0(s_bin_answer);
    vector <int> answer;
    for (int i = 0; i < s_bin_answer.size() / 8; i++) {
        string nums;
        for (int j = 0; j < 8; j++)
            nums += s_bin_answer[i * 8 + j];
        answer.push_back(bin2dec(nums));
    }
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    cout << endl;
    return 0;
}

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

char bit1(string str) {
    int num = 0;
    for (int i = 0; i < str.size(); i += 2)
        num += (str[i] - 48);
    cout << num << " ";
    return ( (char) (num % 2 + 48) );
}

char bit2(string str) {
    int num = 0;
    for (int i = 1; i < str.size(); i += 4) {
        num += (str[i + 1] - 48);
        num += (str[i] - 48);
    }
    cout << num << " ";
    return ( (char) (num % 2 + 48) );
}

char bit4(string str) {
    int num = 0;
    for (int j = 0; j < 4; j++)
        num += (str[3 + j] - 48);
    for (int j = 0; j < 4; j++)
        num += (str[11 + j] - 48);
    cout << num << " ";
    return ( (char) (num % 2 + 48) );
}

char bit8(string str) {
    int num = 0;
    for (int i = 7; i < str.size(); i++)
        num += (str[i] - 48);
    cout << num << " ";
    return ( (char) (num % 2 + 48) );
}

string add0(string s) {
    while (s.size() % 8)
        s += '0';
    return s;
}

int main() {
    int count;
    cout << "Count of blocks: ";
    cin >> count;
    cout << "Enter your blocks:" << endl;
    string result;
    for (int i = 0; i < count; i++) {
        string str;
        cin >> str;
        string answ = "";
        answ += bit8(str);
        answ += bit4(str);
        answ += bit2(str);
        answ += bit1(str);
        cout << answ << endl;
        if (answ != "0000")
            str[bin2dec(answ) - 1] = ( str[bin2dec(answ) - 1] == '0' ? '1' : '0' );
        for (int j = 0; j < str.size(); j++)
            if (j != 0 && j != 1 && j != 3 && j != 7)
                result += str[j];
    }
    cout << result << endl;
    result = add0(result);
    cout << result << endl;
    vector <int> answer;
    for (int i = 0; i < result.size() / 8; i++) {
        string nums;
        for (int j = 0; j < 8; j++)
            nums += result[i * 8 + j];
        answer.push_back(bin2dec(nums));
    }
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    cout << endl;
    return 0;
}

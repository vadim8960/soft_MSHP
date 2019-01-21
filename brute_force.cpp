#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void inc(string &pass, vector <int> &numbers_pass, string alf, vector <int> numbers_alf) {
    ++numbers_pass[numbers_pass.size() - 1];
    if (numbers_pass[numbers_pass.size() - 1] >= alf.size()) {
        numbers_pass[numbers_pass.size() - 1] -= alf.size();
        int i;
        for (i = numbers_pass.size() - 2; i >= 0; --i) {
            ++numbers_pass[i];
            if (numbers_pass[i] < alf.size())
                break;
            numbers_pass[i] -= alf.size();
        }
        if (i == -1)
            numbers_pass.insert(numbers_pass.begin(), numbers_alf[0]);
    }
    pass = "";
    for (unsigned i = 0; i < numbers_pass.size(); ++i)
        pass.push_back(alf[numbers_pass[i]]);
}

int main() {    
    string alf("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ[]{}!@$-_()1234567890");
    unsigned down, up;
    cin >> down >> up;
    string pass(down, alf[0]);
    vector <int> numbers_alf;
    for (unsigned i = 0; i < alf.size(); ++i)
        numbers_alf.push_back(i);
    vector <int> numbers_pass(down, numbers_alf[0]);
    for (unsigned j = down; j <= up; ++j) {
        do {
            cout << pass << endl;
            inc(pass, numbers_pass, alf, numbers_alf);
        } while (pass.size() == j);
    }
    return 0;
}

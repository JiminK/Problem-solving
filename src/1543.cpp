#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // char document[2500];
    // char word[50];
    string document, word;
    getline(cin, document);
    getline(cin, word);

    int cnt = 0;
    int i = 0;
    if (document.length() < word.length()) {
		cout << 0 << "\n";
        return 0;
    }
    while (i < document.length() - word.length() + 1) {
        // cout << document.substr(i, word.length()) << "\n";
        // cout << word << "\n";
        if (document.substr(i, word.length()).compare(word) == 0) {
            cnt++;
            i = i + word.length();
        } else {
            i++;
        }
        // cout << "cnt " << cnt << "\n\n";
    }
    cout << cnt << "\n";

    return 0;
}
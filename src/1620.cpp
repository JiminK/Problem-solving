#include <iostream>
#include <map>

using namespace std;

int N, M;
map<string, int> pokeName;
map<int, string> pokeNum;

void getInput() {
    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        string temp; cin >> temp;
        pokeName.insert({temp, i+1});
        pokeNum.insert({i+1, temp});
    }

    for (int i=0; i<M; ++i) {
        string pokemon; cin >> pokemon;
        if (pokemon[0] >= 65) cout << pokeName[pokemon] << "\n";
        else cout << pokeNum[stoi(pokemon)] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}

// https://life-with-coding.tistory.com/305 : hash map (해시맵)
// https://youtu.be/Vi0hauJemxA : 해시맵 이해에 도움된 영상
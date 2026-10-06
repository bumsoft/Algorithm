#include <iostream>
#include <vector>

using namespace std;

int K, N;
vector<int> seq;

void choose(int depth) {
    if (depth == N) {
        for (int x : seq) cout << x << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= K; i++) {
        seq.push_back(i);
        choose(depth + 1);
        seq.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K >> N;
    choose(0);

    return 0;
}
// 回文自动机
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 2e6 + 5;

struct Node{
    Node *ch[26], *fail;
    int len, sum;
}tr[MAXN];

int n;
char s[MAXN];
int ncnt = 2;
Node *last;

Node *New(int len) {
    tr[ncnt].len = len;
    tr[ncnt].fail = &tr[0];
    for (int i = 0; i < 26; i++) tr[ncnt].ch[i] = &tr[0];
    return &tr[ncnt++];
}

Node *GetFail(Node *x, int pos) {
    while (s[pos - x->len - 1] != s[pos]) x = x->fail;
    return x;
}

void Init() {
    tr[0].len = 0; tr[1].len = -1;
    tr[0].fail = &tr[1]; tr[1].fail = &tr[0];
    for (int i = 0; i < 26; i++) tr[0].ch[i] = tr[1].ch[i] = &tr[0];
    last = &tr[0];
}

void Insert(int pos) {
    Node *cur = GetFail(last, pos);
    if (cur->ch[s[pos] - 'a'] == &tr[0]) {
        Node *now = New(cur->len + 2);
        now->fail = GetFail(cur->fail, pos)->ch[s[pos] - 'a'];
        now->sum = now->fail->sum + 1;
        cur->ch[s[pos] - 'a'] = now;
    }
    last = cur->ch[s[pos] - 'a'];
}

int main() {
    cin >> s + 1;
    n = strlen(s + 1);
    int k = 0;
    Init();
    for (int i = 1; i <= n; i++) {
        s[i] = (s[i] - 97 + k) % 26 + 97;
        Insert(i);
        cout << last->sum << " ";
        k = last->sum;
    }
    return 0;
}
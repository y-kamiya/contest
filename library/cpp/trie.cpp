#include <bits/stdc++.h>
using namespace std;

class ostreamFork {
public:
    ostream &os1,&os2;
    ostreamFork(ostream& os1, ostream& os2) : os1(os1), os2(os2) {}
};
template <class Data>
ostreamFork& operator<<(ostreamFork& osf, Data d) {
    osf.os1 << d; osf.os2 << d; return osf;
}
ostreamFork& operator<<(ostreamFork& osf, ostream& (*f)(ostream&)) {
    osf.os1 << f; osf.os2 << f; return osf;
}
template <class ManipData>
ostreamFork& operator<<(ostreamFork& osf, ostream& (*f)(ostream&, ManipData)) {
    osf.os1 << f; osf.os2 << f; return osf;
}

using ll = long long;

#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(ll i=n;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define FORR(i,a,b) for(ll i=(a);i>=(b);--i)
#define ALL(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define PRINT_DOUBLE(n, x) cout << std::fixed << std::setprecision(n) << x << endl;

void print() {};
void print(string s) { cout << s; }
template<typename Head> void print(Head h) { cout << h; }
template<typename Head, typename... Tail> void print(Head h, Tail... t);
template<typename... Tail> void print(string s, Tail... t);
template<typename T0, typename T1, typename... Tail> void print(pair<T0,T1> p, Tail... t);
template<template<class...> class Cont, typename... Ts, typename... Tail> void print(Cont<Ts...> ts, Tail... t);

template<typename... Tail>
void printnext(Tail... t) { cout << " "; print(t...); }

template<typename Head, typename... Tail>
void print(Head h, Tail... t) {
    cout << h; printnext(t...);
}
template<typename... Tail>
void print(string s, Tail... t) {
    cout << s; printnext(t...);
}
template<typename T0, typename T1, typename... Tail>
void print(pair<T0,T1> p, Tail... t) {
    cout << "(" << p.first << "," << p.second << ")";
    printnext(t...);
}
template<size_t N = 0, typename T>
void print_tuple(const T &t) {
    auto d = ", "; if constexpr(N == 0) d = "";
    if constexpr(N < tuple_size<T>::value) { cout << d << get<N>(t); print_tuple<N+1>(t);}
}
template<typename... Ts, typename... Tail>
void print(tuple<Ts...> h, Tail... t) {
    cout << "("; print_tuple(h); cout << ")";
}
template<template<class...> class Cont, typename... Ts, typename... Tail>
void print(Cont<Ts...> ts, Tail... t) {
    cout << "[";  for (const auto &e : ts) {print(e); cout << " ";} cout << "] ";
    printnext(t...);
}
#ifdef _DEBUG
#define DEBUG(...) { print(__VA_ARGS__); cout << endl; }
#else
#define DEBUG(...)
#endif
 

ofstream file("_output.txt");
ostreamFork osf(file, cout);

template<int char_size, int base>
struct Trie {
    struct Node {
        vector<int> next, accept;
        int c, common;
        Node(int c_) : c(c_), common(0) {
            next.assign(char_size, -1);
        }
    };
    vector<Node> nodes;
    int root;
    Trie() : root(0) {
        nodes.push_back(Node(root));
    }

    void insert(const string& word, int word_id) {
        int node_id = 0;
        REP(i, (int)word.size()) {
            int c = (int)(word[i] - base);
            int& next_id = nodes[node_id].next[c];
            if (next_id == -1) {
                next_id = (int)nodes.size();
                nodes.push_back(Node(c));
            }
            ++nodes[node_id].common;
            node_id = next_id;
        }
        ++nodes[node_id].common;
        nodes[node_id].accept.push_back(word_id);
    }

    void insert(const string& word) {
        insert(word, nodes[0].common);
    }

    bool search(const string& word, bool prefix = false) {
        int node_id = 0;
        REP(i, (int)word.size()) {
            int c = (int)(word[i] - base);
            int& next_id = nodes[node_id].next[c];
            if (next_id == -1) return false;
            node_id = next_id;
        }
        if (prefix) return true;
        return nodes[node_id].accept.size() > 0;
    }

    bool start_with(const string& prefix) {
        return search(prefix, true);
    }

    int count() const {
        return nodes[0].common;
    }

    int size() const {
        return (int)nodes.size();
    }

    int lcp(const string& word) {
        int node_id = 0;
        int ret = 0;
        REP(i, (int)word.size()) {
            int c = (int)(word[i] - base);
            int& next_id = nodes[node_id].next[c];
            node_id = next_id;
            if (nodes[node_id].common > 1) {
                ret = i+1;
            }
        }
        return ret;
    }
};

// https://atcoder.jp/contests/abc287/tasks/abc287_e
void _main() {
    int N;
    cin >> N;

    vector<string> S(N);
    REP(i, N) cin >> S[i];

    Trie<26, 'a'> trie;
    REP(i, N) {
        trie.insert(S[i]);
    }

    REP(i, N) {
        osf << trie.lcp(S[i]) << endl;
    }
}

int main() {
    _main();
    return 0;
}



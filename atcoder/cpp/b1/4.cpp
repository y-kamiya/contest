#include <cstdio>
#include <string>
#include <map>
#include <stack>

using namespace std;

typedef pair<int,int> P;
typedef map<int,int> M;

int floor5(int);
int ceil5(int);
int ceil60(int);

int main() {
    int n, s, e, ret;
    M schedule;

    ret = scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ret = scanf("%d-%d", &s, &e);
        schedule.insert(M::value_type(s, e));
    }

    int start, end;
    M formated_schedule;

    M::iterator it = schedule.begin();
    while (it != schedule.end()) {
        start = (*it).first;
        end = (*it).second;
        formated_schedule.insert(M::value_type(floor5(start), ceil5(end)));
        it++;
    }

    stack<P> st;
    P current, pre;

    it = formated_schedule.begin();
    while (it != formated_schedule.end()) {
        current = P((*it).first, (*it).second);
        if (st.empty()) {
            st.push(current);
        } else {
            pre = st.top();
            if (pre.second < current.first) {
                st.push(current);
            } else if (pre.second < current.second) {
                st.pop();
                pre.second = current.second;
                st.push(pre);
            }
        }
        it++;
    }

    P entry;
    schedule.clear();
    while (!st.empty()) {
        entry = st.top();
        schedule.insert(entry);
        st.pop();
    }

    it = schedule.begin();
    while (it != schedule.end()) {
        printf("%04d-%04d\n", (*it).first, (*it).second);
        it++;
    }

    return 0;
}

int floor5(int n) {
    return n - n % 5;
}

int ceil5(int n) {
    int r = n % 5;
    if (r == 0) {
        return n;
    } else {
        return ceil60(n + (5 - r));
    }
}

int ceil60(int n) {
    int r = n % 100;
    if (r != 60) {
        return n;
    }
    return n + 40;

}

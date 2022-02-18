#include <vector>
using namespace std;
vector<int> prefix_func(string s) {
    int n = s.size();
    vector<int> f(n); 
    for (int i = 1; i < n; i++) {
        int j = f[i - 1];
        while (j && s[i] != s[j]) j = f[j - 1];
        f[i] = j + (s[i] == s[j]);
    }
    return f;
}
 
int cnt_occ(string s, string t) {
    string ts = t + "#" + s;
    int n = t.size(), m = s.size(), nm = ts.size();
    auto f = prefix_func(ts);
    int res = 0;
    for (int i = n + 1; i < nm; i++) res += (f[i] == n);
    return res;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int numDistinct(string s, string t) { // estrutura obrigatoria do leetcode
    const int m = s.length();
    const int n = t.length();
    vector<unsigned long> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= m; ++i)
      for (int j = n; j >= 1; --j)
        if (s[i - 1] == t[j - 1])
          dp[j] += dp[j - 1];

    return dp[n];
  }
};

int main() {
    Solution sol;
    string s, t;

  
    cout << "Digite a string s: ";
    cin >> s;
    cout << "Digite a string t: ";
    cin >> t;

    
    int result = sol.numDistinct(s, t);
    cout << "O número de subsequências distintas é: " << result << endl;

    return 0;
}
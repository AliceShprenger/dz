#include <iostream>
#include <string>
using namespace std;
void IsKPeriodic(const string &txt, int K)
{
    int N = txt.size();
    if (K <= 0)
        cout << "K <= 0"
             << "\n";
    else if ((N % K != 0) || N == 0)
        cout << "the string is not a multiple of K=" << K
             << "\n";
    else
    {
        string pat = txt.substr(0, K);
        bool T = 0;
        for (int i = 0; i < N; i += K)
        {
            for (int j = 0; j < K; j++)
            {
                if (pat[j] != txt[i + j])
                {
                    cout << "the string is not a multiple of K=" << K
                         << "\n";
                    T = 1;
                    break;
                }
            }
            if (T)
                break;
        }
        if (!T)
            cout << "the string is a multiple of K=" << K
                 << "\n";
    }
}
int main()
{
    string txt;
    int K;
    cin >> txt >> K;
    IsKPeriodic(txt, K);
    return 0;
}
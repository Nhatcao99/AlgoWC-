#include<iostream>
#include<cctype>
using namespace std;
unsigned getNthUglyNo(unsigned long long int n)
{
    unsigned long long int ugly[n]; // To store ugly numbers
    unsigned i2 = 0, i3 = 0, i5 = 0;
    unsigned long long  int next_multiple_of_2 = 2;
    unsigned long long  int next_multiple_of_3 = 3;
    unsigned long long int  next_multiple_of_5 = 5;
    unsigned long long int next_ugly_no = 1;

    ugly[0] = 1;
    for (int i=1; i<n; i++)
    {
        next_ugly_no = min(next_multiple_of_2,
                           min(next_multiple_of_3,
                               next_multiple_of_5));
        ugly[i] = next_ugly_no;
        cout << i << " " << ugly[i] << endl;
        if (next_ugly_no == next_multiple_of_2)
        {
            i2 = i2+1;
            next_multiple_of_2 = ugly[i2]*2;
        }
        if (next_ugly_no == next_multiple_of_3)
        {
            i3 = i3+1;
            next_multiple_of_3 = ugly[i3]*3;
        }
        if (next_ugly_no == next_multiple_of_5)
        {
            i5 = i5+1;
            next_multiple_of_5 = ugly[i5]*5;
        }
    } /*End of for loop (i=1; i<n; i++) */
    return next_ugly_no;
}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    int T, n;
//    scanf("%d",&T);
//    for(int c = 0; c < T; c ++){
//        scanf("%d",&n);
//        cout << getNthUglyNo(n) << endl;
//    }
//    return 0;
    cout << getNthUglyNo(1850) << endl;
}

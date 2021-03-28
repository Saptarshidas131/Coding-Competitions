/*
Input:
3
4
4 2 1 3
2
1 2
7
7 6 5 4 3 2 1

Output:
Case #1: 6
Case #2: 1
Case #3: 12
*/

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int T, N;

    // taking number of test cases as input
    cin>>T;

    // looping for T test cases
    for(int i=0; i<T; i++)
    {
        cin>>N;

        int arr[N];
        for(int j=0; j<N; j++)
        {
            cin>>arr[j];
        }

        int result = 0;
        for(int j=0; j<N-1; j++)
        {
            int min = 128, index = -1;

            for(int k=j; k<N; k++)
            {
                if(arr[k] < min){
                    min = arr[k];
                    index = k;
                }
            }
            reverse(arr+j,arr+index+1);
            result += (index-j)+1;
        }
        cout<<"Case #"<<i+1<<": "<<result<<endl;
    }
}

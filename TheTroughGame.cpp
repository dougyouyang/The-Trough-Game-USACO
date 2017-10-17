//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;
int question[101][21], result[101];

int po(int n)
{
    int a=1, i;
    for(i=0;i<n;i++)
        a*=2;
    return a;
}

int main()
{
    int n, m;
    int power, trough[21], ans[21], cnt=0;
    int i, j, k;
    
    cin >> n >> m;
    for(i=1;i<=m;i++){
        int input;
        cin >> input;
        for(j=n;j>=1;j--)
            question[i][j]=input%2, input/=10;
        cin >> result[i];
    }
    power=po(n);
    
    for(i=0;i<=power;i++){
        if(i==16){
            
        }
        int num=i;
        for(j=n;j>=1;j--)
            trough[j]=num%2, num/=2;
        bool same=true;
        for(j=1;j<=m;j++){
            int counter=0;
            for(k=1;k<=n;k++)
                if(question[j][k] && trough[k])
                    counter++;
            if(counter!=result[j]){
                same=false;
                break;
            }
        }
        if(same){
            for(j=1;j<=n;j++)
                ans[j]=trough[j];
            cnt++;
        }
    }
    
    if(cnt==0)
        cout << "IMPOSSIBLE" << endl;
    else if(cnt>1)
        cout << "NOT UNIQUE" << endl;
    else{
        for(i=1;i<=n;i++)
            cout << ans[i];
        cout << endl;
    }
    
    return 0;
}

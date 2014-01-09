/* Suppose u have a square matrix of 0s and 1s only ... find the longest path of
1s available in the matrix and return that .. you can only move right and 
down ... For e.g.

0 0 0 1 1
1 1 1 0 1
0 1 1 1 0
0 0 1 0 0
1 1 1 1 1
*/

//ideone link :  http://ideone.com/6jHsWk

#include<iostream>
using namespace std;
int main()
{
    int A[5][5] = {{0,0,0,1,1},{1,1,1,0,1},{0,1,1,1,0},{0,0,1,0,0},{1,1,1,1,1}};
    int temp[5][5];
    int end_r(0), end_c(0);
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            temp[i][j] = A[i][j];
            int top(0), left(0), max(0); 
            if(i>0) top = temp[i-1][j];
            if(j>0) left = temp[i][j-1];
            if(top>left) max = top; else max=left;
            if(temp[i][j] && max) {temp[i][j] = ++max, end_r=i; end_c=j;}
            cout<<temp[i][j]<<" ";

        }
        cout<<endl;
    }
    int i = end_r, j = end_c, count=temp[i][j];
    --count;
    while(count){    
    if((temp[i-1][j]) == count) --i; else --j;
    --count;
}

    cout<<"Starting Point"<<" "<<i<<" "<<j<<endl;
    cout<<"Ending Point"<<" "<<end_r<<" "<<end_c<<endl;
    cout<<"Max Length"<<" "<<temp[end_r][end_c];
    return 0;
}

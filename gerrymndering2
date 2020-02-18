#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int FIVE = 4;

#define MAX 21
int N, board[MAX][MAX], ppl[5], ans;
bool visited[MAX][MAX];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};


void select_area(int x, int y, int d1, int d2){
    int i, j;
    memset(ppl, 0, sizeof(ppl));
    memset(visited,0, sizeof(visited));


    for(i=0; i<= d1; ++i){
        visited[x+i][y-1]=true;
        visited[x+d2+i][y+d2-i]=true;
        ppl[FIVE] += board[x+i][y-i] + board[x+d2+i][y+d2-i];
    }
    for(i=1;i<d2;i++){
        visited[x+i][y+i]=true;
        visited[x+d1+i][y-d1+i]=true;
        ppl[FIVE]+=board[x+i][y+i]+board[x+d1+i][y-d1+i];
    }
    for(i=0;i<d1;++i){
        j=0;
        while(!visited[x+i+j+1][y-1]){
            visited[x+i+j+1][y-1]=true;
            ppl[FIVE]+=board[x+i+j+1][y-1];
            ++j;
        }
    }
    for(i=1;i<=N;++i){
        for(j=1;j<=N;++j){
            if(visited[i][j]==true) continue;
            if(i<=x+d1 && j<=y) ppl[0]+=board[i][j];
            else if(i<=x+d2 && y<j) ppl[1]+=board[i][j];
            else if(x+d1<=i && j<y-d1+d2) ppl[2]+=board[i][j];
            else if(x+d2<i && y-d1+d2<=j) ppl[3]+=board[i][j];
        }
    }

    pair<int*, int*> p=minmax_element(ppl, ppl+5);
    ans=min(ans,int(*p.second-*p.first));
}


void divide_area(){

    int x,y,d1,d2;

    
    for(x = 1; x <= N - 2; ++x){
        for(y=2;y<=N-1;++y){
            while(1){
                if(x+d1+d2<=N && y-d1 && y+d2 <=N) select_area(x, y, d1, d2++);
                else{
                    d1++, d2=1;
                    if(!(x+d1+d2<=N && 1<=y-d1 && y+d2<=N)) break;
                }
            }
        }
    }
}

int main(){

    cin>>N;
    register int i, j;
    for(i=1;i<=N;++i){
        for(int j=1;j<=N;++j) cin>>board[i][j];
    }

    ans=987654321;
    divide_area();
    cout<<ans;
    return 0;
}

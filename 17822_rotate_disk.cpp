#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, T, x, d, k, ans, deleted_cnt;

vector<vector<int>> board;

bool adj[51][50];

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

bool is_adjacent(const int &i, const int &j, const int &r){
    int tx, ty;
    if(j==0 && r==2) tx = i, ty = M-1;
    else if(j == M-1 && r == 0) tx=i, ty=0;
    else tx=i+dx[r], ty=j+dy[r];
    if(tx>=1 && ty>=0 && tx<=N && ty<M){
        if(board[tx][ty]==-1) return false;
        if(board[i][j]==board[tx][ty]){
            adj[i][j]=true,adj[tx][ty]=true;
            return true;
        }
    }
    return false;

}

void simulation(){
    
    register int i,j,r,c;
    double sum=0.0;
    bool adjacent;

    //1. rotation
    c=k%M;
    for(i=x;i<=N;i+=x){
        if(d) rotate(board[i].begin(), board[i].begin()+c, board[i].end());
        else rotate(board[i].rbegin(), board[i].rbegin()+c, board[i].rend());
    }

    //2. find adj
    adjacent=false;
    for(i=1;i<=N;++i){
        for(j=0;j<M;++j){
            if(board[i][j]==-1) continue;
            sum+=board[i][j];

            for(r=0;r<4;++r){
                if(is_adjacent(i,j,r)){
                    adjacent=true;
                }
            }
        }
    }
    //3. remove adj
    if(adjacent){
        for(i=1;i<=N;++i){
            for(j=0;j<M;++j){
                if(adj[i][j]){
                    board[i][j]=-1;
                    ++deleted_cnt;

                }
                adj[i][j]=false;
            }
        }
        return;
    }
    if(deleted_cnt==M*N) return;

    //4. no adj
    sum/=(double)(N*M - deleted_cnt);

    for(i=1;i<=N;++i){
        for(j=0;j<M;++j){
            if(board[i][j]==-1) continue;
            if((double) board[i][j]>sum) --board[i][j];
            else if((double)board[i][j]<sum) ++board[i][j];
        }
    }
    }


} 

int main(){
    cin >> N >> M >> T;

	board.resize(N + 1, vector<int>(M));
	register int i, j;
	for (i = 1; i <= N; ++i)
		for (j = 0; j < M; ++j)
			cin >> board[i][j];

	for (i = 0; i < T; ++i)
	{
		cin >> x >> d >> k;
		simulation();
		if (deleted_cnt == M * N) break;
	}
	for (i = 1; i <= N; ++i)
		for (j = 0; j < M; ++j)
			if (board[i][j] != -1)
				ans += board[i][j];

	cout << ans;
	return 0;
    
}

#include<iostream>
#include<vector>
#include<string.h>
#include<string>
#include<algorithm>

using namespace std;

int v[33][2];
int score[33];
vector<int> yoot;
int ans;
int pos[5];
bool checkHorse[33];
bool isChange[33];

void solution(int cur, int total){
    if(cur==10){
        ans=max(ans,total);
        return;
    }

    int trial=yoot[cur];

    for(int i=0;i<4;i++){
        int tmp=trial;
        int position=pos[i];
        int tmp_pos=position;

        if(isChange[position]){
            tmp -=1;
            position = v[position][1];
        }

        while(tmp--) position=v[position][0];

        if(position!=21 && checkHorse[position]) continue;

        pos[i]=position;
        checkHorse[tmp_pos]=false;
        checkHorse[position]=true;
        
        solution(cur+1, total+score[position]);

        checkHorse[position]=false;
        checkHorse[tmp_pos]=true;
        pos[i]=tmp_pos;

    }
    
    

}

int main(){

    for(int i=0;i<=24;i++){
        v[i][0]=i+1;
    }

    //define the next direction

    v[21][0]=21;
    
    v[25][0]=31;
    v[26][0]=25;
    v[27][0]=26;
    v[28][0]=27;
    v[29][0]=30;
    v[30][0]=25;
    v[31][0]=32;
    v[32][0]=20;

    v[5][1]=22;
    v[10][1]=29;
    v[15][1]=28;

    isChange[5]=isChange[10]=isChange[15]=true;

    //setting score

    for(int i=1;i<=20;i++) score[i]=2*i;
    for(int i=22;i<=24;i++) score[i]=13+3*(i-22);
    score[25]=25;

    for(int i=26;i<=28;i++) score[i]=i;

    score[31]=30;
    score[32]=35;
    score[29]=22;
    score[30]=24;

    yoot.resize(10);
    for( int i=0;i<10;i++) cin>>yoot[i];

    solution(0,0);

    cout<<ans<<endl;

    return 0;
}
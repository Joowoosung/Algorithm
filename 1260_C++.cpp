#include<iostream>
using namespace std;
bool t[1001][1001];
bool t_v[1001];//dfs에서 사용할 visit
bool t_vv[1001];//bfs에서 사용할 visit
int que[1001];
int n, m, v;
int Front = 0;
int Rear = 0;
int b;

void dfs(int a){
	t_v[a]=true;
	cout << a << " ";
	for (int i = 1; i <= 1000; i++){
		if (t_v[i] == false && t[a][i] == true){
			dfs(i);
		}
	}
}


void bfs(int a){
	
	t_vv[a] = true;
	que[Rear] = a;
	Rear++;

	while (Front != Rear){
		b=que[Front];
		Front++;
		cout << b << " ";
		for (int i = 1; i <=1000 ; i++){
			if (t_vv[i] == false && t[b][i]==true){
				que[Rear] = i;
				Rear++;
				t_vv[i] = true;
			}
		}
	}
}

int main(){
	
	cin >> n >> m >> v;
	int a, b;
	for (int i = 0; i <m ; i++){
		cin >> a >> b;
		t[a][b] = t[b][a] = true;
	}

	dfs(v);
	cout << endl;

	bfs(v);
	cout << endl;

}
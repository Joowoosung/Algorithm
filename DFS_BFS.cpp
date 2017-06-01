#include <stdio.h>
 
int n; // 정점의 총 갯수
int rear, front;
int map[30][30], visit[30], queue[30]; // 인접 행렬과 방문 여부를 나타내는 배열
 
void DFS(int v)
{
    int i;
 
    visit[v] = 1; // 정점 v를 방문했다고 표시
    for (i = 1; i <= n; i++)
    {
        // 정점 v와 정점 i가 연결되었고, 정점 i를 방문하지 않았다면
        if (map[v][i] == 1 && !visit[i])
        {
            printf("%d에서 %d로 이동\n", v, i);
            // 정점 i에서 다시 DFS를 시작한다
            DFS(i);
        }
    }
}

void BFS(int v)
{
    int i;
 
    visit[v] = 1; // 정점 v를 방문했다고 표시
    printf("%d에서 시작\n", v);
    queue[rear++] = v; // 큐에 v를 삽입하고 후단을 1 증가시킴
    while (front < rear) // 후단이 전단과 같거나 작으면 루프 탈출
    {
        // 큐의 첫번째에 있는 데이터를 제외하고 제외된 값을 가져오며, 전단 1 증가
        v = queue[front++];
        for (i = 1; i <= n; i++)
        {
            // 정점 v와 정점 i가 만나고, 정점 i를 방문하지 않은 상태일 경우
            if (map[v][i] == 1 && !visit[i])
            {
                visit[i] = 1; // 정점 i를 방문했다고 표시
                printf("%d에서 %d로 이동\n", v, i);
                queue[rear++] = i; // 큐에 i를 삽입하고 후단을 1 증가시킴
            }
        }
    }
}

 
int main()
{
    int start; // 시작 정점
    int v1, v2;
 
    scanf("%d%d", &n, &start);
 
    while (1)
    {
        scanf("%d%d", &v1, &v2);
        if (v1 == -1 && v2 == -1) break; // -1과 -1이 입력되면 무한 루프 탈출
        map[v1][v2] = map[v2][v1] = 1; // 정점 v1과 정점 v2가 연결되었다고 표시
    }
    BFS(start); // DFS 시작!
 
    return 0;
}

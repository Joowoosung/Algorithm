#include <stdio.h>
 
int n; // ������ �� ����
int rear, front;
int map[30][30], visit[30], queue[30]; // ���� ��İ� �湮 ���θ� ��Ÿ���� �迭
 
void DFS(int v)
{
    int i;
 
    visit[v] = 1; // ���� v�� �湮�ߴٰ� ǥ��
    for (i = 1; i <= n; i++)
    {
        // ���� v�� ���� i�� ����Ǿ���, ���� i�� �湮���� �ʾҴٸ�
        if (map[v][i] == 1 && !visit[i])
        {
            printf("%d���� %d�� �̵�\n", v, i);
            // ���� i���� �ٽ� DFS�� �����Ѵ�
            DFS(i);
        }
    }
}

void BFS(int v)
{
    int i;
 
    visit[v] = 1; // ���� v�� �湮�ߴٰ� ǥ��
    printf("%d���� ����\n", v);
    queue[rear++] = v; // ť�� v�� �����ϰ� �Ĵ��� 1 ������Ŵ
    while (front < rear) // �Ĵ��� ���ܰ� ���ų� ������ ���� Ż��
    {
        // ť�� ù��°�� �ִ� �����͸� �����ϰ� ���ܵ� ���� ��������, ���� 1 ����
        v = queue[front++];
        for (i = 1; i <= n; i++)
        {
            // ���� v�� ���� i�� ������, ���� i�� �湮���� ���� ������ ���
            if (map[v][i] == 1 && !visit[i])
            {
                visit[i] = 1; // ���� i�� �湮�ߴٰ� ǥ��
                printf("%d���� %d�� �̵�\n", v, i);
                queue[rear++] = i; // ť�� i�� �����ϰ� �Ĵ��� 1 ������Ŵ
            }
        }
    }
}

 
int main()
{
    int start; // ���� ����
    int v1, v2;
 
    scanf("%d%d", &n, &start);
 
    while (1)
    {
        scanf("%d%d", &v1, &v2);
        if (v1 == -1 && v2 == -1) break; // -1�� -1�� �ԷµǸ� ���� ���� Ż��
        map[v1][v2] = map[v2][v1] = 1; // ���� v1�� ���� v2�� ����Ǿ��ٰ� ǥ��
    }
    BFS(start); // DFS ����!
 
    return 0;
}

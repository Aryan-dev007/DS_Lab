#include<stdio.h>
#include<conio.h>
#define MAX 10

int a[MAX][MAX], visited1[MAX], visited2[MAX];
int n, source; //no of vertices  and source

void create() {
	int i,j;
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	printf("Enter adjacency Matrix\n");
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
}

void bfs() {
	int q[10], u, front=0, rear=-1, i;
	for (i = 0; i < n; i++) visited1[i] = 0;
	printf("Enter source vertex: ");
	scanf("%d", &source);
	q[++rear] = source;
	visited1[source] = 1;
	printf("Reachable vertices are: \n");
	while (front <= rear) {
		u = q[front++];
		for (i = 1; i <= n; i++) {
			if (a[u][i] == 1 && visited1[i] == 0) {
				q[++rear] = i;
				visited1[i] = 1;
				printf("%d\t", i);
			}
		}
	}
	printf("\n");
}

void dfs(int source) {
	int i;
	visited2[source] = 1;
	for (i = 1; i <= n; i++) {
		if (a[source][i] == 1 && visited2[i] == 0) {
			printf("%d -> %d\t", source, i);
			dfs(i);
		}
	}
}

int main(void) {
	int ch, i, m;
	clrscr();
	while (1) {
		printf("1.Create\n2.BFS\n3.DFS and Connectivity\n4.Exit\nChoice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
					create(); break;
			case 2:
					bfs();
					for (i = 1; i <= n; i++)
						if (visited1[i] == 0)
							printf("Vertex is not reachable! %d", i);
					break;
			case 3:
					printf("Enter source vertex: ");
					scanf("%d", &source);
					for (i=1; i<=n; i++) visited2[i] = 0;
					m = 1;
					dfs(source);
					for (i = 1; i <= n; i++) {
						if (visited2[i] == 0) m = 0;
					}
					if (m == 1)
						printf("Connected Graph\n");
					else
						printf("Disconnected Graph\n");
					break;
			default: return 0;
		}

	}
}

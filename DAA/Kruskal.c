// correction
#include <stdio.h>

struct Edge {
	int src, dest, weight;
};

int adj[100][100], n, e;
struct Edge edges[100], mst[100];

void sortEdges() {
	for (int i = 0; i < e - 1; i++) {
		for (int j = 0; j < e - i - 1; j++) {
			if (edges[j].weight > edges[j + 1].weight) {
				struct Edge temp = edges[j];
				edges[j] = edges[j + 1];
				edges[j + 1] = temp;
			}
		}
	}
}

int findSet(int parent[], int i) {
	if (parent[i] == -1) {
		return i;
	}
	return findSet(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
	int xset = findSet(parent, x);
	int yset = findSet(parent, y);
	parent[xset] = yset;
}

void kruskal() {
	int parent[n];
	for (int i = 0; i < n; i++) {
		parent[i] = -1;
	}
	int mstIndex = 0;
	for (int i = 0; i < e; i++) {
		int x = findSet(parent, edges[i].src);
		int y = findSet(parent, edges[i].dest);
		if (x != y) {
			mst[mstIndex++] = edges[i];
			Union(parent, x, y);
		}
	}
	printf("Minimum Spanning Tree:\n");
	for (int i = 0; i < n - 1; i++) 
    {
		printf("%c -> %c: %d\n", 'a' + mst[i].src, 'a' + mst[i].dest, mst[i].weight);
	}
}

int main() {
	n = 9; // Number of vertices
	// Hardcoded adjacency matrix
	int adj[9][9] = {
		{0, 4, 0, 0, 0, 0, 0, 8, 0},
		{4, 0, 8, 0, 0, 0, 0, 11, 0},
		{0, 8, 0, 7, 0, 4, 0, 0, 2},
		{0, 0, 7, 0, 9, 14, 0, 0, 0},
		{0, 0, 0, 9, 0, 10, 0, 0, 0},
		{0, 0, 4, 14, 10, 0, 2, 0, 0},
		{0, 0, 0, 0, 0, 2, 0, 1, 6},
		{8, 11, 0, 0, 0, 0, 1, 0, 7},
		{0, 0, 2, 0, 0, 0, 6, 7, 0}
	};
	e = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (adj[i][j] != 0) {
				edges[e].src = i;
				edges[e].dest = j;
				edges[e].weight = adj[i][j];
				e++;
			}
		}
	}
	sortEdges();
	kruskal();
	return 0;
}

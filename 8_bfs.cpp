#include <bits/stdc++.h> 
using namespace std; 
#define N 3

struct Node {
	Node* parent; 
	int mat[N][N]; 
	int x, y;
	int level;
}; 

int cetakMatrix(int mat[N][N]) { 
	for (int i = 0; i < N; i++) 
	{ 
		for (int j = 0; j < N; j++)
		{
			
			printf("%d ", mat[i][j]); 
		}
		printf("\n");
		
	}
	printf("------\n");
} 

Node* newNode(int mat[N][N], int x, int y, int newX, int newY, int level, Node* parent) { 
	Node* node = new Node; 
	node->parent = parent; 

	memcpy(node->mat, mat, sizeof node->mat); 

	swap(node->mat[x][y], node->mat[newX][newY]); 

	node->level = level; 

	node->x = newX; 
	node->y = newY; 

	return node; 
} 

int main() { 
	int initial[N][N] = { 
		{1, 2, 3}, 
		{5, 7, 6}, 
		{4, 8, 0} 
	}; 

	int final[N][N] = { 
		{1, 2, 3}, 
		{5, 8, 6}, 
		{0, 7, 4} 
	}; 
	cetakMatrix(initial);
	cetakMatrix(final);

	return 0; 
} 

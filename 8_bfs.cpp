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

int row[] = { 1, 0, -1, 0 }; 
int col[] = { 0, -1, 0, 1 }; 

int isSafe(int x, int y) { 
	return (x >= 0 && x < N && y >= 0 && y < N); 
} 

void cetakPath(Node* root) { 
	if (root == NULL) 
		return; 
	cetakPath(root->parent);
	cetakMatrix(root->mat); 

	printf("\n"); 
} 

bool cekgoal (int mat[N][N],int final [N] [N]) {
 	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) 
			if (mat [i] [j] != final [i] [j]) 
			return false;
	}
	 
 	return true;
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

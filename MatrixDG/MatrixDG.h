#pragma once
#include <stdint.h>

#define MAX 100
class MatrixDG
{
public:
	// 创建图
	MatrixDG();
	// 提供数据创建图
	MatrixDG(char vexs[], int vlen, char edges[][2], int elen);
	~MatrixDG();

	// 深度优先搜索
	void DFS();
	// 广度优先搜索
	void BFS();
	// 打印矩阵队列图
	void print();

private:
	// 读取一个字符
	char readChar();
	// 返回ch在matrix中的位置
	int getPosition(char ch);
	// 返回顶点v的第一个邻接顶点的索引，失败则返回-1
	int firstVertex(int v);
	// 返回顶点v相对于w的下一个邻接顶点的索引，失败则返回-1
	int nextVertex(int v, int w);
	// 深度优先搜索遍历图的递归实现
	void DFS(int i, int *visited);

private:
	char mVexs[MAX];
	int mVexNum; 
	int mEdgeNum;
	int mMatrix[MAX][MAX] = {0};
};

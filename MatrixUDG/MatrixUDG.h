#pragma once

// 变得结构体
class EData
{
public:
	char start;   // 边的起点
	char end;     // 边的终点
	int  weight;  // 边的权重

public:
	EData() {}
	EData(char s, char e, int w) : start(s), end(e), weight(w) {}
};

const int MAX = 100;
const int INF = 0x7FFFFFFF;
class MatrixUDG {
public:
	// create graph according with input data
	MatrixUDG();
	// create graph according with supplied data
	MatrixUDG(char vexs[], int vlen, char edges[][2], int elen);
	~MatrixUDG();

	// dfs 
	void DFS();
	// bfs
	void BFS();
	// prim算法，获取最小生成树
	void prim(int start);
	// kruskal算法，获取最小生成树
	void kruskal();
	// print 
	void print();

private:
	// 读取一个输入字符
	char readChar();
	// 返回ch在mMatrix矩阵中的位置
	int getPosition(char ch);
	// 返回定点v的第一个邻接顶点的索引，失败返回-1
	int firstVertex(int v);
	// 返回顶点v相对于w的下一个邻接点的索引，失败返回-1
	int nextVertex(int v, int w);
	// 深度优先搜索遍历图的递归实现
	void DFS(int i, int* visited);
	// 获取图中的边
	EData* getEdges();
	void sortEdges(EData*, int elen);
	void sortEdges2(EData*, int elen);
	int getEnd(int vends[], int i);

private:
	char mVexs[MAX];	   // 顶点集合
	int mVexNum;		   // 顶点数
	int mEdgNum;		   // 边数
	int mMatrix[MAX][MAX]; // 邻接矩阵
};


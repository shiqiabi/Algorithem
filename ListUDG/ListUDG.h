#pragma once

#define MAX 100
// 邻接表
class ListUDG
{
public:
	ListUDG(char vexs[], int vlen, char edges[][2], int elen);
	~ListUDG();

	// 深度优先搜索
	void DFS();
	// 广度优先搜索
	void BFS();
	// 打印邻接表
	void print();

private:
	// 邻接表中对应的链表的节点
	class ENode
	{
	public:
		int ivex;
		ENode* nextEdge;
	};

	class VNode
	{
	public:
		char data; // 顶点信息
		ENode *firstEdge; // 指向第一条依附于该定点的边
	};

	// 返回ch的位置
	int getPosition(char ch);
	// 深度优先搜索便利图的递归实现
	void DFS(int i, int *visited);
	// 将node节点链接到list的最后
	void linkLast(ENode* list, ENode* node);

private:
	int mVexNum;
	int mEdgeNum;
	VNode mVexs[MAX];
};


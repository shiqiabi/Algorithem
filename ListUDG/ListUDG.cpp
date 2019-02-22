#include "ListUDG.h"
#include <iostream>
#include <queue>
using namespace std;

ListUDG::ListUDG(char vexs[], int vlen, char edges[][2], int elen)
{
	// read node 
	int i;
	for (i = 0; i < vlen; i++)
	{
		mVexs[i].data = vexs[i];
		mVexs[i].firstEdge = nullptr;
	}
	mVexNum = vlen;

	// read edges
	for (i = 0; i < elen; i++)
	{
		int index1 = getPosition(edges[i][0]);
		int index2 = getPosition(edges[i][1]);
		
		ENode *enode2 = new ENode();
		enode2->ivex = index2;
		enode2->nextEdge = nullptr;
		
		if (mVexs[index1].firstEdge == nullptr)
		{
			mVexs[index1].firstEdge = enode2;
		}
		else
		{
			linkLast(mVexs[index1].firstEdge, enode2);
		}

		ENode *enode1 = new ENode();
		enode1->ivex = index1;
		enode1->nextEdge = nullptr;
		if (mVexs[index2].firstEdge == nullptr)
		{
			mVexs[index2].firstEdge = enode1;
		}
		else
		{
			linkLast(mVexs[index2].firstEdge, enode1);
		}
	}
	mEdgeNum = elen;
}

// 深度优先搜索
void ListUDG::DFS()
{
	int visited[MAX] = { 0 };
	for(int i=0; i < mVexNum; i++)
	{		
		DFS(i, visited);	
	}
}

// 广度优先搜索
void ListUDG::BFS()
{
	std::queue<int> nodequeue;
	bool visited[MAX] = { false };
	for (int index = 0; index < mVexNum; index++)
	{
		if (!visited[index])
		{
			nodequeue.push(index);
			while (!nodequeue.empty())
			{
				int front = nodequeue.front();
				visited[front] = true;
				cout << mVexs[front].data << " ";
				ENode* node = mVexs[front].firstEdge;
				while (node)
				{
					if (!visited[node->ivex])
					{
						nodequeue.push(node->ivex);
					}
					node = node->nextEdge;
				}
			}
		}
	}
}

// 打印邻接表
void ListUDG::print()
{

}

// 返回ch的位置
int ListUDG::getPosition(char ch)
{
	for (int i = 0; i < mVexNum; i++)
	{
		if (mVexs[i].data == ch)
			return i;
	}
	return -1;
}

// 深度优先搜索便利图的递归实现
void ListUDG::DFS(int i, int *visited)
{
	if (visited[i] == 0)
	{
		cout << mVexs[i].data << " ";
		ENode* edge = mVexs[i].firstEdge;
		while (edge != nullptr)
		{
			if (visited[edge->ivex] == 0)
			{
				visited[edge->ivex] = 1;
				DFS(edge->ivex, visited);
			}
			else
			{
				edge = edge->nextEdge;
			}
		}
	}	
}

// 将node节点链接到list的最后
void ListUDG::linkLast(ENode* list, ENode* node)
{
	while (list->nextEdge)
	{
		list = list->nextEdge;
	}
	list->nextEdge = node;
}
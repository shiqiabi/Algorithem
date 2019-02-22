#include "MatrixDG.h"

#include <iostream>
#include <queue>
using namespace std;

//MatrixDG 和 MatrixUDG 对于深度搜索和广度搜索而言算法的没有什么区别。
//他们的区别在于构造Matrix矩阵的时候。
MatrixDG::MatrixDG()
{
	char c1, c2;
	int i, p1, p2;
	// 输入“顶点数”和“边数”
	cout << "input vertex number: ";
	cin >> mVexNum;
	cout << "input edge number: ";
	cin >> mEdgeNum;
	if (mVexNum < 1 || mEdgeNum < 1 || mEdgeNum >(mVexNum*(mVexNum - 1)) / 2)
	{
		cout << "invalid input parameters!!!" << endl;
		return;
	}

	// 初始化顶点
	for (i = 0; i < mVexNum; i++)
	{
		cout << "vertex(" << i << "): ";
		mVexs[i] = readChar();
	}

	// 初始化“边”
	for (int i = 0; i < mEdgeNum; i++)
	{
		// 读取边的顶点
		cout << "edge(" << i << "): ";
		c1 = readChar();
		c2 = readChar();

		p1 = getPosition(c1);
		p2 = getPosition(c2);
		if (p1 == -1 || p2 == -1)
		{
			cout << "input error: invalid edge!" << endl;
			return;
		}

		mMatrix[p1][p2] = 1;
	}
}

/*
* 创建图(用已提供的矩阵)
*/

MatrixDG::MatrixDG(char vexs[], int vlen, char edges[][2], int elen)
{
	int i, p1, p2;
	// 初始化“顶点数"和“边数”
	mVexNum = vlen;
	mEdgeNum = elen;
	// 初始化“顶点"
	for (int i = 0; i < mEdgeNum; i++)
	{
		mVexs[i] = vexs[i];
	}
	// 初始化“边”
	for (i = 0; i < mEdgeNum; i++)
	{
		p1 = getPosition(edges[i][0]);
		p2 = getPosition(edges[i][1]);
		mMatrix[p1][p2] = 1;
	}
}

/*
析构函数
*/

MatrixDG::~MatrixDG()
{

}

/*
获取ch在mMatrix中的位置
*/
int MatrixDG::getPosition(char ch)
{
	int i;
	for (i = 0; i < mVexNum; i++)
	{
		if (mVexs[i] == ch)
		{
			return i;
		}
	}
	return -1;
}

/*
读取一个字符
*/
char MatrixDG::readChar()
{
	char ch;
	do
	{
		cin >> ch;
	} while (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')));
	return ch;
}

/*
返回顶点v的第一个邻接顶点的索引，失败则返回-1
*/
int MatrixDG::firstVertex(int v)
{
	int i;
	if (v < 0 || v >= mVexNum)
		return -1;

	for (i = 0; i < mVexNum; i++)
	{
		if (mMatrix[v][i] == 1)
			return i;
	}

	return -1;
}

/*
返回顶点v相对于w的下一个邻接顶点的索引，失败返回-1
*/
int MatrixDG::nextVertex(int v, int w)
{
	if ((v < 0 || v >= mVexNum) || (w < 0 || w >= mVexNum))
	{
		return -1;
	}

	int i;
	for (i = w + 1; i < mVexNum; i++)
	{
		if (mMatrix[v][i] == 1)
			return i;
	}
	return -1;
}

// dfs 
void MatrixDG::DFS()
{
	int i;
	int visited[MAX];
	// 初始化所有顶点都没有被访问
	for (i = 0; i < mVexNum; i++)
	{
		visited[i] = 0;
	}

	// 图有可能是不连通的。从一个顶点出发经过深度优先搜索，不能遍历完所有的顶点
	for (i = 0; i < mVexNum; i++)
	{
		if (!visited[i])
			DFS(i, visited);
	}
}

// bfs
void MatrixDG::BFS()
{
	// 初始化所有的顶点都没有被访问
	int visited[MAX] = { 0 };
	int i;
	std::queue<int> nodequeue;
	// 遍历所有的节点
	for (i = 0; i < mVexNum; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			cout << mVexs[i] << " ";
			// 入队
			nodequeue.push(i);
			while (!nodequeue.empty())
			{
				// 获取头节点和出队
				int index = nodequeue.front();
				nodequeue.pop();
				int w;
				// 遍历所有的邻接节点
				for (w = firstVertex(index); w >= 0; w = nextVertex(index, w))
				{
					if (!visited[w])
					{
						visited[w] = true;
						cout << mVexs[w] << " ";
						nodequeue.push(w);
					}
				}
			}
		}
	}
}

// print the hole matrix
void MatrixDG::print()
{
	int i, j;
	cout << "Matrix Graph:" << endl;
	for (i = 0; i < mVexNum; i++)
	{
		for (j = 0; j < mVexNum; j++)
		{
			cout << mMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

/*
深度优先搜索遍历图的递归实现.
*/
void MatrixDG::DFS(int i, int* visited)
{
	int w;
	visited[i] = 1;
	cout << mVexs[i] << " ";
	// 遍历该顶点的所有邻接顶点。若是没有访问过，那么继续往下走
	for (w = firstVertex(i); w >= 0; w = nextVertex(i, w))
	{
		if (!visited)
			DFS(w, visited);
	}
}
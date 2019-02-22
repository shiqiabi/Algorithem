#include "MatrixUDG.h"

#include <iostream>
#include <queue>
using namespace std;

MatrixUDG::MatrixUDG()
{
	char c1, c2;
	int i, p1, p2;
	// 输入“顶点数”和“边数”
	cout << "input vertex number: ";
	cin >> mVexNum;
	cout << "input edge number: ";
	cin >> mEdgNum;
	if (mVexNum < 1 || mEdgNum < 1 || mEdgNum >(mVexNum*(mVexNum - 1)) / 2)
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
	for (int i = 0; i < mEdgNum; i++)
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
		mMatrix[p2][p1] = 1;
	}
}

/*
 * 创建图(用已提供的矩阵)
 */

MatrixUDG::MatrixUDG(char vexs[], int vlen, char edges[][2], int elen)
{
	int i, p1, p2;
	// 初始化“顶点数"和“边数”
	mVexNum = vlen;
	mEdgNum = elen;
	// 初始化“顶点"
	for (int i = 0; i < mEdgNum; i++)
	{
		mVexs[i] = vexs[i];
	}
	// 初始化“边”
	for (i = 0; i < mEdgNum; i++)
	{
		p1 = getPosition(edges[i][0]);
		p2 = getPosition(edges[i][1]);
		mMatrix[p1][p2] = 1;
		mMatrix[p2][p1] = 1;
	}
}

/*
析构函数
*/

MatrixUDG::~MatrixUDG()
{

}

/*
获取ch在mMatrix中的位置
*/
int MatrixUDG::getPosition(char ch)
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
char MatrixUDG::readChar()
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
int MatrixUDG::firstVertex(int v)
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
int MatrixUDG::nextVertex(int v, int w)
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
void MatrixUDG::DFS()
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
void MatrixUDG::BFS()
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
void MatrixUDG::print()
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
void MatrixUDG::DFS(int i, int* visited)
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

/*
prim最小生成树。该算法的时间复杂度是O(N*N)
start: 从图中的第start个元素开始，生成最小树
*/
void MatrixUDG::prim(int start)
{
	int index = 0;     // prim最小树的索引，即prims数组的索引
	char prims[MAX];   // prim最小树的结果数组
	int weights[MAX];  // 顶点间边的权值

	// prim最小生成树中第一个点是“图中第start个顶点",因为是从start开始的。
	prims[index++] = mVexs[start];

	// 初始化”顶点的权值数组“，将每个顶点的权值初始化为"第start个顶点"到”该顶点“的权值
	int i;
	for (i = 0; i < mVexNum; i++)
	{
		weights[i] = mMatrix[start][i];
	}
	// 将第start个顶点的权值初始化为0.可以理解为到自身的距离为0
	weights[i] = 0;
	
	// 每一次循环从未进入最小生成输的点中找到权值最小的顶点加入最小生成树中，然后更新最小生成树的边
	for (i = 0; i < mVexNum; i++)
	{
		// 忽略start
		if (i == start) continue;
		int j, k = 0, min = INF;
		// 在未被加入到最小生成树的顶点中，找出权值最小的顶点。
		while (j < mVexNum)
		{
			// 若weights[j] = 0, 意味着“第j个节点已经被排序过”(或者说已经加入到了最小生成树中).
			if (weights[j] != 0 && weights[j] < min)
			{
				min = weights[j];
				k = j;
			}
			j++;
		}

		// 经过上面的处理后，在未被加入到最小生成树的顶点中，权值最小的顶点是第k个顶点。将第k个顶点加入到最小生成树的结果数组中。
		prims[index++] = mVexs[k];
		// 将"第k个顶点的权值"标记为0,意味着"第k个顶点已经排序过了"(或者说已经加入到了最小树结果中).
		weights[k] = 0;
		// 当第k个顶点被加入到最小生成树的结果数组中之后，更新其他顶点的权值
		for (j = 0; j < mVexNum; j++)
		{
			// 当第j个节点没有被处理，并且需要更新时才更新
			if (weights[j] != 0 && mMatrix[k][j] < weights[j])
			{
				weights[j] = mMatrix[k][j];
			}
		}
	}

	// 计算最小生成树的权值，因为在上一步中已经将weights数组中的权值都赋值为0了。所以需要重新寻找。
	int sum = 0;
	// 因为其实点是prims[0],所以从1开始
	for (i = 1; i < index; i++)
	{
		int min = INF;
		// 获取prims[i]在mMatrix中的位置
		int n = getPosition(prims[i]);
		// 在vexs[0...i-1]中，找出到i的权值最小的顶点
		for (int j = 0; j < i; j++)
		{
			int m = getPosition(prims[j]);
			if (mMatrix[m][n] < min)
			{
				min = mMatrix[m][n];
			}
		}
		sum += min;
	}

	// 打印最小
	cout << "PRIM(" << mVexs[start] << ")=" << sum << ":";
	for (i = 0; i < index; i++)
	{
		cout << prims[i] << " ";
	}
	cout << endl;
}

EData* MatrixUDG::getEdges()
{
	int index = 0;
	EData* edges = new EData[mEdgNum];
	for (int i = 0; i < mVexNum; i++)
	{
		for (int j = i + 1; j < mVexNum; j++, index++)
		{
			if (mMatrix[i][j] != INF)
			{
				edges[index].start = mVexs[i];
				edges[index].end = mVexs[j];
				edges[index].weight = mMatrix[i][j];
			}
		}
	}
	return edges;
}

// 选择排序，这个不能向冒泡排序那样进行优化
void MatrixUDG::sortEdges(EData* edges, int elen)
{
	for (int i = 0; i < elen; i++)
	{
		for (int j = i + 1; j < elen; j++)
		{
			if (edges[i].weight > edges[j].weight)
			{
				std::swap(edges[i], edges[j]);
			}
		}
	}
}

// 冒泡排序, 冒泡排序可以优化
void MatrixUDG::sortEdges2(EData *edges, int elen)
{
	bool swapped = false;
	for (int i = 0; i < elen; i++)
	{		
		for (int j = 0; j < elen - i - 1; j++)
		{
			if (edges[j].weight > edges[j + 1].weight)
			{
				std::swap(edges[j], edges[j + 1]);				
			}
		}
		if (!swapped) break;
	}
}

int MatrixUDG::getEnd(int vends[], int i)
{
	while (vends[i] != 0)
	{
		i = vends[i];
	}
	return i;
}

/*
克鲁斯卡尔算法生成最小生成树
*/
void MatrixUDG::kruskal()
{
	int index = 0;
	EData rets[MAX];
	// 获取图中所有的边, 先以mVex[0]作为起点，依次为mVex[1],mVex[2]作为起点获取边
	EData* edges = getEdges();
	// 将边按照"权"的大小进行排序(从小到大)
	sortEdges(edges, mEdgNum);
	int vends[MAX] = { 0 };                       // 用于保存”已有最小生成树“中每个顶点在该最小生成树中的终点
	int i;
	for (i = 0; i < mEdgNum; i++)
	{
		int p1 = getPosition(edges[i].start);     // 获取第i条边的”起点“的序号
		int p2 = getPosition(edges[i].end);       // 获取第i条边的”终点“的序号
		int m = getEnd(vends, p1);                // 获取p1在最小生成树的终点
		int n = getEnd(vends, p2);                // 获取p2在最小生成树的终点
		if (m != n)
		{
			vends[m] = n;
			rets[index++] = edges[i];
		}
	}

	delete[] edges;

	// 统计并打印"krushkal最小生成树”的信息
	int length = 0;
	for (i = 0; i < index; i++)
	{
		length += rets[i].weight;
	}
	cout << "Kruskal=" << length << ":";
	for (i = 0; i < index; i++)
	{
		cout << "(" << rets[i].start << "," << rets[i].end << ")";
	}
	cout << endl;
}
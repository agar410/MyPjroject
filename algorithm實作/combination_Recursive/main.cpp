#include <iostream>

using namespace std;


void dfs(int pos, int cnt, int n, int k, int a[],bool visited[]) {
    //已標記了k個數，輸出結果
    if (cnt == k) {
        for (int i = 0; i < n; i++)
            if (visited[i]) cout << a[i] << ' ';
        cout << endl;
        return;
    }

    //處理到最後一個數，直接返回
    if (pos == n) return;

    //如果a[pos]沒有被選中
    if (!visited[pos]) {
        //選中a[pos]
        visited[pos] = true;
        //處理在子串a[pos+1, n-1]中取出k-1個數的子問題
        dfs(pos + 1, cnt + 1, n, k, a,visited);
        //回溯
        visited[pos] = false;
    }
    //處理在子串a[pos+1, n-1]中取出k個數的問題
    dfs(pos + 1, cnt, n, k, a, visited);
}

int main()
{
    int i,n,k;
    n=5,k=3;
    int *a = new int[n];
    bool *visited = new bool[n];
        for (i = 0; i < n; i++)
        {
            a[i] = i + 1;
            visited[i] = false;
        }
        dfs(0, 0, n, k, a, visited);
        delete[] a;
        delete[] visited;
    cout << "Hello world!" << endl;
    return 0;
}

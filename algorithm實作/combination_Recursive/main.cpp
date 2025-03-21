#include <iostream>

using namespace std;


void dfs(int pos, int cnt, int n, int k, int a[],bool visited[]) {
    //�w�аO�Fk�ӼơA��X���G
    if (cnt == k) {
        for (int i = 0; i < n; i++)
            if (visited[i]) cout << a[i] << ' ';
        cout << endl;
        return;
    }

    //�B�z��̫�@�ӼơA������^
    if (pos == n) return;

    //�p�Ga[pos]�S���Q�襤
    if (!visited[pos]) {
        //�襤a[pos]
        visited[pos] = true;
        //�B�z�b�l��a[pos+1, n-1]�����Xk-1�Ӽƪ��l���D
        dfs(pos + 1, cnt + 1, n, k, a,visited);
        //�^��
        visited[pos] = false;
    }
    //�B�z�b�l��a[pos+1, n-1]�����Xk�Ӽƪ����D
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

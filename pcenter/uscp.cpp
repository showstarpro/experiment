#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <utility>

using namespace std;
LARGE_INTEGER t1, t2;
vector<vector<int>> V;

void findpair(vector<int> &X, vector<int> &delt, vector<int> &UX, vector<int> &flag, vector<int> &W, int &f, int N, int &I, int &J);
void makemove(vector<int> &X, vector<int> &delt, vector<int> &UX, vector<int> &flag, vector<int> &W, int N, int I, int J, int &f);
void makemove1(vector<int> &X, vector<int> &deltt, vector<int> &UX, vector<int> &flag, vector<int> &W, int N, int I, int J);

int main(int argc, char **argv)
{
    if (argc != 5)
        cout << "please input: xxx.exe inputfile outputfile timelimit seed" << endl;
    FILE *fp;
    if ((fp = freopen(argv[1], "rb", stdin)) == NULL)
    {
        printf("打开文件失败");
        return -1;
    }
    srand(atoi(argv[4]));
    QueryPerformanceCounter(&t1);

    int N, P, cnt = 0, n, tmp;
    scanf("%d%d", &N, &P);
    vector<int> X(P, 0);
    vector<int> Xbest(P, 0);
    vector<int> flag(N, 0);
    vector<int> delt(N, 0);

    V.resize(N);

    for (int i = 0; i < 2 * N; i++)
    {
        if (i % 2 == 0)
        {
            scanf("%d", &n);
            V[i / 2].reserve(n);
        }
        else if (i % 2)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &tmp);
                V[i / 2].push_back(tmp);
            }
        }
    }

    fclose(fp);

    //init X=>greedy algorithm
    for (int i = 0; i < P; i++)
    {
        int bestcnt = 0, besti;
        for (int k = 0; k < N; k++)
        {
            //calc uncovered
            cnt = 0;
            for (int j = 0; j < V[k].size(); j++)
            {
                if (flag[V[k][j]] == 0)
                    cnt++;
            }
            if (cnt > bestcnt)
            {
                bestcnt = cnt;
                besti = k;
            }
        }
        X[i] = besti;
        //update flag
        for (int k = 0; k < V[besti].size(); k++)
        {
            if (flag[V[besti][k]] > 0)
                flag[V[besti][k]] = -1;
            else if (flag[V[besti][k]] == 0)
                flag[V[besti][k]] = besti + 1;
        }
    }
    vector<int> UX;
    UX.reserve(N);

    vector<int> W(N, 1);
    for (int i = 0; i < N; i++)
    {
        if (flag[i] == 0)
        {
            UX.push_back(i);
            for (int k = 0; k < V[i].size(); k++)
                delt[V[i][k]]++;
        }
        else if (flag[i] > 0) //flag[i]=center
        {
            delt[flag[i] - 1]++;
        }
    }
    int f = UX.size();

    int I = -1, J = -1, iter = 0, bestsize = f, lastsize = f;

    if (f != 0)

        while (1)
        {

            findpair(X, delt, UX, flag, W, f, N, I, J);
            makemove(X, delt, UX, flag, W, N, I, J, f);
            if (UX.size() < bestsize)
            {
                Xbest.assign(X.begin(), X.end());
                bestsize = UX.size();
            }
            else if (UX.size() >= lastsize)
            {
                for (int i = 0; i < UX.size(); i++)
                {
                    W[UX[i]]++;
                }
            }
            if (bestsize == 0)
            {
                QueryPerformanceCounter(&t2);
                cout<<((double)(t2.QuadPart - t1.QuadPart) / 1e7) <<endl;
                break;
            }
            
            if ((double)(t2.QuadPart - t1.QuadPart) / 1e7 > atoi(argv[3]))
            {
                cout << "超时:" << ((double)(t2.QuadPart - t1.QuadPart) / 1e7) <<endl;
                break;
            }
            iter++;
            lastsize = UX.size();
        }
    if ((fp = freopen(argv[2], "wb", stdout)) == NULL)
    {
        printf("打开文件失败");
        return -1;
    }
    for (int i = 0;i<X.size(); i++)
    {
        printf("%d ", X[i]);
    }
    return 0;
}

void findpair(vector<int> &X, vector<int> &delt, vector<int> &UX, vector<int> &flag, vector<int> &W, int &f, int N, int &I, int &J)
{
    int v = UX[rand() % UX.size()];
    vector<int> deltlast(N, 0);
    deltlast.assign(delt.begin(), delt.end());
    int fbest = 1e8; //find best in i,j
    vector<pair<int, int>> M;
    // int cnt = 0;
    for (int i = 0; i < V[v].size(); i++)
    {
        //consider only itself!
        int ii = V[v][i];
        if (V[v].size() != 1 && ii == J)
            continue;
        for (int k = 0; k < V[ii].size(); k++)
        {
            int j = V[ii][k];
            // cnt++;
            if (flag[j] > 0)
            {
                delt[flag[j] - 1] -= W[j];
            }
        }

        for (int j = 0; j < X.size(); j++)
        {
            if (X[j] == I)
                continue;
            else
            {
                int fX = f - delt[ii] + delt[X[j]];
                if (fX < fbest)
                {
                    fbest = fX;
                    M.clear();
                    M.push_back(make_pair(ii, X[j]));
                }
                else if (fX == fbest)
                {
                    M.push_back(make_pair(ii, X[j]));
                }
            }
        }
        delt.assign(deltlast.begin(), deltlast.end());
    }
    int k = rand() % M.size();
    I = M[k].first;
    J = M[k].second;
}

void makemove1(vector<int> &X, vector<int> &deltt, vector<int> &UX, vector<int> &flag, vector<int> &W, int N, int I, int J)
{
    for (int v = 0; v < V[I].size(); v++)
    {
        int vv = V[I][v];
        if (flag[vv] > 0)
        {
            deltt[flag[vv] - 1] -= W[vv];
        }
        else if (flag[vv] == 0)
        {
            for (int k = 0; k < V[vv].size(); k++)
                if (V[vv][k] != I)
                {
                    deltt[V[vv][k]] -= W[vv];
                }
        }
    }

    vector<int>::iterator vi;
    vi = find(X.begin(), X.end(), J);
    *vi = I;

    //re calc the flag:（flag=-1 cannot process）
    std::fill(flag.begin(), flag.end(), 0);
    //int cnt = 0;
    for (int i = 0; i < X.size(); i++)
    {
        for (int j = 0; j < V[X[i]].size(); j++)
        {
            if (flag[V[X[i]][j]] == 0)
                flag[V[X[i]][j]] = X[i] + 1;
            else if (flag[V[X[i]][j]] > 0)
                flag[V[X[i]][j]] = -1;
            //cnt++;
        }
    }

    
    //cout << cnt << endl;
    for (int v = 0; v < V[J].size(); v++)
    {
        int vv = V[J][v];
        if (flag[vv] == 0)
        {
            for (int i = 0; i < V[vv].size(); i++)
                if (V[vv][i] != J)
                    deltt[V[vv][i]] += W[vv];
        }
        else if (flag[vv] > 0)
        {
            deltt[flag[vv] - 1] += W[vv];
        }
    }
}
void makemove(vector<int> &X, vector<int> &delt, vector<int> &UX, vector<int> &flag, vector<int> &W, int N, int I, int J, int &f)
{
    // QueryPerformanceCounter(&t1);
    fill(delt.begin(), delt.end(), 0);
    vector<int>::iterator vi;
    vi = find(X.begin(), X.end(), J);
    *vi = I;
    //re calc the flag:flag=-1 cannot process
    fill(flag.begin(), flag.end(), 0);
    for (int i = 0; i < X.size(); i++)
    {
        for (int j = 0; j < V[X[i]].size(); j++)
        {
            if (flag[V[X[i]][j]] == 0)
                flag[V[X[i]][j]] = X[i] + 1;
            else if (flag[V[X[i]][j]] > 0)
                flag[V[X[i]][j]] = -1;
        }
    }

    UX.clear();
    int f1 = 0;
    for (int i = 0; i < N; i++)
    {
        if (flag[i] == 0)
        {
            UX.push_back(i);
            f1 += W[i];
            for (int k = 0; k < V[i].size(); k++)
                delt[V[i][k]] += W[i];
        }
        else if (flag[i] > 0) //flag[i]=center
        {
            delt[flag[i] - 1] += W[i];
        }
    }
    f = f1;
}

#include "stdio.h"
#include "cmath"
#include "iostream"
#include "algorithm"
using namespace std;
 
struct point
{
	long long x, y;
	bool flag;
};
point p[200003];
point tp[200003];
 
bool cmp_x(const point & a, const point & b) { return a.x < b.x; }
 
bool cmp_y(const point & a, const point & b) { return a.y < b.y; }
 
double min(double a, double b) { return a < b ? a : b; }
 
double dis(const point & a, const point & b)
{
	if(a.flag == b.flag) return 1e12;  //将类型相同的点之间的距离设为无穷大
 
	return sqrt((double)((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}
 
double solve(int lf, int rt, int n)  //left, right
{
	if(lf == rt) return 1e12;  //只有一个点时，距离设为无穷大
	if(rt - lf == 1)
		return dis(p[lf], p[rt]);
 
	int mid = (lf + rt) >> 1;
	double ans = min(solve(lf, mid, n), solve(mid + 1, rt, n));
 
	int lp = 0, i, j;
	for(i = mid; i >= lf && p[i].x - p[mid].x < ans; i--)
	{
		tp[lp].x = p[i].x;
		tp[lp].y = p[i].y;
		tp[lp++].flag = p[i].flag;
	}
 
	for(i = mid + 1; i <= rt && p[i].x - p[mid].x < ans; i++)
	{
		tp[lp].x = p[i].x;
		tp[lp].y = p[i].y;
		tp[lp++].flag = p[i].flag;
	}
 
	sort(tp, tp + lp, cmp_y);
 
	for(i = 0; i < lp; i++)
		for(j = i + 1; j - i < 7 && j < lp; j++)
			ans = min(ans, dis(tp[i], tp[j]));
 
	return ans;
}
 
int main()
{
	int n, i, t;
    double ans[10];
    cin >> t;
    int l = t;
    int j = 0;
    while(t--)
	{
		scanf("%d", &n);
		for(i = 1; i <= n; i++)
		{
			p[i].flag = true;
			scanf("%I64d%I64d", &p[i].x, &p[i].y);
		}
 
		for(i = n + 1; i <= 2 * n; i++)
		{
			p[i].flag = false;
			scanf("%I64d%I64d", &p[i].x, &p[i].y);
		}
 
		n += n;
		sort(p + 1, p + n + 1, cmp_x);
        ans[j++] = solve(1, n, n);
	}

    for (int k = 0; k < l;k++)
    {
        printf("%.3f\n", ans[k]);
    }

        return 0;
}
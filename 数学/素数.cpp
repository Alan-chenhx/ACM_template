//质数 线性筛
#include <bits/stdc++.h>
using namespace std;
//埃xx算法划掉质数的倍数
const int MAXN = 1000010;
bool notprime[MAXN];//值为false 表示素数，值为true 表示非素数
void init() {
	memset(notprime, false, sizeof(notprime));
	notprime[0] = notprime[1] = true;
	for (int i = 2; i < MAXN; i++)
		if (!notprime[i]) {
			if (i > MAXN / i)continue;//防止后面i*i 溢出(或者i,j 用longlong)
			//直接从i*i 开始就可以，小于i 倍的已经筛选过了, 注意是j+=i
				for (int j = i * i; j < MAXN; j += i)
					notprime[j] = true;
		}
	
}
//线性筛
const int MAXN2 = 10000;
int prime[MAXN2 + 1];
void getPrime() {
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i <= MAXN2; i++) {
		if (!prime[i])prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0] && prime[j] <= MAXN2 / i; j++) {
			prime[prime[j] * i] = 1;
			if (i%prime[j] == 0) break;
		}
	}
}
//大区间素数筛
//
//POJ 2689 Prime Distance
//给出一个区间[L,U]，找出区间内容、相邻的距离最近的两个素数和
//距离最远的两个素数。
//1<=L<U<=2,147,483,647 区间长度不超过1,000,000
//就是要筛选出[L,U] 之间的素数
const int MAXN = 100010;
int prime[MAXN + 1];
void getPrime() {
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i <= MAXN; i++) {
		if (!prime[i])prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++) {
			prime[prime[j] * i] = 1;
			if (i%prime[j] == 0)break;
		}
	}
}
bool notprime[1000010];
int prime2[1000010];
void getPrime2(int L, int R) {
	memset(notprime, false, sizeof(notprime));
	if (L<2)L = 2;
	for (int i = 1; i <= prime[0] && (long long)prime[i] * prime[i] <= R; i++) {
		int s = L / prime[i] + (L%prime[i]>0);
		if (s == 1)s = 2;
		for (int j = s; (long long)j*prime[i] <= R; j++)
			if ((long long)j*prime[i] >= L)
				notprime[j*prime[i]-L] = true;
	}
	prime2[0] = 0;
	for (int i = 0; i <= R-L; i++)
		if (!notprime[i])
			prime2[++prime2[0]] = i + L;
}
int main() {
	getPrime();
	int L, U;
	while (scanf("%d%d", &L, &U) == 2) {
		getPrime2(L, U);
		if (prime2[0] < 2)printf("There.are.no.adjacent.primes.\n");
		else {
			int x1 = 0, x2 = 100000000, y1 = 0, y2 = 0;
			for (int i = 1; i < prime2[0]; i++) {
				if (prime2[i + 1]-prime2[i] < x2-x1) {
					x1 = prime2[i];
					x2 = prime2[i + 1];
				}
				if (prime2[i + 1]-prime2[i] > y2-y1) {
					y1 = prime2[i];
					y2 = prime2[i + 1];
				}
			}
			printf("%d,%d.are.closest,.%d,%d.are.most.distant.\n",
				x1, x2, y1, y2);
		}
	}
}
//prime factorization质数分解
//素数筛选和合数分解
const int MAXN = 10000;
int prime[MAXN + 1];
void getPrime() {
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i <= MAXN; i++) {
		if (!prime[i])prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++) {
			prime[prime[j] * i] = 1;
			if (i%prime[j] == 0) break;
		}
	}
}
long long factor[100][2];
int fatCnt;
int getFactors(long long x) {
	fatCnt = 0;
	long long tmp = x;
	for (int i = 1; prime[i] <= tmp / prime[i]; i++) {
		factor[fatCnt][1] = 0;
		if (tmp%prime[i] == 0) {
			factor[fatCnt][0] = prime[i];
			while (tmp%prime[i] == 0) {
				factor[fatCnt][1]++;
				tmp /= prime[i];
			}
			fatCnt++;
		}
	}
	if (tmp != 1) {
		factor[fatCnt][0] = tmp;
		factor[fatCnt++][1] = 1;
	}
	for (int i = 0; i < fatCnt; i++) {
		printf("%lld %lld\n", factor[i][0], factor[i][1]);
	}
	return fatCnt;
}


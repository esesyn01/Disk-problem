#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
using namespace std;
struct file {
	 long long id;
	 long long size;
};
void change(file *a, file *b)
{
	file temp;
	temp.id = b->id;
	temp.size = b->size;
	b->id = a->id;
	b->size = a->size;
	a->id = temp.id;
	a->size = temp.size;
}
void qs_bysize(file* tab, int l, int r)
{
	int i = l;
	int j = r;
	file axis = tab[(i + j) / 2];
	while (j >= i)
	{
		while (tab[i].size < axis.size)
		{
			++i;
		}
		while (tab[j].size > axis.size)
		{
			--j;
		}
		if (j >= i)
		{
			change(&tab[i], &tab[j]);
			++i;
			if(j!=0)
			j--;
		}
	}
	if (j > l)
	{
		qs_bysize(tab, l, j);
	}
	if (i < r)
	{
		qs_bysize(tab, i, r);
	}
}
void qs_byid(file* tab, int l, int r)
{
	int i = l;
	int j = r;
	file axis = tab[(i + j) / 2];
	while (j >= i)
	{
		while (tab[i].id > axis.id)
		{
			++i;
		}
		while (tab[j].id < axis.id)
		{
			--j;
		}
		if (j >= i)
		{
			change(&tab[i], &tab[j]);
			++i;
			if(j!=0)
			--j;
		}
	}
	if (j > l)
	{
		 qs_byid(tab, l, j);
	}
	if (i < r)
	{
		 qs_byid(tab, i, r);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, cap,it=0,it1=0,it2=0;
	long long cnt1=0,cnt2=0;
	scanf("%d %d", &n, &cap);
	file* tab = new file[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%lld %lld",&tab[i].id,&tab[i].size);
	}
	qs_bysize(tab, 0, n - 1);
	file* pen1 = new file[n];
	file* pen2 = new file[n];
	while (cnt1 <= cap)
	{
		if (cnt1 + tab[it].size <= cap)
		{
			pen1[it1] = tab[it];

			cnt1 += tab[it].size;
			++it;
			++it1;
		}
		else
		{
			break;
		}
	}
	while (cnt2 <= cap)
	{
		if (cnt2 + tab[it].size <= cap)
		{
			pen2[it2] = tab[it];
			cnt2 += tab[it].size;
			++it;
			++it2;
		}
		else
		{
			break;
		}
	}
	if(it1>0)
	qs_byid(pen1, 0, it1-1);
	if(it2>0)
	qs_byid(pen2, 0, it2-1);
	printf("%d\n1: ", it);
	for (int i = 0; i < it1; i++)
	{
		printf("%lld ", pen1[i].id);
	}
	printf("\n2: ");
	for (int i = 0; i < it2; i++)
	{
		printf("%lld ", pen2[i].id);
	}
	delete[] pen1;
	delete[] pen2;
	delete[] tab;
	return 0;
}
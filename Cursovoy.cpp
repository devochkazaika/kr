//Программа поиска города, от которого достижимы все города
#include <stdio.h>
#include <string.h>
#include "Second.h"
#define n 20
char z[n][20];

struct listinc
{
int town; float weight; listinc *next;
};


int input(listinc *adj[],int N,FILE *p)
{
	char city[20];
	listinc *b;
	int r,i,g,j=0;
	float m;
	for(i=0;i<N;i++)
		z[i][0]='\0';
	while(!feof(p))
	{
		fscanf(p,"%s", city); r=0;
		for(i=0,r=0;i<j&&!r;i++)
			if(!strcmp(city,z[i])) r=1;
		if(r) i--;
		else
		{
			i=j;
			j++;
			strcpy(z[i],city);
		}
		fscanf(p,"%s", city); //ввод названия города–конца дороги
		for(g=0,r=0;g<j&&!r;g++)
			if(!strcmp(city,z[g]))
				r=1;
		if(r)
			g--;
		else
		{
			g=j;
			j++;
			strcpy(z[g],city); //добавить город в список городов
		}
		fscanf(p,"%d",&m); //ввод длины дороги
		for(b = adj[i]; b!= NULL&&b->town!=g; b = b->next) ;
		if (!b)
		{
			b=adj[i];
			adj[i]=new listinc;
			adj[i]->town=g;
			adj[i]->next=b;
			adj[i]->weight=m;
		}
		else if (m < b->weight)
			b->weight = m;
	}
	if(j<N)
		return 0; //есть изолированные города
	else return 1; //введен связный орграф
}




int search_ver ( int k, int N, listinc *adj [] )
{
	int i,v,u,flag=1;
	float d[n]; //массив расстояний от вершины k до остальных
	line *Q; //определение очереди (указателя на начало очереди)
	listinc *use ;
	Q = NULL;
	for(i=0;i<N;i++)
		d[i]=1000;
	d[k]=0;
	for(i=0; i<N; i++)
		in_line (&Q, i, d);
	while(Q&&flag) {
		u=out_line_min (&Q);
		if (d[u] > 100 )
			flag = 0;
		else {
			use=adj[u];
			if (use) {
				while( use ){
					v=use->town;
					if(d[v] > (d[u]+use->weight ))
						d[v] = d[u] + use->weight;
					use=use->next;
				}
				change(Q, d);
			}
		}
	}

	if(flag)
		for(i=0;i<N&&flag;i++)
			if(d[i]>100)
				flag=0;
	return flag;
}




int main()
{
	FILE *p;
	listinc *adj[n];
	int N,r,i,flag,result;
	p=fopen("input.txt","r");
	if (p!= NULL)
	{
		fscanf (p,"%d",&N );
		if(N>1)
		{
			for(i=0;i<N;i++)
				adj[i]=NULL;
			r=input(adj, N, p);
			if(r==1) {
				if(N==2)
				{
					for(i=0,flag=0;i<2&&!flag;i++) //поиск искомого города, если
						for(;adj [i]!=NULL;adj[i]=adj[i]->next)
							if(adj[i]->weight<=100)
								flag=1;
					result=flag;
				}
				else
				{
					for(i=0,flag=0;i<N&&!flag;i++)
						flag = search_ver (i, N, adj);
					result=flag;
				}
			}

			if(r==0)
				result=0; //изолированная вершина
			if(result)
			{ printf("\nв системе дорог есть такой город\n");


			printf("\nэто город %s\n", z [i-1] ); }
			else printf("\nв системе дорог нет такого города\n"); }
		else printf("\n система дорог пуста\n");
		fclose(p); }
	else
		printf("\n файл не открыт \n");

return 0;
}

#include <stdio.h>

struct line {
	int town;
	float pr;
	line *next, *prev;
};

void in_line (line **s, int v, float d[] )
{
	line *p;
	if ( *s )
	{
		p=(*s)->prev;
		p->next = new line;
		p->next->prev = p;
		p = p->next;
		p-> town = v;
		p->pr = d[v];
		(*s)->prev = p;
	}
	else
	{
		(*s) = new line;
		(*s)->next = (*s);
		(*s)->prev = (*s);
		(*s)-> town = v;
		(*s)-> pr = d[v];
	}
}

void change (line *s, float d [ ] )
{
	int i;
	line *p;
	p = s;
	do
	{
		i= p->town;
		p->pr = d[i];
		p = p->next;
	}
	while ( p!=s );
}


int out_line_min (line **s )
{
	line *p, *q;
	int x;
	float w;
	if ( (*s) == (*s)->next )
	{ x =(*s)-> town; delete (*s); (*s) = NULL; }
	else
	{
		w=(*s)->pr;
		q=*s;
		p=(*s)->next;
		while ( p != *s )
		{
			if(p->pr<w){w=p->pr; q=p;}
			p = p->next;
		}
		x = q-> town; //удаление элемента из очереди
		q->prev->next = q->next;
		q->next->prev = q->prev;
		if ( q == (*s) ) (*s) = q->next;
		delete (q);
	}
	return x;
}


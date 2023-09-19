#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

/* void swap_char(triangle *s, int i, int j)
{
    triangle *t1 = (triangle*) s;
    s[i] = s[j];
    s[j] = t1;
}
*/
double area(triangle tr) {
    double p = (tr.a + tr.b + tr.c) / 2.0;
    return sqrt(p * (p - tr.a) * (p - tr.b) * (p - tr.c));
}

int compare(const void *a, const void *b) {
    triangle *t1 = (triangle*) a;
    triangle *t2 = (triangle*) b;
    double area1 = area(*t1);
    double area2 = area(*t2);
    if (area1 > area2) {
        return 1;
    } else if (area1 < area2) {
        return -1;
    } else {
        return 0;
    }
}

void sort_by_area(triangle* tr, int n) {
    qsort(tr, n, sizeof(triangle), compare);
}

/*void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
  /*  triangle trr;
    for(int i =0; i<n;i++)
    {
         for(int j =i; j<n;j++)
      {
        if((tr[i].a*tr[i].b)>(tr[j].a*tr[j].b))
        {       trr.a = tr[i].a;
                tr[i].a = tr[j].a;
                tr[j].a = trr.a;

                trr.b = tr[i].b;
                tr[i].b = tr[j].b;
                tr[j].b = trr.b;
                
                trr.c = tr[i].c;
                tr[i].c = tr[j].c;
                tr[j].c = trr.c;
        }
      }
        
    }
}
*/
int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
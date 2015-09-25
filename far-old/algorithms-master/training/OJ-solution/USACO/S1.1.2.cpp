/*
ID : yajunw22
PROG : gift1
LANG : C++
*/

# include <stdio.h>
# include <memory.h>


# define freadInt(x) (fscanf(fin, "%d", &x))
# define freadStr(x) (fscanf(fin, "%s", x))
# define fwriteStr(x) (fprintf(fout, "%s", x))
# define fwriteInt(x) (fprintf(fout, "%d", x))
# define debug(x) (printf("%s\n", x))


const int maxn = 26*2;

unsigned int GetElementKey( char letter )
{
	return (letter >= 'a') ? (letter-'a'+26) : (letter-'A');
}

struct node {
	node * nextElement[maxn];
	int ID;
	node () {
		memset(nextElement, NULL, sizeof(nextElement));
		ID = -1;
	}
};


node * root = NULL;
int cntID;

node * InitDictTree( void )
{
	cntID = 0;
	root = new node();
	return root;
}

int InsertName( const char * strName )
{
	if (root == NULL) InitDictTree();
	node * p = root;
	for (int i = 0; strName[i]; ++i) {
		int idx = GetElementKey(strName[i]);
		if ( p->nextElement[ idx] == NULL ) {
			p->nextElement[idx] = new node();
		}
		p = p->nextElement[idx];
	}
	p->ID = ++cntID;
	return p->ID;
}

int GetNameIdx( const char * strName )
{
	if (root == NULL) return 0;
	node * p = root;
	for (int i = 0; strName[i]; ++i) {
		int idx = GetElementKey( strName[i] );
		if ( p->nextElement[ idx ] == NULL ) {
			return -1;
		}
		p = p->nextElement[ idx ];
	}
	return p->ID;
}


char names[15][25];
int account[15];

int main()
{
	FILE * fin = fopen("gift1.in", "r");
	FILE * fout = fopen("gift1.out", "w");

	int NP;
	freadInt(NP);
	for (int i = 0; i < NP; ++i) {
		freadStr(names[i]);
		account[ InsertName(names[i])] = 0;
	}

	char name[25];
	for (int i = 0; i < NP; ++i) {
		freadStr(name);
		int money, cnts, divMoney;
		freadInt(money);
		freadInt(cnts);
		if (cnts == 0) continue;
		divMoney = money / cnts;
		int idx = GetNameIdx(name);
		account[ GetNameIdx(name) ] -= divMoney*cnts;
		for (int j = 0; j < cnts; ++j) {
			freadStr(name);
			account[ GetNameIdx(name) ] += divMoney;
		}
	}
	fclose(fin);

	for (int i = 0; i < NP; ++i) {
		fwriteStr(names[i]);
		fwriteStr(" ");
		fwriteInt(account[ GetNameIdx(names[i]) ]);
		fwriteStr("\n");
	}

	fclose(fout);

	return 0;
}

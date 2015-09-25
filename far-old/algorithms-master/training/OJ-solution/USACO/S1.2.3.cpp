/*
ID : yajunw22
PROG : namenum
LANG : C++
*/
# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <vector>
# include <string>

char ID[25];
std::vector<std::string> vc;

void readNum(char *s)
{
	FILE * fp = fopen("namenum.in", "r");
	fscanf(fp, "%s", ID);
	fclose(fp);
}

char hh[25];
char * hash(char *s)
{
	for (int i = 0; s[i]; ++i) {
		if (s[i]<='R') hh[i] = (s[i]-'A')/3+2+'0';
		else hh[i] = (s[i]-'Q')/3+7+'0';
		if(!s[i+1]) hh[i+1] = '\0';
	}
	return hh;
}

void buildAns(void)
{
	char name[25];
	FILE * fp = fopen("dict.txt", "r");
	while (fscanf(fp, "%s", name)!=EOF) {
		if (strcmp(hash(name), ID) == 0) {
			vc.push_back(std::string(name));
		}
	}
	fclose(fp);
	sort(vc.begin(), vc.end());
}

void writeAns(void)
{
	FILE * fp = fopen("namenum.out", "w");
	if (vc.empty()) fprintf(fp, "NONE\n");
	for (int i = 0; i < vc.size(); ++i) {
		fprintf(fp, "%s\n", vc[i].c_str());
	}
	fclose(fp);
}

int main()
{
	readNum(ID);
	buildAns();
	writeAns();

	return 0;
}

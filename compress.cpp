#include <fstream>
#define LGMAX_SC 10000
#define LGMAX_S LGMAX_SC*100
using namespace std;
ifstream fin("compress.in");
ofstream fout("compress.out");
int poz, lg;
char sc[LGMAX_SC], s[LGMAX_S];
void decompress();
int main()
{
	fin >> sc;
	fin.close();
	do
	{
		for (; sc[poz] != '(' && sc[poz]; poz++)
		{
			s[lg++] = sc[poz];
		}
		if (sc[poz] == '(')
		{
			poz++;
			decompress();
		}
	}
	while (sc[poz]);
	s[lg] = 0;
	fout << s;
	fout.close();
	return 0;
}
void decompress()
{
	int st, dr, nr, i, j; 
	st = lg;
	while(sc[poz] != ')')
	{
		if (sc[poz] != '(')
		{
			s[lg++] = sc[poz++];
		}
		else
		{
			poz++;
			decompress();
		}
	}
	dr = lg;
	nr = sc[++poz]-'0';
	for (++poz; sc[poz] >= '0' && sc[poz] <= '9'; poz++)
	{
		nr = nr*10 + (sc[poz]-'0');
	}
	for (i = 1; i < nr; i++)
	{
		for (j = st; j < dr; j++)
		{
			s[lg++] = s[j];
		}
	}
}

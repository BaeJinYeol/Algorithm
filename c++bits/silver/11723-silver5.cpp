#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> set;
vector<bool> check_num(21, false);

void add(int x) 
{
	if (!check_num[x]) {
		set.push_back(x);
		check_num[x] = 1;
	}
}
void remove(int x) 
{
	if (check_num[x]) {
		set.erase(remove(set.begin(), set.end(), x), set.end());
		check_num[x] = 0;
	}
}
void check(int x) 
{
	if (check_num[x]) cout << 1 << '\n';
	else cout << 0 << '\n';
}
void toggle(int x) 
{
	if (check_num[x]) remove(x);
	else add(x);
}
void all() 
{
	set = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 
		12, 13, 14, 15, 16, 17, 18, 19, 20 };
	check_num.assign(check_num.size(), true);
}
void empty() 
{
	set.clear();
	check_num.assign(check_num.size(), false);
}

int CheckOperator(const string oper) 
{
	if (!oper.compare("add")) return 1;
	else if (!oper.compare("remove")) return 2;
	else if (!oper.compare("check")) return 3;
	else if (!oper.compare("toggle")) return 4;
	else if (!oper.compare("all")) return 5;
	else return 6;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int num = 0;
		string oper;
		cin >> oper;
		if (oper.compare("all") && oper.compare("empty")) cin >> num;

		switch (CheckOperator(oper))
		{
		case 1:
			add(num);
			break;
		case 2:
			remove(num);
			break;
		case 3:
			check(num);
			break;
		case 4:
			toggle(num);
			break;
		case 5:
			all();
			break;
		case 6:
			empty();
			break;
		}
	}

	return 0;
}
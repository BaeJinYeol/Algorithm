#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Member {
	int age;
	string name;
};

bool compareAge(const Member& a, const Member& b) {
	return a.age < b.age;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num, i;
	cin >> num;

	vector<Member> memberList(num);

	for (i = 0; i < num; i++)
		cin >> memberList[i].age >> memberList[i].name;
	
	stable_sort(memberList.begin(), memberList.end(), compareAge);

	for (Member person : memberList)
		cout << person.age << " " << person.name << '\n';

	return 0;
}
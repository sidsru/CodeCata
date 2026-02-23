// 백준
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);
class CustomStack
{
public:
	void push(const int InStack)
	{
		v.push_back(InStack);
	}
	void pop()
	{
		if (v.empty() == true)
		{
			cout << -1 << endl;
		}
		else if (v.empty() == false)
		{
			cout << v.back() << endl;
			v.pop_back();
		}
	}
	void size()const
	{
		cout << v.size() << endl;
	}
	void IsEmpty() const
	{
		if (v.empty() == true)
		{
			cout << 1 << endl;
		}
		else if (v.empty() == false)
		{
			cout << 0 << endl;
		}
	}
	void Top()const
	{
		if (v.empty() == true)
		{
			cout << -1 << endl;
		}
		else if (v.empty() == false)
		{
			cout << v.back() << endl;
		}
	}
private:
	vector<int> v;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	CustomStack s;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		switch (temp)
		{
		case 1:
			int num;
			cin >> num;
			s.push(num);
			break;
		case 2:
			s.pop();
			break;
		case 3:
			s.size();
			break;
		case 4:
			s.IsEmpty();
			break;
		case 5:
			s.Top();
			break;
		}
	}
	return 0;
}

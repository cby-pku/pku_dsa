#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
bool IsSame(string a, string b)
{
	char drop;
	//a短
		int mi = min(a.length(), b.length());
		string a1 = a; string b1 = b;
		sort(a1.begin(),a1.end());
		sort(b1.begin(), b1.end());
		bool exis = false;
		for (int i = 0; i < mi; i++)
		{
			if (a1[i] != b1[i])
			{	
					drop = b1[i];
					exis = true;
					break;
			}
		}
 
		if (!exis)
		{
			drop = b1[b1.length() - 1];
		}
		string ti; bool ex = false;
		for (int i = 0; i < a.length(); i++)
			{
				if (a[i]!=b[i])
				{
					ex = true;
					ti = a.substr(0, i);
					ti = ti + drop;
					ti = ti + a.substr(i, 1000);
					break;
				}
			}
		if (!ex)
		{
			ti =a+ drop;
		}
			if (ti!=b)
			{
				return false;
			}
			else {
				return true;
			}
}
int main()
{
	string dictionary[10010];
	string words[60];
	string a, b;
	int dic = 0; int m = 0;
	while (1)
	{
		cin >> a;
		if (a=="#")
		{
			break;
		}
		else
		{
			dictionary[dic++] = a;
		}
	}
	while (1)
	{
		cin >>b;
		if (b == "#")
		{
			break;
		}
		else
		{
			words[m++] = b;
		}
	}
	for (int i = 0; i <m; i++)
	{
		bool you = false;
		for (int j = 0; j < dic; j++)
		{
			if (dictionary[j]==words[i])
			{
				cout << words[i] << " is correct" << endl;
				you = true;
				break;
			}
		}//判断是否完全相同。
 
		if (you != true)
		{
			cout << words[i] << ": ";
			for (int j = 0; j < dic; j++)
			{
				int somewhat = words[i].length() - dictionary[j].length();
				if (somewhat == 0)
				{
					for (int k = 0; k < words[i].length(); k++)
					{
						if (words[i][k] != dictionary[j][k])
						{
							string tishen = words[i];
							tishen[k] = dictionary[j][k];
							if (tishen == dictionary[j])
							{
								cout << dictionary[j] << " ";
							}
						}
					}
				}
				if (abs(somewhat) == 1)
				{
					if (words[i].length() > dictionary[j].length())
					{
						if (IsSame(dictionary[j], words[i]))
						{
							cout << dictionary[j] << " ";
						}
					}
					else
					{
						if (IsSame(words[i], dictionary[j]))
						{
							cout << dictionary[j] << " ";
						}
					}
				}
			}
			cout << endl;
 
		}
	}
	return 0;
}
#include<iostream>
#include<string>
#include<fstream>
#include<map>
using namespace std;


void generateCSV()
{
	int t = 0;
	while (t < 2)
	{
		ofstream out;
		if (t == 0)
		{
			out.open("t1.csv",ios::out);
		}
		else
		{
			out.open("t2.csv", ios::out);
		}
		for (int i = 0; i < 1000000; i++)
		{
			int a = rand(), b = rand() + rand();
			string line;
			line.append(to_string(a));
			line.append(",");
			line.append(to_string(b));
			line.append("\n");
			out << line;
		}
		out.close();
		t++;
	}

}


map<int,int> getMap(string file)
{
	index:ifstream in(file);
	string line;
	map<int, int> m1;
	if (in)
	{
		while (getline(in, line))
		{
			size_t pos = line.find(",");
			string str_value = line.substr(0, pos);
			int value = atoi(str_value.c_str());
			if (value > 10)
			{
				map<int, int>::iterator it = m1.find(value);
				if (it == m1.end())
				{
					m1.insert(pair<int, int>(value, 1));
				}
				else
				{
					(*it).second++;
				}
			}
		}
		in.close();
	}
	else
	{
		in.close();
		generateCSV();
		goto index;
	}
	return m1;
}




int main()
{
	int count = 0;
	map<int, int> m1 = getMap("t1.csv"),m2 = getMap("t2.csv");
	for (map<int, int>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		map<int, int>::iterator it2 = m2.find((*it).first);
		if (it2 != m2.end())
		{
			count += (*it).second;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}
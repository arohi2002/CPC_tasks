#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector <int> getIntersection(vector < vector <int> > &sets){
	vector <int> result;
	int small_i = 0; 
	int mn = sets[0].size();
	for (int i = 1 ; i < sets.size() ; i++){
		sort(sets[i].begin(), sets[i].end());
		if (mn > sets[i].size()){
			mn = sets[i].size();
			small_i = i;
		}
	}

	map<int,int> mp;

	for (int i = 0; i < sets[small_i].size(); i++)
	{
		if (mp.find( sets[small_i][i] ) == mp.end())
			mp[ sets[small_i][i] ] = 1;
		else
			mp[ sets[small_i][i] ]++;
	}
	map<int,int>::iterator it;
	for (it = mp.begin(); it != mp.end(); ++it)
	{
		int elem = it->first;
		int freq = it->second;

		bool f = true;

		for (int j = 0 ; j < sets.size() ; j++){
			if (j != small_i){
				if (binary_search( sets[j].begin(), sets[j].end(), elem ))
				{
				int lInd = lower_bound(sets[j].begin(), sets[j].end(), elem)
															- sets[j].begin();
				int rInd = upper_bound(sets[j].begin(), sets[j].end(), elem)
															- sets[j].begin();

				if ((rInd - lInd) < freq)
					freq = rInd - lInd;
				}
				else
				{
					f = false;
					break;
				}
			}
		}

		if (f)
		{
			for (int k = 0; k < freq; k++)
				result.push_back(elem);
		}
	}
	return result;
}

void printset(vector <int> set)
{
	for (int i = 0 ; i < set.size() ; i++)
		cout<<set[i]<<" ";
}

void TestCase1()
{
	vector < vector <int> > sets;
	vector <int> set1;
	set1.push_back(1);
	set1.push_back(1);
	set1.push_back(2);
	set1.push_back(2);
	set1.push_back(5);

	sets.push_back(set1);

	vector <int> set2;
	set2.push_back(1);
	set2.push_back(1);
	set2.push_back(4);
	set2.push_back(3);
	set2.push_back(5);
	set2.push_back(9);

	sets.push_back(set2);

	vector <int> set3;
	set3.push_back(1);
	set3.push_back(1);
	set3.push_back(2);
	set3.push_back(3);
	set3.push_back(5);
	set3.push_back(6);

	sets.push_back(set3);

	vector <int> r = getIntersection(sets);

	printset(r);

}
int main()
{
	TestCase1();
	return 0;
}

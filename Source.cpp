#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;

bool nonDtest(vector<int> &v);


int main()
{
	vector<int>v1 = { 4, 1, 2 };
	nonDtest(v1);

	vector<int>v2 = {5,4,3,1,2};
	nonDtest(v2);

	return 0;

}



bool nonDtest(vector<int> &v)
{
	//using .size as it gives the number of elements not the size of the vector in bytes
	int numofelements = v.size();

	//since no triangle has less than three sides
	if (numofelements < 3) {
		cout << "no triangle has only two sides" << endl<<endl;
		return false;
	}

	else if (numofelements >= 3) {
		//we sort the vector to ease the comparison
		sort(v.begin(), v.end());

		//we use number of elements minus two to decrease the times we have to loop since it is
		//a sorted vector and if we only have 3 elements looping two more times would be useless
		//because we will be out of range and also comparing the same three numbers three times

		for (int i = 0; i < numofelements - 2; i++) {

			if ((v[i] + v[i + 1] > v[i + 2]) && (v[i + 1] + v[i + 2] > v[i]) && (v[i] + v[i + 2] > v[i + 1])) {

				cout << "it is possible to make a non-degenerate triangle out of these side lengths" << endl<<endl;

				return true;
			}
		}

		//if we don't find any 3 numbers that satisfy the non degeneracy state

		cout << "it is impossible to make a non-degenerate triangle out of these possible side lengths" << endl<<endl;

		return false;
	}
}



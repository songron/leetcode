#include<iostream>
#include<string>
using namespace std;
int main()
{
	string first = "";
	string second = "";
	cout << "\nEnter the First Word: ";
	getline(cin, first);
	cout << "\nEnter the Second Word: ";
	getline(cin, second);
	int letters_counter=0;
	if (first.length() == second.length())
	{
		bool found = false;
		
		for (int i = 0; i < first.length(); i++)
		{
			for (int j = 0; j < second.length(); j++)
			{
				if (first[i] == second[j])
				{
					found = true;
					break;
				}

			}

			if (found)
			{
				letters_counter += 1;
			}
		}
		if (letters_counter == first.length())
		{
			cout << "\nANAGRAMS";
		}
		else
		{
			cout << "\nNOT ANAGRAMS";
		}

	}
	else
	{
		cout << "\nNOT ANAGRAMS";
		cout << endl << endl;
		system("pause");
		return 0;
	}
	
	cout << endl << endl;
	system("pause");
	return 0;
}

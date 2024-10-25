#include <iostream>
#include <string>
using namespace std;

int start_with_letter_count(const char* a, const char b)
{
	int* count = new int(0);
	bool* flag = new bool(true);
	while (*a != '\0')
	{
		

		if (*a == b && *flag)
		{
			*count += 1;
		}
		*flag = false;
		if (*a == ' ')
		{
			*flag = true;
		}

		a++;
	}
	return *count;
	delete count;
	delete flag;
	

}

int word_min_len(const char* a)
{
	int* count = new int(0);
	int* temp = new int(0);
	
	
	for (; *a == ' '; a++)
	{}
	for (; *a != ' ' && *a != '\0';  a++)
	{
		*count += 1;
	}
	*temp = *count;
	*count = 0;
	while(*a != '\0')
	{
		
		for (; *a == ' '; a++)
		{}
		if (*a == '\0')
		{
			break;
		}
		for (; *a != ' ' && *a != '\0'; a++)
		{
			*count += 1;
		}
		
		if (*count < *temp )
		{
			*temp = *count;
		}
		*count = 0;
	}

	delete count;
	return *temp;
	delete temp;
}

int last_word_letter_count(const char* a, const char b)
{
	int* count = new int(0);
	for (;*a != '\0'; a++)
	{}
	for (; *a == ' ' || *a == '\0'; a--)
	{}

	for (; *a != ' '; a--)
	{
		if (*a == b)
		{
			*count += 1;
		}
	}
	return *count;
	delete count;
}


void tolower(char* a)
{
	while (*a != '\0')
	{
		if ('A' <= *a && *a <= 'Z')
		{
			*a += 32;

		}
		a++;
	}
}

int start_end_letter_same(const char* a)
{
	int* count = new int(0);
	char* temp = new char(0);

	while (*a != '\0')
	{
		for (; *a == ' ' && *a != '\0'; a++)
		{
		}
		*temp = *a;
		for (; *a != ' ' && *a != '\0'; a++)
		{
		}
		if (*(a - 1) == *temp)
		{
			*count += 1;
		}
	}

	delete temp;
	return *count;
	delete count;
}

int main()
{
	char a[1000];
	char letter = 'a';

	cout << "Enter words (below 1000 characters): " << endl;
	cin.getline(a, 1000);

	cout << endl;

	cout << "Task 1 (start_with_letter_" << letter << "_count): " << start_with_letter_count(a, letter) << "\n\n";
	cout << "Task 2 (word_min_len): " << word_min_len(a) << "\n\n";
	cout << "Task 3 (last_word_letter_" << letter << "_count): " << last_word_letter_count(a, letter) << "\n\n";
	tolower(a);
	cout << "Task 4 (tolower): " << a << "\n\n";
	cout << "Task 5 (start_end_letter_same): " << start_end_letter_same(a) << "\n\n";

	return 0;
}
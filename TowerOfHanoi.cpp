#include <iostream>
using namespace std;
int* from_tower;
int* to_tower;
int* aux_tower;
int from_end, to_end, aux_end;
int no_of_sliders = 5;
void toh(int n, char from, char  to, char aux);
void print_sliders(int no_of_sliders);
void update_table(char from, char  to);
int main()
{
	char a = 'A', b = 'B', c = 'C';
	from_tower = new int[no_of_sliders];
	to_tower = new int[no_of_sliders];
	aux_tower = new int[no_of_sliders];
	from_end = 0;  to_end = no_of_sliders; aux_end = no_of_sliders;
	for (int i = 0; i < no_of_sliders; i++)
	{
		from_tower[i] = i + 1;
		to_tower[i] = 0;
		aux_tower[i] = 0;
	}
	print_sliders(no_of_sliders);
	toh(no_of_sliders, a, c, b);
	cout << "Complete."<< endl;
	int ret;
	cin >> ret;
	return 0;
}
void toh(int n, char from, char  to, char aux)
{
	if (n == 1)
	{
		cout << " Moving slider " << n << " from " << from << " to " << to << endl;
		update_table(from, to);
		print_sliders(no_of_sliders);
	}
	else
	{
		toh(n - 1, from, aux, to);
		cout << " Moving slider " << n << " from " << from << " to " << to << endl;
		update_table(from, to);
		print_sliders(no_of_sliders);
		toh(n - 1, aux, to, from);

	}
}
void print_sliders(int no_of_sliders)
{
	cout << "    Tower of Hanoi" << endl;
	cout << "**********************" << endl;
	for (int i = 0; i < no_of_sliders; i++)
	{
		cout << "    " << from_tower[i] << "      " << to_tower[i] << "     " << aux_tower[i] << endl;
	}
	cout << "    A      B     C" << endl;
	cout << "**********************" << endl;
}
void update_table(char from, char  to)
{
	int temp;
	switch (from)
	{
	case 'A':
		temp = from_tower[from_end];
		from_tower[from_end] = 0;
		from_end++;
		break;
	case 'B':
		temp = to_tower[to_end];
		to_tower[to_end] = 0;
		to_end++;
		break;
	case 'C':
		temp = aux_tower[aux_end];
		aux_tower[aux_end] = 0;
		aux_end++;
		break;
	default:
		break;
	}
	switch (to)
	{
	case 'A':
		from_end--;
		from_tower[from_end] = temp;
		break;
	case 'B':
		to_end--;
		to_tower[to_end] = temp;
		break;
	case 'C':
		aux_end--;
		aux_tower[aux_end] = temp;
		break;
	default:
		break;
	}
}

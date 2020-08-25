#include <iostream>
using namespace std;
// back tracking for the connected components
#define n_rows 5
#define n_columns 6
#define DiagonalNeighbours 0
int sample_array[n_rows][n_columns] = 
{ 
{0, 0, 1, 0, 0, 1},
{0, 1, 1, 0, 1, 0 },
{0, 1, 1, 0, 0, 0 },
{1, 0, 1, 0, 1, 0 },
{1, 0, 0, 0, 0, 1 }
};
void print_matrix(int * track_components, int row_no, int column_no);
int countConnectedComponents();
void recurConnectedComponents(int * track_components, int row_no, int column_no);
int main()
{	
	int ret;
	print_matrix(&sample_array[0][0], n_rows, n_columns);
	cout<<"No of connected components "<<countConnectedComponents()<<endl;	
	cin >> ret;

	return 0;
}

void print_matrix(int * track_components, int row_no, int column_no)
{
	cout<<"Matrix is "<<endl;
	for (int row_no = 0; row_no < n_rows; row_no++)
	{		for (int col_no = 0; col_no < n_columns; col_no++)
		{
			cout << *(track_components+(row_no*n_columns)+col_no) << " ";
		}
	cout << endl;
	}	
	cout << endl;
}

int countConnectedComponents()
{
	int count = 0;
	int track_components[n_rows][n_columns];		
	memset(&track_components[0][0], 0, sizeof(int)*n_columns*n_rows);
	for (int row_no = 0; row_no < n_rows; row_no++)
		for (int column_no = 0; column_no < n_columns; column_no++)
			if (sample_array[row_no][column_no] == 1 && track_components[row_no][column_no] == 0 )
			{
				recurConnectedComponents(&track_components[0][0], row_no, column_no);
				count++;				
			}
			else {
				track_components[row_no][column_no] = 1;
			}
	return count;	
}
void recurConnectedComponents(int * track_components, int row_no, int column_no)
{
	*(track_components+((row_no*n_columns)+column_no)) = 1;
#if DiagonalNeighbours 
	signed int x_axis[] = { 0, 0, 1,-1, 1, -1, 1, -1 };
	signed int y_axis[] = { 1,-1, 0, 0, 1, 1, -1, -1 };
	int neighbourhood_size = 8;
#else
	signed int x_axis[] = { 0, 0, 1,-1 };
	signed int y_axis[] = { 1,-1, 0, 0 };
	int neighbourhood_size = 4;
#endif
	for (int neighour = 0; neighour < neighbourhood_size; neighour++)
	{
		if (row_no + x_axis[neighour] < 0|| row_no + x_axis[neighour] >= n_rows)
			continue ;
		if (column_no + y_axis[neighour] < 0 || column_no + y_axis[neighour] >= n_columns)
			continue;
		if(sample_array[row_no+x_axis[neighour]][column_no+y_axis[neighour]]==1 && *(track_components + (((row_no + x_axis[neighour])*n_columns) + column_no + y_axis[neighour])) == 0)
			recurConnectedComponents(track_components, row_no + x_axis[neighour], column_no+ y_axis[neighour]);
	}
}

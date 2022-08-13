#include <iostream>
#include "Hungarian.h"
#include <cmath>
using namespace std;


vector<vector<double>> find_distance_table(int number_of_point, float x_start[], float y_start[], float z_start[], float x_goal[], float y_goal[], float z_goal[])
{

	vector<vector<double>> distance_table(number_of_point, vector<double> (number_of_point, 0));
	for(int i=0 ; i<number_of_point; i++)
	{
		float x_s= x_start[i];
		float y_s= y_start[i];
		float z_s= z_start[i];
		
		for(int j=0 ; j<number_of_point; j++)
		{
			float x_g = x_goal[j];
			float y_g = y_goal[j];
			float z_g = z_goal[j];

			double distance = sqrt(pow((x_s - x_g), 2) + pow((y_s - y_g), 2) + pow((z_s - z_g), 2));
			distance_table[i][j] = distance;
			//cout << distance<< "\t";

		}
		//cout << endl;
	}

	
	return distance_table;

}

void change_order_of_goals(int number_of_point, vector<int> assignment, float x_goal[], float y_goal[], float z_goal[])
{


	float* x_goal_copy = new float(number_of_point);
	float* y_goal_copy = new float(number_of_point);
	float* z_goal_copy = new float(number_of_point);

	for(int i=0 ; i<number_of_point ; i++)
	{
		x_goal_copy[i] = x_goal[i];
		y_goal_copy[i] = y_goal[i];
		z_goal_copy[i] = z_goal[i];
	}

	
	for (unsigned int x = 0; x < number_of_point ; x++)
	{
		int best_goal_index = assignment[x];
		
		//call by refrence:)
		x_goal[x] = x_goal_copy[best_goal_index];
		y_goal[x] = y_goal_copy[best_goal_index];
		z_goal[x] = z_goal_copy[best_goal_index];
	}

}



int main(void)
{

	float x_goal[4] = {-40, -40, 40, 40};
	float y_goal[4] = {40, 20, -40, -20};
	float z_goal[4] = {-10, -10, 10, 10};
	


	float x_start[4] = {50, 50, -50, -50};
	float y_start[4] = {20, 40, 20, 40};
	float z_start[4] = {0, 0, 0, 0};
	
	int number_of_point = 4;

	for(int i=0 ; i<number_of_point; i++)
	{
		cout << "(" << x_start[i] << " , " << y_start[i] << " , " << z_start[i]<< ") ";
	}
	cout << "\n\n";
	for(int i=0 ; i<number_of_point; i++)
	{
		cout << "(" << x_goal[i] << " , " << y_goal[i] << " , " << z_goal[i]<< ") ";
	}
	cout << "\n\n";


    // please use "-std=c++11" for this initialization of vector.
	// vector< vector<double> > costMatrix ={{ 92, 90, 61, 42}, 
	// 									  { 90, 92, 81, 61 }, 
	// 									  { 24, 14, 108, 98}, 
	// 									  { 14, 24, 120, 108} };

	vector< vector<double> > costMatrix = find_distance_table(number_of_point, x_start, y_start, z_start, x_goal, y_goal, z_goal);

	HungarianAlgorithm HungAlgo;
	vector<int> assignment;

	double cost = HungAlgo.Solve(costMatrix, assignment);

	change_order_of_goals(number_of_point, assignment, x_goal,  y_goal, z_goal);


	cout << "\n\nOutput : \n\n";
	for(int i=0 ; i<number_of_point; i++)
	{
		cout << "(" << x_start[i] << " , " << y_start[i] << " , " << z_start[i]<< ") ";
	}
	cout << "\n\n";
	for(int i=0 ; i<number_of_point; i++)
	{
		cout << "(" << x_goal[i] << " , " << y_goal[i] << " , " << z_goal[i]<< ") ";
	}
	cout << "\n\n";

	cout << "\ncost: " << cost << std::endl;

	return 0;
}

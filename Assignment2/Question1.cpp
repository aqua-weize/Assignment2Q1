#include <iostream>
#include <iomanip>
using namespace std;
//function prototype
int findTotal(int votes[], int number);
double calculatePercentage(int votes[], int total);
double calculatePercentage1(int votes[], int total);
double calculatePercentage2(int votes[], int total);
double calculatePercentage3(int votes[], int total);
double calculatePercentage4(int votes[], int total);
string findWinner(string candidates[], int votes[]);
void displayResults(string candidates[], int votes[],double percent[]);
//main
int main()
{
	string candidates[5] = { "" };
	int votes[5] = { 0 };
	double percent[5] = { 0.0 };
	int total = 0;
	//user input the candidates' name
	for (int Iname = 0; Iname < 5; Iname++)
	{
		char canName[100];
		cout << "Enter the candidate " << Iname + 1 << " name: ";
		cin.getline(canName, sizeof(canName));
		candidates[Iname] = canName;
	}
	//user input the votes count of contestants
	for (int Ivote = 0; Ivote < 5; Ivote++)
	{
		cout << "\nEnter the votes received for contestant " << candidates[Ivote] << ": ";
		while (!(cin >> votes[Ivote]))
		{
			cout << "Please enter valid number: ";
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	//function calling
	total = findTotal(votes, 5);
	cout << "Total votes are " << total << endl;
	percent[0] = calculatePercentage(votes, total);
	percent[1] = calculatePercentage1(votes, total);
	percent[2] = calculatePercentage2(votes, total);
	percent[3] = calculatePercentage3(votes, total);
	percent[4] = calculatePercentage4(votes, total);
	
	//display result
	displayResults(candidates, votes, percent);
	//display winner
	total = findTotal(votes, 5);
	cout << "\nTotal votes are " << total << endl;
	cout << "The Winner of election is: " << findWinner(candidates, votes) << "!!!" <<  endl << "\nCONGRATULATIONS";
	return 0;
}
//function definition
int findTotal(int votes[], int numbers)
{
	double total = 0.0;
	for (int j = 0; j < 5; j++)
	{
		total += votes[j];
	}
	return total;
}
double calculatePercentage(int votes[], int total)
{
	double Percentage = 0.0;
	Percentage = (votes[0] / static_cast<double>(total));
	return Percentage;
}
double calculatePercentage1(int votes[], int total)
{
	double Percentage = 0.0;
	Percentage = (votes[1] / static_cast<double>(total));
	return Percentage;
}
double calculatePercentage2(int votes[], int total)
{
	double Percentage = 0.0;
	Percentage = (votes[2] / static_cast<double>(total));
	return Percentage;
}
double calculatePercentage3(int votes[], int total)
{
	double Percentage = 0.0;
	Percentage = (votes[3] / static_cast<double>(total));
	return Percentage;
}
double calculatePercentage4(int votes[], int total)
{
	double Percentage = 0.0;
	Percentage = (votes[4] / static_cast<double>(total));
	return Percentage;
}

string findWinner(string candidates[], int votes[])
{
	string winner = "";
	int highest = 0;

	for (int j = 0; j < 5; j++)
	{
		if (votes[j] > highest)
		{
			highest = votes[j];
			winner = candidates[j];
		}
	}
	return winner;
}
void displayResults(string candidates[], int votes[], double percent[])
{
	cout << "\nStudents/Contestants" << setw(25) << "Votes received" << setw(25) << "% of Total votes" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << setw(10) << candidates[i] << setw(30) << votes[i] << setw(25) << (percent[i]*100) << endl;
	}
}



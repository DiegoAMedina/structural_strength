//Diego Medina, David Jia, Alexis Munoz, Noe Lomeli
//10-30-15
//Evaluating Structural Strength

#include<iostream> // input output
#include<fstream> // files
#include<vector>
#include<cmath>
#include<cstdlib> // exit()
#include<string> // string
using namespace std;

double variance(int ary[], int num);
//Summary: Calculates the variance of the values
//Precondition: Takes in an array, the mean, and the number of values in the array
//Postcondition: Returns the variance of the values
//
//**********************************************************************************************
double mean(int ary[], int n);
//Summary: Calculates the mean of the values  
//Precondition: Array must be of type int, with the size/number of positions of the array going
//to be used, passed in as the second parameter of type int.
//Postcondition: Returns the mean of the the array type double
//
//**********************************************************************************************
double stdDev(double var);
//Summary: Calculates the standard deviation of the values
//Precondition: Takes in the value for the variance
//Postcondition: Returns the standard deviation of the values
//
//**********************************************************************************************
int max(int ary[], int n);
//Summary: Computes the highest value in the files
//Precondition: Takes in the array and the size of the array
//Postcondition: Returns the highest value found
//
//**********************************************************************************************
int min(int ary[], int n);
//Summary: Computes the lowest value int the files
//Precondition: Takes in the array and the size of the array
//Postcondition: Returns the lowest value found
//
//**********************************************************************************************
int main()
{
	ifstream finA;
	ifstream finB;

	const int SIZE = 10;

	string strA; // to eat the string value
	string strB; // to eat the string value

	int steel[SIZE];
	int graphite[SIZE];
	int steelMin;
	int graphiteMin;
	int steelMax;
	int graphiteMax;
	int num;


	double steelMean;
	double graphiteMean;
    double steelVariance;
    double graphVariance;
	double steelStdDev;
	double graphiteStdDev;
    
	finA.open("data1.txt");
	finB.open("data2.txt");
    
	if(finA.fail())
	{
    	cout << "Error in opening input file." << endl;
    	exit(1);
	}
    
	if(finB.fail())
	{
    	cout << "Error in opening input file." << endl;
    	exit(1);
	}
    
	finA >> strA;
    
	finB >> strB;
    
	int count = 0;
    
	while(finA >> steel[count])
	{
    	count++;
	}
    
	count = 0;
    
	while(finB >> graphite[count])
	{
    	count++;
	}
   	 


	steelVariance = variance(steel, SIZE);
    graphVariance = variance(graphite, SIZE);  
	steelMean = mean(steel,SIZE);
	graphiteMean = mean(graphite,SIZE);
	steelMin = min(steel,SIZE);
	graphiteMin = min(graphite,SIZE);
	steelMax = max(steel,SIZE);
	graphiteMax = max(graphite,SIZE);
	steelStdDev = stdDev(steelVariance);
	graphiteStdDev = stdDev(graphVariance);

    
	cout << "\t\t\tSteel\t\tGraphite " << endl << endl;
	cout << "Mean:\t\t\t" << steelMean << "\t\t" << graphiteMean << endl;
	cout << "Maximum Value:\t\t" << steelMax << "\t\t" << graphiteMax << endl;
	cout << "Minimum Value:\t\t" << steelMin << "\t\t" << graphiteMin << endl;
	cout << "Variance: \t\t" << steelVariance << "\t" << graphVariance << endl;
	cout << "Standard Deviation:\t" << steelStdDev << "\t\t" << graphiteStdDev << endl << endl;
	cout << "On the third standard deviation, the steel coupon can only hold 18846.9 - " <<
   		 "(1190.7 * 3) Newtons, which is 15274.8 Newtons. This does not meet the " <<
   	 	"anticipated load of 16000 Newtons. Likewise on the third standard deviation, " <<
   	      "the graphite coupon can only hold 18581.4 - (1018.08 * 3) Newtons, which is " <<
   	      "15527.16 Newtons. This also does not meet the anticipated load of 16000 " <<
   	      "Newtons." << endl << endl;
    



	finA.close();
	finB.close();    

	return 0;
}
//******************************************************************************
double mean(int ary[], int n)
{
	double mean;
	double sum = 0.0;

	for(int ix = 0; ix < n; ix++)
	{
    	sum += ary[ix];
	}

	mean = sum / n;

	return mean;
}

double stdDev(double var)
{
	double result;
    
	result = sqrt(var);

	return result;
}

int max(int ary[], int n)
{
	int max = ary[0];

	for(int ix = 0; ix < n; ix++)
	{
    	if(ary[ix] > max)
    	{
        	max = ary[ix];
    	}
	}
    
	return max;
}

int min(int ary[], int n)
{
 	int min = ary[0];


	for (int ix = 0; ix < n; ix++)
	{
    	if(ary[ix] < min)
    	{
        	min = ary[ix];
    	}

	}

	return min;
}

double variance(int ary[], int num)
{
    double mean1 = mean(ary, num);
    double difference;
	double variance;
	double change;

    for (int ix(0); ix < num; ix++)
	{
    	difference = ary[ix]-mean1;
    	change = pow(difference,2);
   	 variance += change;
    }

    variance = variance/num;    

    return variance;
}





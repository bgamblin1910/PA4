#include "PA4.h"

// TODO: finish the functions and define/call additional functions
int numPackages(ifstream& inFile)
{
	int count = 0;
	 string num = " ";
  while (!inFile.eof()) {
    for(int i = 0; i < 6; i++)
	{
		getline(inFile,num);
	}
    if (!inFile.bad()) {
      count++;
    }
  }
  return count;
}
Package * loadPackages(ifstream& inFile, string * driverName, int * numPackages) {
	Package * output = new Package[*numPackages];
	string temp;
	int id1;
	double weight1;
	int width1;
	int length1;
	int height1;
	for(int i =0; i < *numPackages; i++)
	{
		getline(inFile,temp);
		Package temp; 
		inFile >> id1;
		inFile >> weight1;
		inFile >> width1;
		inFile >> length1;
		inFile >> height1;
		temp.id = id1;
		temp.weight = weight1;
		temp.width = width1;
		temp.length = length1;
		temp.height = height1;
		
		output[i] = temp;
	}
	
	return output;
}



void computePackageStats(const Package packages[], const int numPackages, int * heaviestId, double * heaviestWeight, double * avgWeight) {
	
	int id = 0;
	double weightHeavy = 0;
	double average = 0;
	for(int i =0; i < numPackages; i++)
	{
		if(weightHeavy < (packages[i].weight))
		{
			id = packages[i].id;
			weightHeavy = packages[i].weight;
		}
		average += packages[i].weight;
	}
	average /= numPackages;
	*heaviestId = id;
	*heaviestWeight = weightHeavy;
	*avgWeight = average;
}



void printPackage(string name, int numPackages, Package packages[], int heavy, double wei, double avg)
{
	cout << "The Number of packages on ";
	cout << name;
	cout << "'s truck: ";
	cout << numPackages<<endl<< endl;
	cout << "Package Info" << endl << "____________" << endl<< endl;
	for(int i =0; i < numPackages; i++)
	{
		cout<< "Package ID: " << packages[i].id << endl;
		cout<< "Package Weight: " << packages[i].weight << endl;
		cout<< "Package Width: " << packages[i].width << endl;
		cout<< "Package Length: " << packages[i].length << endl;
		cout<< "Package Height: " << packages[i].height << endl<< endl;
		
	}
	cout << "Package Data" << endl << "_____________"<< endl;
	cout << "ID of heaviest package: " << heavy<< endl;
	cout << "Weight of heaviest package: " << wei<< endl;
	cout << "Average weight of packages on truck: " << avg<< endl<< endl;
}

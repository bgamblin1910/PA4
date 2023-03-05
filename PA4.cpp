/*
 Name: Ben Gamblin
 Class: CptS 122, Spring 2022
 Date: 3/5/2022
 Programming Assignment: PA4                                                                     
 Description: This program organizes, 
 calculates and prints stats about a
 set of packages organized in a text file.
*/

#include "PA4.h"

// TODO: finish the functions and define/call additional functions
/*************************************************************
 * Function: numOfPackages()
 * Date Created: 3/2/2022 
 * Date Last Modified: 3/4/2022 
 * Description: calculates number of packages
 * Input parameters: the infile
 * Returns: number of packages in file
 * Pre: must have a text file with
 * Post: cursor moved in file
 *************************************************************/
int numOfPackages(ifstream& inFile)
{
	inFile.seekg(0, ios::beg);
	int count = 0;
	 string num = " ";
  while (!inFile.eof()) {
		getline(inFile,num);
    if (!inFile.bad()) {
      count++;
    }

  }
  
  return (count/6);
}

/*************************************************************
 * Function: loadPackages()
 * Date Created: 3/2/2022 
 * Date Last Modified: 3/4/2022 
 * Description: loads the packages into an array
 * Input parameters: the infile, string pointer for output, int pointer for num of Packages
 * Returns: array of packages
 * Pre: must have a text file with
 * Post: cursor moved in file
 *************************************************************/
Package * loadPackages(ifstream& inFile, string * driverName, int * numPackages) {
	*numPackages = numOfPackages(inFile);
	inFile.clear();
	inFile.seekg(0, ios::beg);
	Package * output = new Package[*numPackages];
	getline(inFile,*driverName);

	for(int i =0; i < *numPackages; i++)
	{
		// creates and fills a package
		inFile.seekg(1, ios::cur);
		Package temp; 
		inFile >> temp.id ;
		inFile >> temp.weight;
		inFile >> temp.width;
		inFile >> temp.length;
		inFile >> temp.height;
		output[i] = temp;
	}
	
	return output;
}


/*************************************************************
 * Function: computePackageStats()
 * Date Created: 3/2/2022 
 * Date Last Modified: 3/4/2022 
 * Description: calculates package array stats
 * Input parameters: packages array, number of packages and three int pointers.
 * Returns: nothing, fills pointers with stats
 * Pre: package array must be filled
 * Post: pointers are filled.
 *************************************************************/
void computePackageStats(const Package  packages[], const int numPackages, int * heaviestId, double * heaviestWeight, double * avgWeight) {
	//temporary variables
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


/*************************************************************
 * Function: printPackage()
 * Date Created: 3/2/2022 
 * Date Last Modified: 3/4/2022 
 * Description: prints package raay info
 * Input parameters: packages array, number of packages, name of truckers, and three package stats
 * Returns: nothing
 * Pre: package array must be filled and must have already calculated stats
 * Post: prints package info
 *************************************************************/
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

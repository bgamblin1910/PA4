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

// TODO: add parameters to main() for command line args
int main(int argc, char *argv[]) {
	// TODO: your code here
ifstream inFile(argv[1]);
  int count = 0; 
	string driverName;
int * numPackages = &count;
 // clear the EOF bit
  string * Name = &driverName;
  Package * packages = new Package[*numPackages];
  packages = loadPackages(inFile, Name, numPackages);
  int id = 0;
  double wei = 0.0;
  double avgW = 0.0;
  
  
  int * heaviestId = &id;
  double * heaviestWeight= &wei;
  double * avgWeight = &avgW;
	computePackageStats(packages, *numPackages, heaviestId, heaviestWeight, avgWeight);
  printPackage(driverName, *numPackages, packages, id, wei, avgW);
	
  Name = NULL;
heaviestId =  NULL;
heaviestWeight =  NULL;
avgWeight =  NULL;
packages =  NULL;
numPackages =  NULL;
  delete Name;
  delete heaviestId;
  delete heaviestWeight;
  delete avgWeight;
  
  delete packages;
  delete numPackages;
  return 0;
}

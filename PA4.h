/*
 Name: Ben Gamblin
 Class: CptS 122, Spring 2022
 Date: 3/5/2022
 Programming Assignment: PA4                                                                     
 Description: This program organizes, 
 calculates and prints stats about a
 set of packages organized in a text file.
*/
#ifndef PA4_H
#define PA4_H

#include <iostream>
#include <fstream>

using namespace std;

struct Package {
	int id;
	double weight;
	int width;
	int length;
	int height;
};

int numOfPackages(ifstream& inFile);
Package * loadPackages(ifstream& inFile, string * driverName, int * numPackages);
void computePackageStats(const Package package[], const int, int * heaviestId, double *, double *);
// TODO: add your additional function prototypes here
void printPackage(string name, int numPackages, Package packages[], int heavy, double wei, double avg);

#endif

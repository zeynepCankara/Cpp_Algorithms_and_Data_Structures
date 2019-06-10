/**
 * Title: Balanced Search Trees, Hashing and Graphs
 * Author: Zeynep Cankara
 * ID: 21703381
 * Section: 1
 * Assignment: 4
 * Description: Tester file for Assignment 4
 *              New STL library includes:
 *              -  <fstream>
 */

#include "graph.h"
#include <string>
#include <iostream>
/*You can add additional libraries here to read and process the dataset*/
#include <fstream> // file read/write

using namespace std;

#include <iostream>

// tester
int main() {
    /*YOUR IMPLEMENTATION*/
    // read input file
    ifstream inputF;
    // Airport Graph
    Graph a;
    fstream file("flightDataset.txt");
    if (!inputF) {
        cout << "ERROR: Can't open the file !!!" << endl; // FAIL: opening file
    } else {
        // Build the graph from the txt input file
        int numFlights = 220; // obtained from flightDataset.txt file
        for (int i = 0; i < numFlights; i++) { //read file and add edges
            string numPassengers; // passengers within the flight
            string src; // source
            string dst; // destination
            getline(file, src, ';');
            getline(file, dst, ';');
            getline(file, numPassengers, '\n');
            a.addConnection(src, dst, stoi(numPassengers));
        }
    }
    // Airport Graph
    Graph g;
    g.addAirport("PEK");
    g.addAirport("ATL");
    g.addAirport("DXB");
    g.addAirport("LAX");
    g.addAirport("CDG");
    g.addConnection("PEK", "LAX", 1000);
    g.addConnection("PEK", "DXB", 2000);
    g.addConnection("PEK", "CDG", 3000);
    g.addConnection("LAX", "CDG", 4000);
    g.addConnection("CDG", "PEK", 5000);
    // print the airports from NORWICH
    // working
    // test for getAdjacentAirports
    list <string> names = a.getAdjacentAirports("NORWICH");
    list<string>::iterator iterNode = names.begin();
    // iterate the list
    cout << "Airports from NORWICH: " << endl;
    while(iterNode != names.end())
    {
        cout << (*iterNode) << endl;
        iterNode++;
    }
    // test for getTotalPassengers
    int totalPassengers = a.getTotalPassengers("KIRKWALL");
    // working
    cout << "Total number of passengers from/to KIRKWALL: " << totalPassengers << endl;
    // test for findShortestPath from KIRKWALL to JERSEY
    list<string> shortestPath = a.findShortestPath("KIRKWALL", "JERSEY");
    for (list<string>::iterator it = shortestPath.begin(); it != shortestPath.end(); ++it){
        cout << "vertex: " << *it << endl;
    }
    // delete airport EDINBURGH
    // test for deleteAirport
    a.deleteAirport("EDINBURGH");
    cout << "Shortest path after deleting EDINBURGH" << endl;
    shortestPath = a.findShortestPath("KIRKWALL", "JERSEY");
    for (list<string>::iterator it = shortestPath.begin(); it != shortestPath.end(); ++it){
        cout << "vertex: " << *it << endl;
     }
    // Iterate through the adjList (delete airport test)
    cout << "Displaying the airports after EDINBURGH & MANCHESTER & JERSEY deleted" << endl;
    a.deleteAirport("MANCHESTER");
    a.deleteAirport("JERSEY");
    map< string, list<node> >::iterator it = a.adjList.begin();
    // Iterate through the map
    while(it != a.adjList.end())
    {
        cout << "vertex visited: " << it->first << endl;
        // Goto next
        it++;
    }
    // Create minimum spanning tree test
    //a.findMST();
    
    return 0;
}

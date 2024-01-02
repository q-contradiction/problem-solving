/*
 * Problem : www.codewars.com/kata/585894545a8a07255e0002f1
 *
 * The algorithm identifies the next possible steps given the current dot and the visited dots in the pattern
 * Then, using a given starting point, we run a standard recursion for len = len - 1, till the length of the pattern is 1.  
 */  

#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

set<char> dots{'A', 'B', 'C', 'D', 'E', 'F', 'G' ,'H', 'I'};

set<char> calculateConnectivity(char currentDot, set<char> availableDots) {

    set<char> connections(availableDots);

    switch (currentDot) {

    case 'A':
        if (availableDots.find('E') != availableDots.end())
            connections.erase('I');
        if (availableDots.find('D') != availableDots.end())
            connections.erase('G');
        if (availableDots.find('B') != availableDots.end())
            connections.erase('C');
        break;

    case 'B':
        if (availableDots.find('E') != availableDots.end())
            connections.erase('H');
        break;

    case 'C':
        if (availableDots.find('E') != availableDots.end())
            connections.erase('G');
        if (availableDots.find('B') != availableDots.end())
            connections.erase('A');
        if (availableDots.find('F') != availableDots.end())
            connections.erase('I');
        break;

    case 'D':
        if (availableDots.find('E') != availableDots.end())
            connections.erase('F');
        break;

    case 'E':
        break;

    case 'F':
        if (availableDots.find('E') != availableDots.end())
            connections.erase('D');
        break;

    case 'G':
        if (availableDots.find('E') != availableDots.end())
            connections.erase('C');
        if (availableDots.find('D') != availableDots.end())
            connections.erase('A');
        if (availableDots.find('H') != availableDots.end())
            connections.erase('I');
        break;

    case 'H':
        if (availableDots.find('E') != availableDots.end())
            connections.erase('B');
        break;

    case 'I':
        if (availableDots.find('E') != availableDots.end())
            connections.erase('A');
        if (availableDots.find('H') != availableDots.end())
            connections.erase('G');
        if (availableDots.find('F') != availableDots.end())
            connections.erase('C');
        break;
    }

    return(connections);
}

unsigned int countPatternsFrom(char currentDot, unsigned short length) {

    int patterns = 0;

    if (length <=0 || length >= 10) 
        return 0;
    else if (length == 1) 
        return 1;
    
    dots.erase(currentDot);

    set<char> connections = calculateConnectivity(currentDot, dots);

    for (auto nextDot : connections) {
        if (length > 1) 
            patterns += countPatternsFrom(nextDot, length - 1);
        dots.insert(nextDot);
    }

    dots.insert(currentDot);
    return patterns;
}


int main()
{
    // Test cases
    assert(countPatternsFrom('A', 0) == 0);
    assert(countPatternsFrom('A', 10) == 0);
    assert(countPatternsFrom('B', 1) == 1);
    assert(countPatternsFrom('C', 2) == 5);
    assert(countPatternsFrom('D', 3) == 37);
    assert(countPatternsFrom('E', 4) == 256);
    assert(countPatternsFrom('E', 8) == 23280);
}


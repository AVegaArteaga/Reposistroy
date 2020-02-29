///
//
// Lab03: Sets and Recursion
//
// 1: Recursively generate the Fibonacci numbers up to and including 10 and add them to set R.
// 2: Generate a second set O of odd numbers from 1 to 100.
// 3: Create a set I that is the intersection of R and O by STL set_intersection.
// 4: Create a set U that is the union of the sets R and the first half of set O, you may not use STL set_union.
// 5: Print out each set, R, O, I and U.
//
//
//

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <set>

#define NO_ITEM 5
#define ITEM_W 7
int fibonacci(int n) {
    if(n < 2) {
   	return n;
    }
    return fibonacci(n - 2) + fibonacci(n - 1);
}// End of fibonacci

int main() {
    std::set<int> R;
    std::set<int> O;
    size_t line_break = 0; //for formatting output
    std::cout << "\nBuilding a set, R, of recursively generated Fibonacci numbers up to and including 10: \n";
    for(size_t i = 2; i <= 10; i++)
	R.insert(fibonacci(i));
    std::cout << "Printing the set R: \n";
    for(auto i : R) {
	line_break++;
	std::cout << std::left << i << std::setw(ITEM_W);
	if(line_break % NO_ITEM == 0)
	    std::cout << std::endl;
    }
    line_break = 0; // resetting the line_break counter back to zero
    std::cout << "\nBuilding a set, O, of of odd numbers from 1 to 100: \n";
    for(size_t odd = 1; odd < 100; odd+=2)
	O.insert(odd);
    std::cout << "Printing the set O: \n";
    for(auto i : O) {
	line_break++;
	std::cout << std::left << i << std::setw(ITEM_W);
	if(line_break % NO_ITEM == 0)
	    std::cout << std::endl;
    }
    line_break = 0; //resetting the line_break counter back to zero
    std::cout << "Building the set, I, from intersection of R and O using set_intersection (STL): \n";
    std::set<int> I;
    //set_intersection has 6 arguments: the first 2 here tell the function to start at the beginning 
    //and continue until the end. the next 2 arguments do the same thing but for the set O. The last argument
    //uses the inserter to put the intersect of R and O into set I (starting at the beginning of I)
    set_intersection(R.begin(), R.end(), O.begin(), O.end(), std::inserter(I, I.begin()));
    for(auto it : I) {
	line_break++;
	std::cout << std::left << it << std::setw(ITEM_W);
	if(line_break % NO_ITEM == 0)
	    std::cout << std::endl;
    }
    line_break = 0; //resetting the line_break counter back to zero
    std::cout << "\nBuilding the set, U, from from half of O and R NOT using any STL algorithms: \n";
    std::set<int> U;
    unsigned int i = 0;
    auto it = R.begin();
    while(it != R.end()) {
	i++;
	if(i <= R.size() / 2)
	    U.insert(*it);
	else
	    break;
	it++;
    }
    auto it2 = O.begin();
    i = 0;
    while(it2 != O.end()) {
	  i++;
	if( i <= O.size() / 2)
	      U.insert(*it2);
	else
	    break;
	it2++;
    }	
    std::cout << "Printing out the set U: \n";
    for(auto i : U) {
	line_break++;
	std::cout << std::left << i << std::setw(ITEM_W);
	if(line_break % NO_ITEM == 0)
	    std::cout << std::endl;
    }
    std::cout << std::endl;
}

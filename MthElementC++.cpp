#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// Program to find the Mth integer in a space separated
// string of integers, where the last number is the
// Mth element to print. If that value is beyond the 
// number of values entered, print a blank space.
int main() {
  //Read sequence input
  string sequence_input;
  
  // Read the requested input into string
  getline(cin, sequence_input);
   
  //utilize stringstream to separate into tokens
  vector<string> tokens{};
  string token{};
  stringstream ss(sequence_input);
  
  // Push the tokens onto the stack
  while (ss >> token) {
    tokens.push_back(token);
  }
  
  // Find the value of 'M'
  int m = stoi(tokens.back());
  tokens.pop_back();
 
 // If the requested value is beyond the list
 // print a blank line.
  if (m > tokens.size()) {
    cout << endl;
  }
  else {
	// Print the requested value.
    cout << tokens[tokens.size() - m] << endl;
  }
  
  return 0;
}


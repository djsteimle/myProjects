#include <iostream>
#include <string>
#include <unordered_map>

// Mth last element of a sequence
// The last integer could be multiple digits
// Increase index based on spaces

using namespace std;

int main() {
  string line;
  
  // Speedy fast hash map
  // Could also use an array here but I wanted to be cool! DSA rocks!
  unordered_map<int, string> hash_map;
 
  //Index starts at 0 
  int index = 0;
  
  // Mth Integer from End of Sequence
  int mth_int = 0;
  
  string return_string = " ";
  
  // Get line to get the full string ex. ("a b c d 4")
  // Continues to execute until <ctrl>-C is pressed
  // To terminate execution.
  while (getline(cin, line))
  {  
    // Parse each character and store in a hash
    for (int i = 0; i < (int)line.length(); i++)
    {
      // Don't store spaces, but use as delimiter
	  // Between values.
	  if (line[i] == ' ')
      {
        // only increment based on spaces
        index++;
      }
      else
      {
        hash_map[index] += line[i];
      }
    }
   
    // Last string in map is the Mth Integer
    mth_int = stoi(hash_map[index]);
    
    // Print empty string if M is out of bounds
    if (mth_int > index)
    {
      return_string = " ";
    }
    else
    {
      return_string = hash_map[index - mth_int];
    }
    
    cout << return_string << endl;
  }
  return 0;
}
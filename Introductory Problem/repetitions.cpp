#include <iostream>
#include <string>

using namespace std;

int main() {
  string dna;
  cin >> dna;

  char current_char = dna[0];
  int current_length = 1;
  int max_length = 1;

  for (int i = 1; i < dna.size(); ++i) {
    if (dna[i] == current_char) {
      current_length++;
    } else {
      max_length = max(max_length, current_length);
      current_length = 1;
      current_char = dna[i];
    }
  }

  // Update max_length for the last character
  max_length = max(max_length, current_length);

  cout << max_length << endl;

  return 0;
}

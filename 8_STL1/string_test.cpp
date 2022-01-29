#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[]) {
  string s = "asdf";
  s[2] = 'k';

  cout << s << endl;
  return 0;
}

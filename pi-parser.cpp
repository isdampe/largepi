#include <iostream>
#include <string>
#include "pi-distribution.h"
#include "pi-repitition.h"
#include "pi-substring.h"

using namespace std;

struct pi_parser
{
  int program;
  string data_path;
};

void usage()
{
  cout << "Usage: ./pi-parser /path/to/pi.txt" << endl;
}

int menu_select()
{
  string result;
  int selection;
  cout << endl << "--Select a program--: " << endl;
  cout << "1. Count digit distribution" << endl;
  cout << "2. Substring search" << endl;
  cout << "3. Find repititions" << endl;
  cout << "4. Find first n repitition of k" << endl << endl;
  cout << "Selection: ";
  cin >> result;

  try {
    selection = stoi(result);
  } catch (invalid_argument e) {
    cout << "Please enter a number" << endl;
    return menu_select();
  }
  if ( selection < 1 || selection > 4 )
    return menu_select();

  return selection;

}

int main(int argc, char *argv[])
{
  if ( argc < 2 )
  {
    usage();
    return 1;
  }

  pi_parser app;
  app.program = menu_select();
  app.data_path = argv[1];

  switch ( app.program )
  {
    case 1:
      pi_distribution(app.data_path);
    break;
    case 2:
      pi_substring(app.data_path);
    break;
    case 3:
      pi_repitition(app.data_path);
    break;
    case 4:
      pi_repitition_nk(app.data_path);
    break;
  }

  return 0;
}

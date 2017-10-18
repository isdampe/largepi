#include <iostream>
#include <string>
#include "pi-distribution.h"

using namespace std;

struct pi_parser
{
  int program;
  string data_path;
};

int menu_select()
{
  string result;
  int selection;
  cout << endl << "--Select a program--: " << endl;
  cout << "1. Count digit distribution" << endl;
  cout << "2. Substring search" << endl;
  cout << "3. Find repititions" << endl << endl;
  cout << "Selection: ";
  cin >> result;

  try {
    selection = stoi(result);
  } catch (invalid_argument e) {
    cout << "Please enter a number" << endl;
    return menu_select();
  }
  if ( selection < 1 || selection > 3 )
    return menu_select();

  return selection;

}

int main()
{
  pi_parser app;
  app.program = menu_select();
  app.data_path = "../data/pi-5-bil.txt";

  switch ( app.program )
  {
    case 1:
      pi_distribution(app.data_path);
    break;
    case 2:

    break;
    case 3:

    break;
  }

  return 0;
}

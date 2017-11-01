#include <iostream>
#include <string>
#include "pi-io.h"
#include "pi-repitition.h"

using namespace std;

void pi_repitition(string in_file)
{
  pi_io session = pi_io_session(in_file, 0);
  unsigned long long i = 0, n = 1, highest_recur = 0, highest_idx = 0, current_count = 0;
  char current_digit, highest_digit;

  //Read first n bytes.
  string buffer;
  do {
    buffer = pi_io_read(session);

    for ( i=0; i<buffer.length(); i++ )
    {
      if ( current_digit != buffer[i] )
      {
        current_digit = buffer[i];
        current_count = 1;
      }
      else
      {
        current_count += 1;
        if ( current_count > highest_recur )
        {
          highest_recur = current_count;
          highest_idx = n - current_count -1;
          highest_digit = current_digit;
          cout << "Found new highest record: " << highest_digit << " " << highest_recur << " times at index " << highest_idx << endl;
        }
      }
      n++;
    }

    cout << session.progress << "%" << endl;

  } while( buffer != "" );

  cout << "Done." << endl;
  cout << "Most frequent reoccurence found: " << highest_recur << " repititions of \"" << highest_digit << "\" at index " << highest_idx << endl;

}

void pi_repitition_nk(string in_file)
{
  unsigned long long n;
  string k;

  n = get_input_int("Please enter a number for n");

  cout << "Please enter a number for k: ";
  cin >> k;

  pi_io session = pi_io_session(in_file, 0);
  unsigned long long x = 0, found_idx;
  unsigned int current_count = 0;
  bool found = false;

  //Read first n bytes.
  string buffer;
  do {
    buffer = pi_io_read(session);

    for ( int i=0; i<buffer.length(); i++ )
    {
      if ( buffer[i] == k[0] )
      {
        current_count++;

        if ( current_count >= n )
        {
          found = true;
          found_idx = (x - n);
          break;
        }
      }
      else
      {
        current_count = 0;
      }

      x++;

    }

    if ( found == true )
      break;

    cout << session.progress << "%" << endl;

  } while( buffer != "" );

  cout << "Done." << endl;
  if ( found == true )
    cout << "The first " << n << " repitions of " << k << " is at index " << found_idx << endl;
  else
    cout << "No " << n << " repititions of " << k << " was found" << endl;

}


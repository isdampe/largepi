#include <iostream>
#include <string>
#include "pi-io.h"
#include "pi-repitition.h"

using namespace std;

void pi_repitition(string in_file)
{
  pi_io session = pi_io_session(in_file);
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

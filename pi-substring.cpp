#include <iostream>
#include <string>
#include "pi-io.h"
#include "pi-substring.h"

using namespace std;

void pi_substring(string in_file)
{
  unsigned long long n = 0;
  unsigned long long max_idx, start_idx;
  bool found = false;
  string search_str = pi_substring_get_input();
  start_idx = get_input_int("Please enter a starting index (default 0): ");
  pi_io session = pi_io_session(in_file, start_idx);
  int substr_pos = 0, substr_end = search_str.length(), highest_pos = 0;
  
  //Read first n bytes.
  string buffer;
  do {
    buffer = pi_io_read(session);

    for ( int i=0; i<buffer.length(); i++ )
    {
  
      if ( buffer[i] == search_str[substr_pos] )
      {
        substr_pos++;
        if ( substr_pos > highest_pos )
        {
          highest_pos = substr_pos;
          max_idx = n - (substr_pos) + start_idx;
          
          cout << endl << "New highest found at " << highest_pos << ", index: " << max_idx << endl;
          if ( highest_pos >= substr_end )
          {
            found = true;
            break;
          }
        }

      }
      else
        substr_pos = 0;

      n++;
    }

    if ( found == true )
      break;

    cout << '\r' << session.progress << "%              ";
  } while( buffer != "" );

  cout << endl << "Found substring match of length " << highest_pos << " at index " << max_idx << endl;

}

string pi_substring_get_input()
{
  string result;

  while ( true )
  {
    cout << "Enter a string of characters to find (numbers only): ";
    cin >> result;
    if ( result != "" )
      break;
  }

  return result;

}

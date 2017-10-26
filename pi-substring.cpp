#include <iostream>
#include <string>
#include "pi-io.h"
#include "pi-substring.h"

using namespace std;

void pi_substring(string in_file)
{
  pi_io session = pi_io_session(in_file);
  string search_str = pi_substring_get_input();

  int current_offset = 0, max_offset = search_str.length();
  unsigned long long longest_offset, longest_idx, n;

  //Read first n bytes.
  string buffer;
  do {
    buffer = pi_io_read(session);

    for ( int i=0; i<buffer.length(); i++ )
    {


      if ( search_str[current_offset] == buffer[i] )
      {
        current_offset += 1;
        if ( current_offset > longest_offset )
        {
          longest_offset = current_offset;
          longest_idx = n - current_offset;
          cout << "Found new longest match, " << longest_offset << " in length at index " << longest_idx << endl;
        }
      }
      else
      {
        if ( current_offset > 0 )
          current_offset = 0;
      }

      n++;
    }


    cout << session.progress << "%" << endl;
  } while( buffer != "" );


  cout << "Longest match, " << longest_offset << " in length at index " << longest_idx << endl;
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

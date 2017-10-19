#include <iostream>
#include <string>
#include "pi-io.h"
#include "pi-distribution.h"

using namespace std;

void pi_distribution(string in_file)
{
  pi_io session = pi_io_session(in_file);
  unsigned long long dist[255] = {0};

  //Read first n bytes.
  string buffer;
  do {
    buffer = pi_io_read(session);
    pi_count_digits(dist, buffer);
    cout << session.progress << "%" << endl;
  } while( buffer != "" );

  pi_output_distribution(dist);

}

void pi_count_digits(unsigned long long dist[255], const string &buffer)
{
  const char *buf = buffer.c_str();
  int ch;
  for ( unsigned long long n=0; n<buffer.length(); n++ )
  {
    dist[buf[n]] += 1;
  }
}

void pi_output_distribution(unsigned long long dist[255])
{
  for ( int n=48; n<58; ++n )
  {
    cout << pi_int_to_ascii(n) << ", " << dist[n] << endl;
  }
}

string pi_int_to_ascii(int n)
{
  string result = "N/A";
  switch (n)
  {
    case 48:
    result = "0";
    break;
    case 49:
    result = "1";
    break;
    case 50:
    result = "2";
    break;
    case 51:
    result = "3";
    break;
    case 52:
    result = "4";
    break;
    case 53:
    result = "5";
    break;
    case 54:
    result = "6";
    break;
    case 55:
    result = "7";
    break;
    case 56:
    result = "8";
    break;
    case 57:
    result = "9";
    break;
  }

  return result;
}

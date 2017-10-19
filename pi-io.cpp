#include <iostream>
#include <iomanip>
#include <fstream>
#include <sys/stat.h>

#include "pi-io.h"

#define IO_BUFFER_SIZE 273631;

using namespace std;

unsigned long long get_file_size(string filename)
{
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}

pi_io pi_io_session(string in_file)
{
  pi_io result;
  result.file_path = in_file;
  result.size = get_file_size(result.file_path);
  result.read_bytes = 0;
  result.bytes_per_read = IO_BUFFER_SIZE;

  return result;
}

string pi_io_read(pi_io &session)
{
  char data[session.bytes_per_read +1];
  unsigned long long diff;
  unsigned int read_n_bytes = session.bytes_per_read;

  if ( session.read_bytes >= session.size )
    return "";

  diff = session.size - session.read_bytes;
  if ( diff < session.bytes_per_read )
    read_n_bytes = diff;

  ifstream fh(session.file_path, ios::binary);
  fh.seekg(session.read_bytes);
  fh.read(data, read_n_bytes);
  data[session.bytes_per_read] = '\0';
  fh.close();

  session.read_bytes += read_n_bytes;
  session.progress = ( (double)session.read_bytes / (double)session.size ) * 100;

  return data;
}

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sys/stat.h>

using namespace std;

struct pi_io
{
  unsigned long long read_bytes;
  unsigned long long size;
  unsigned long long bytes_per_read;
  double progress;
  string file_path;
};

unsigned long long get_file_size(std::string filename);
pi_io pi_io_session(string in_file);
string pi_io_read(pi_io &session);

#ifndef TESTBENCH_H_
#define TESTBENCH_H_

#include <string>
#include <iostream>
#include <systemc>
#include "Initiator.h"
#include "filter_def.h"
//
#include "MemoryMap.h"
//
using namespace sc_core;
using namespace std;
using namespace sc_dt;

class Testbench : public sc_module
{
public:
  Initiator initiator;

  SC_HAS_PROCESS(Testbench);

  Testbench(sc_module_name n);
  ~Testbench() = default;

  int read_bmp(const char *fname_s);
  int write_bmp(const char *fname_t);

  unsigned int get_width() { return width; }

  unsigned int get_height() { return height; }

  unsigned int get_width_bytes() { return width_bytes; }

  unsigned int get_bytes_per_pixel() { return bytes_per_pixel; }

  unsigned char *get_source_image() { return source_bitmap; }
  unsigned char *get_target_image() { return target_bitmap; }

private:
  unsigned int input_rgb_raw_data_offset;
  const unsigned int output_rgb_raw_data_offset;
  int width = 0;
  int height = 0;
  unsigned int width_bytes;
  unsigned char bits_per_pixel;
  unsigned short bytes_per_pixel;
  unsigned char *source_bitmap;
  unsigned char *target_bitmap;

  void do_sobel();
  //void out();
};
#endif

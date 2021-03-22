#include <cmath>
#include<systemc>
#include "SobelFilter.h"


//int width = 0;               // image width
//int height = 0;              // image height


SobelFilter::SobelFilter(sc_module_name n) : sc_module(n) {
  SC_THREAD(do_filter);
  sensitive << i_clk.pos();
  dont_initialize();
  reset_signal_is(i_rst, false);
}

//Gaussian Blur
#define filterWidth 3     //mask_X
#define filterHeight 3    //mask_Y

double filter[filterHeight][filterWidth] =
{
  0.077847, 0.123317, 0.077847,
  0.123317, 0.195346, 0.123317,
  0.077847, 0.123317, 0.077847,
};

void SobelFilter::do_filter() {
  //{ wait(); }
  //while (true) {
    int x, y, v, u;        // for loop counter
    double R, G, B; // color of R, G, B
    double RR, GG, BB;
    //int height, width;
    //height = i_height.read();
    //width = i_width.read();

    for (y = 0; y != height; ++y) {
      for (x = 0; x != width; ++x) {
        R = G = B = 0;
        for (v = -1; v<filterHeight-1 ; ++v) {
          for (u = -1; u<filterWidth-1 ; ++u) {
            if (x + u >= 0 && x + u < width && y + v >= 0 && y + v < height) {
              wait();
              R += i_r.read() * filter[u+1][v+1];
              G += i_g.read() * filter[u+1][v+1];
              B += i_b.read() * filter[u+1][v+1];
            }

          }

        }
        //i_r.read(RR);
        //i_g.read(GG);
        //i_b.read(BB);
         
      }
    }
    
    //for (unsigned int v = 0; v < filterHeight; ++v) {
    //  for (unsigned int u = 0; u < filterWidth; ++u) {
        //unsigned char grey = (i_r.read() + i_g.read() + i_b.read()) / 3;
        //wait();
        //for (unsigned int i = 0; i != MASK_N; ++i) {
          //val[i] += grey * mask[i][u][v];

         // wait();
        //}
      //}
    //}
    //double total = 0;
    //for (unsigned int i = 0; i != MASK_N; ++i) {
    //  total += val[i] * val[i];
    //  wait();
    //}
    //int result = (int)(std::sqrt(total));
    //o_result.write(result);
  //}
  sc_stop();
}


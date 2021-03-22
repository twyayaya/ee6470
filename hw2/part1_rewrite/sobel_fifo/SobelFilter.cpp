#include <cmath>
#include<systemc>
#include "SobelFilter.h"
using namespace std ;


SobelFilter::SobelFilter(sc_module_name n) : sc_module(n) {
  SC_THREAD(do_filter);
  //sensitive << i_clk.pos();
  //dont_initialize();
  //reset_signal_is(i_rst, false);
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

    int x, y, v, u;        // for loop counter
    double R, G, B; // color of R, G, B
    cout<<"do filter start"<<endl;
    while(1){
    //for (y = 0; y != height; ++y) {
      cout<<"do filter Y start"<<endl;
      //for (x = 0; x != width; ++x) {
        R = G = B = 0;
        cout<<"do filter X start"<<endl;
        for (v = -1; v<filterHeight-1 ; ++v) {
          cout<<"do filter V start"<<endl;
          for (u = -1; u<filterWidth-1 ; ++u) {
            cout<<"do filter U start"<<endl;
            //if (x + u >= 0 && x + u < width && y + v >= 0 && y + v < height) {
              //wait();
              R += i_r.read() * filter[u+1][v+1];
              G += i_g.read() * filter[u+1][v+1];
              B += i_b.read() * filter[u+1][v+1];
              cout<<"sobelR="<<R<<endl;
            //}
          }
        }   
      //}
    o_r.write(R);
    o_g.write(G);
    o_b.write(B);
    }
    
    
    sc_stop();
}
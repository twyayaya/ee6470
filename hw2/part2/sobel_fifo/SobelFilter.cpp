#include <cmath>
#include<systemc>
#include "SobelFilter.h"
using namespace std ;


SobelFilter::SobelFilter(sc_module_name n) : sc_module(n) {
  SC_THREAD(do_filter);
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
    cout<<"DO"<<endl;
    int x, y, v, u,i,j;        // for loop counter
    double R, G, B; // color of R, G, B

    width = i_width.read();
    height = i_height.read();

    int r[3][width], g[3][width], b[3][width];


    //cout<<"R"<<endl;
    int c ;
    //cout<<"DO FILTER"<<endl;

    for(y = 0 ; y < height ; y++) {    
        if(y < height - 1){
            for(c = 0 ;c < width ; c++) { //reading
                r[2][c] = i_r.read();
                g[2][c] = i_g.read();
                b[2][c] = i_b.read();
                //cout<<"DO Y loop"<<endl;
            }
        }
        
        for(x = 0 ; x < width ; x++){
            R = G = B = 0;
            for (i = -1 ; i < filterHeight - 1 ; i++) {
                for (j = -1 ; j < filterWidth - 1 ; j++) {
                    //cout<<"filter j "<<endl;
                    if(0<=y+i && y+i<height && 0<=x+j && x+j<width){
                        R += r[i+1][x+j+1] * filter[i+1][j+1];
                        G += g[i+1][x+j+1] * filter[i+1][j+1];
                        B += b[i+1][x+j+1] * filter[i+1][j+1];
                        //cout<<"filter"<<endl;
                    }
                }
            }
            o_r.write(R);
            o_g.write(G);
            o_b.write(B);
            
        }
        for(x = 0 ;x < width ; x++) { //shifting
            r[0][x] = r[1][x];
            g[0][x] = g[1][x];
            b[0][x] = b[1][x];
            r[1][x] = r[2][x];
            g[1][x] = g[2][x];
            b[1][x] = b[2][x];
            r[2][x] = g[2][x] = b[2][x] = 0;
        }
        
    }
}
    
    /*
    for(cnt = 0 ;cnt < width ; cnt++){
        r[0][c] = g[0][c] = b[0][c] = 0;
        r[2][c] = g[2][c] = b[2][c] = 0;
        r[1][c] = i_r.read();
        g[1][c] = i_g.read();
        b[1][c] = i_b.read();
    }

    cout<<"do filter start"<<endl;
    while(1){
        for (v = -1; v<filterHeight-1 ; ++v) {
          for (u = -1; u<filterWidth-1 ; ++u) {
              R += i_r.read() * filter[u+1][v+1];
              G += i_g.read() * filter[u+1][v+1];
              B += i_b.read() * filter[u+1][v+1];
              cout<<"sobelR="<<R<<endl;
          }
        }   
    o_r.write(R);
    o_g.write(G);
    o_b.write(B);
    }
    sc_stop();
}
*/
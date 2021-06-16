#ifndef FILTER_DEF_H_
#define FILTER_DEF_H_

#define CLOCK_PERIOD 10

#define MAX_IMAGE_BUFFER_LENTH 1024

union word
{
  int sint;
  unsigned int uint;
  unsigned char uc[4];
};

// mask parameters
const int MASK_X = 3;
const int MASK_Y = 3;

// Filter inner transport addresses
// Used between blocking_transport() & do_filter()
//new sobel(gaussian)
#define filterWidth 3
#define filterHeight 3
double filter[filterHeight][filterWidth] =
    {
        1,
        2,
        1,
        2,
        4,
        2,
        1,
        2,
        1,
};
double factor = 1.0 / 16.0;
double bias = 0.0;
#endif

#ifndef FILTER_DEF_H_
#define FILTER_DEF_H_

// Sobel Filter inner transport addresses
// Used between blocking_transport() & do_filter()
const int SOBEL_FILTER_R_ADDR = 0x00000000;
const int SOBEL_FILTER_RESULT_ADDR = 0x00000004;

#endif

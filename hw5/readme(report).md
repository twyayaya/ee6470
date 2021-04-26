# Homework5 

##### 109061613 黃柏凱


## High level synthesis of Gaussian Blur
  大概就是把原本用scfifo的地方換成stratus HLS的方式傳送<br>
  用#ifndef來區別<br>
  part1是通道沒分開和lab6差不多,rbg<24>綁在一起傳送接收<br>
  part2則是把r<8>, g<8>, b<8>分開來傳送接收<br>
  檔案都放在stratus資料夾裡,所以run的動作都一樣<br>
  sim_B       : Run behavioral simulation<br>
  sim_V_BASIC : Run synthesis and Verilog simulation with HLS configuration BASIC<br>
  sim_V_DPA   : Run synthesis and Verilog simulation with HLS configuration DPA<br>
### Run 
```
cd stratus
make sim_B
make sim_V_BASIC
make sim_V_DPA
```
* 原圖結果:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw5/hw5_part2/stratus/lena.bmp)


* 修改後結果圖:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw5/hw5_part2/stratus/lena_hw5_part2_test1.bmp)

## 討論
**code的比較(以system.h為例)**<br>

*part1*
  ```c++
  #ifndef NATIVE_SYSTEMC
	  cynw_p2p<sc_dt::sc_uint<24> > rgb;
	  cynw_p2p<sc_dt::sc_uint<24> > result;
  #else
	  sc_fifo<sc_dt::sc_uint<24> > rgb;
	  sc_fifo<sc_dt::sc_uint<24> > result;
  #endif
  ```
*part2*
```c++
#ifndef NATIVE_SYSTEMC
	//cynw_p2p<sc_dt::sc_uint<24> > rgb;
	//cynw_p2p<sc_dt::sc_uint<24> > result;
	cynw_p2p<sc_dt::sc_uint<8> > r;
	cynw_p2p<sc_dt::sc_uint<8> > g;
	cynw_p2p<sc_dt::sc_uint<8> > b;
	cynw_p2p<sc_dt::sc_uint<8> > result_r;
	cynw_p2p<sc_dt::sc_uint<8> > result_g;
	cynw_p2p<sc_dt::sc_uint<8> > result_b;
#else
	//sc_fifo<sc_dt::sc_uint<24> > rgb;
	//sc_fifo<sc_dt::sc_uint<24> > result;
	sc_fifo<sc_dt::sc_uint<8> > r;
	sc_fifo<sc_dt::sc_uint<8> > g;
	sc_fifo<sc_dt::sc_uint<8> > b;
	sc_fifo<sc_dt::sc_uint<8> > result_r;
	sc_fifo<sc_dt::sc_uint<8> > result_g;
	sc_fifo<sc_dt::sc_uint<8> > result_b;
#endif
```

**time的比較**<br>

*part1*
```
sim_B:		Simulated time == 52428850 ns
sim_V_BASIC:	Simulation stopped via $stop(1) at time 76021815100 PS + 0
sim_V_DPA:	Simulation stopped via $stop(1) at time 76021815100 PS + 0
```
*part2*
```
sim_B:		Simulated time == 104857650 ns
sim_V_BASIC:	Simulation stopped via $stop(1) at time 128450615100 PS + 0
sim_V_DPA:	Simulation stopped via $stop(1) at time 128450615100 PS + 0
```

**Estimated Area的比較(SobelFilter)**<br>
1.part1
  1. sim_V_BASIC
```

        00803: | Allocation Report for all threads:                                        |
        00805: |                                               Area/Instance               |
        00805: |                                         ------------------------    Total |
        00805: |                        Resource  Count    Seq(#FF)    Comb    BB     Area |
        00805: | -------------------------------  -----  ----------  ------  ----  ------- |
        00811: | ------------------------------------------------------------------------- |
        00812: |                      Total Area         798.9(107)  1344.8   0.0   2143.7 |
               |                                                                           |
               +---------------------------------------------------------------------------+
```
  2. sim_V_DPA
```

        00803: | Allocation Report for all threads:                                        |
        00805: |                                               Area/Instance               |
        00805: |                                         ------------------------    Total |
        00805: |                        Resource  Count    Seq(#FF)    Comb    BB     Area |
        00805: | -------------------------------  -----  ----------  ------  ----  ------- |
        00811: | ------------------------------------------------------------------------- |
        00812: |                     Total Area         768.8(103)  1197.8   0.0   1966.6  |
               |                                                                           |
               +---------------------------------------------------------------------------+
```

2.part1
  1. sim_V_BASIC
```

        00803: | Allocation Report for all threads:                                        |
        00805: |                                               Area/Instance               |
        00805: |                                         ------------------------    Total |
        00805: |                        Resource  Count    Seq(#FF)    Comb    BB     Area |
        00805: | -------------------------------  -----  ----------  ------  ----  ------- |
        00811: | ------------------------------------------------------------------------- |
        00812: |                      Total Area         809.2(110)  1382.8   0.0   2192.0 |
               |                                                                           |
               +---------------------------------------------------------------------------+
```
  2. sim_V_DPA
```

        00803: | Allocation Report for all threads:                                        |
        00805: |                                               Area/Instance               |
        00805: |                                         ------------------------    Total |
        00805: |                        Resource  Count    Seq(#FF)    Comb    BB     Area |
        00805: | -------------------------------  -----  ----------  ------  ----  ------- |
        00811: | ------------------------------------------------------------------------- |
        00812: |                     Total Area         718.9(98)   1310.6   0.0   2029.5  |
               |                                                                           |
               +---------------------------------------------------------------------------+
```
## 問題討論
1. 

## 參考網站
1.[Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/filtering.html#Gaussian_Blur_)<br>
2.EE6470課程網站<br>


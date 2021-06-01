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

2.part2
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
**RTL Summary and Tree Map**<br>

  1.part1, RTL Summary, BASIC
  
   ![](https://github.com/twyayaya/ee6470/blob/master/hw5/hw5_part1_basic_1.jpg)
  
  2.part1, Tree Map, BASIC
  
  ![](https://github.com/twyayaya/ee6470/blob/master/hw5/hw5_part1_basic_2.jpg)
  
  3.part1, RTL Summary, DPA
  
  ![](https://github.com/twyayaya/ee6470/blob/master/hw5/hw5_part1_dpa_1.jpg)
  
  4.part1, Tree Map, DPA
  
  ![](https://github.com/twyayaya/ee6470/blob/master/hw5/hw5_part1_dpa_2.jpg)
  
  5.part2, RTL Summary, BASIC
  
   ![](https://github.com/twyayaya/ee6470/blob/master/hw5/hw5_part2_basic_1.jpg)
  
  6.part2, Tree Map, BASIC
  
  ![](https://github.com/twyayaya/ee6470/blob/master/hw5/hw5_part2_basic_2.jpg)
  
  7.part2, RTL Summary, DPA
  
  ![](https://github.com/twyayaya/ee6470/blob/master/hw5/hw5_part2_dpa_1.jpg)
  
  8.part2, Tree Map, DPA
  
  ![](https://github.com/twyayaya/ee6470/blob/master/hw5/hw5_part2_dpa_2.jpg)  


## 問題討論
1. 可以看到的是把rbg綁在一起所花費得時間比r,g,b分開來還快很多
2. Area的部分則是DPA較BASIC小,par1的area和part2相比,part1的area較好
3. 在剛開始跑sim_B時沒發生問題,但如果要跑sim_V_BASIC或DPA時就會發生以下狀況
   1. **non-const**<br>
   	![](https://github.com/twyayaya/ee6470/blob/master/hw5/nospilt_sim_V_BASIC.jpg)
	在SobelFilrer.cpp裡沒有把filter[filterHeight][filterWidth]前面加const就會出現這ERROR<br>
	解決方法 : int filter[filterHeight][filterWidth] -> const int filter[filterHeight][filterWidth]<br>
	
   2. **Unexpected kind if initial value for**<br>
	![](https://github.com/twyayaya/ee6470/blob/master/hw5/nospilt_sim_V_BASIC2.jpg)
	在SobelFilrer.cpp裡,我原本的filter裡面都是小數點,這樣就不用再最後除個f(factor),但好像就是因為用小數點,所以會出現這ERROR<br>
	解決方法 : 就是把filter裡面改成整數,最後在除個f(factor)<br>

4. 還有一個問題我不知道是為什麼會出現這個,但好像也沒什麼影響
   ![](https://github.com/twyayaya/ee6470/blob/master/hw5/hw5_nouse.jpg)


## 參考網站
1.[Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/filtering.html#Gaussian_Blur_)<br>
2.EE6470課程網站<br>


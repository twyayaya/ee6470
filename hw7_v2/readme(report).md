# Homework7 

##### 109061613 黃柏凱


##  Data Partitioning of the Gaussian Blur Processing
  使用hw6和lab8其中兩個有用到多核(tiny32-mc)的小lab<br>
  
  

  
### Run 
```
cd build
make
make sim
```

* 結果:<br>
* 2 core
    ![](https://github.com/twyayaya/ee6470/blob/master/hw7_v2/hw7_1.jpg)<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw7_v2/hw7_2.jpg)<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw7_v2/hw7_3.jpg)<br>
* 1 core
    ![](https://github.com/twyayaya/ee6470/blob/master/hw6_test/hw6_2.jpg)<br>


## 討論
  改變platform/main.cpp和hw6/build/main.cpp<br>
  重點應該是把原本core0改成有core0 core1,然後接好<br>
  看起來其實速度相差不多,但仔細算 1core和2core的時間想比,1core還是比較快一點<br>
  
  
  
## 問題
  可能是因為使用2core 所以剛開始那邊會重疊
  應該蠻好調整的吧?
  ![](https://github.com/twyayaya/ee6470/blob/master/hw7_v2/hw7_1.jpg)<br>


## 參考網站
1.[Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/filtering.html#Gaussian_Blur_)<br>
2.EE6470課程網站<br>


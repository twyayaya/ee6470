# Homework7 

##### 109061613 黃柏凱


##  Data Partitioning of the Gaussian Blur Processing
  使用hw6和lab8其中兩個有用到多核(tiny32-mc)的小lab<br>
  其中的id是讓我看目前是在用哪個core(core0 or core1)<br>
  然後因為是寬度對半切,原圖是256*256,所以兩core各算128<br>
  那個p就是紀錄現在算到寬度的哪,當算到寬度為128時會結束<br>
  此次用到的是bin/tiny32-mc
  
  

  
### Run 
```
cd build
make
make sim
```

* 結果:<br>
* 2 core<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw7_test/hw7_test_1.jpg)<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw7_test/hw7_test_2.jpg)<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw7_test/hw7_test_3.jpg)<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw7_test/hw7_test_4.jpg)<br>
    
* 1 core<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw6_test/hw6_2.jpg)<br>


## 討論
  改變platform/main.cpp和hw6/build/main.cpp<br>
  重點應該是把原本core0改成有core0 core1,然後接好<br>
  看起來其實速度相差不多,但仔細算 1core和2core的時間想比,1core還是比較快一點<br>
  
  
  
## 問題
  可能是因為使用2core 所以剛開始那邊會重疊
  應該蠻好調整的吧?
  ![](https://github.com/twyayaya/ee6470/blob/master/hw7_test/hw7_test_1.jpg)<br>


## 參考網站
1.[Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/filtering.html#Gaussian_Blur_)<br>
2.EE6470課程網站<br>


# Homework7 

##### 109061613 黃柏凱


##  Data Partitioning of the Gaussian Blur Processing
  使用hw6和lab8其中兩個有用到多核(tiny32-mc)的小lab<br>
  不過目前不知道為什麼只能跑到一半,寬度為256但build/main.cpp的for loop只能跑到128<br>
  剩下那一半跑不瞭,可能是platform連接有誤,還在找bug<br>
  
# 以下是hw6的,待改
  
### Run 
```
cd build
make
make sim
```

* 結果:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw6_test/hw6_1.jpg)<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw6_test/hw6_2.jpg)<br>



## 討論
  因為從這結果圖來看的話只能知道最後那32個reg最後存了什麼,所以原本想法是<br>
  step1. 用以前的hw把圖模糊化<br>
    原圖:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw6_test/build/lena_std_short.bmp)<br>
    模糊過後:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw6_test/lena_std_short_for_hw6.bmp)<br>
    
  step2. 再把模糊過後的圖拿去生成bitmap(lena_std_short_for_hw6.h)<br>
  
  step3. 用lena_std_short_for_hw6.h和這次作業生出來的數字進行比對<br>
  
  
## 問題
  我在main.cpp裡面增加了以下的code來比較輸入和輸出是否為一樣的.h檔,但都是失敗了<br>
  檔案在step3_file裡,然後因為多了這幾段,模擬時間增加許多,reg最終所留下來的數值也有所改變<br>
  
    //new
    #include "lena_std_short_for_hw6_v2.h"
    //new
    ...
    ...
    //new
      //unsigned char lena_std_short_for_hw6_bmp[] = {}
      unsigned char R = lena_std_short_for_hw6_v2_bmp[bytes_per_pixel * (j * width + i) + 2];
      unsigned char G = lena_std_short_for_hw6_v2_bmp[bytes_per_pixel * (j * width + i) + 1];
      unsigned char B = lena_std_short_for_hw6_v2_bmp[bytes_per_pixel * (j * width + i) + 0];

      if (R != buffer[0])
      {
        printf("0 "); //R error
      }
      if (G != buffer[1])
      {
        printf("1 "); //G error
      }
      if (B != buffer[2])
      {
        printf("2 "); //B error
      }
      //new
      }
    }
    printf("if no 012 then !!correct!!");
    }
  
  ![](https://github.com/twyayaya/ee6470/blob/master/hw6_test/step3.jpg)<br>


## 參考網站
1.[Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/filtering.html#Gaussian_Blur_)<br>
2.EE6470課程網站<br>


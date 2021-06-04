# Homework6 

##### 109061613 黃柏凱


##  Cross-compile Gaussian Blur to RISC-V VP platform
  使用lab8的 sobel filter來改
  然後把原本的o_result改成o_r, o_g, o_b, 因為根據之前的看法拆成這樣速度比較快一點
  
### Run 
```
cd build
make
make sim
```

* 結果:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw5/hw5_part2/stratus/lena.bmp)




## 討論
  因為從這結果圖來看的話只能知道最後那32個reg最後存了什麼,所以原本想法是
  step1. 用以前的hw把圖模糊化
  step2. 再把模糊過後的圖拿去生成bitmap(A)
  step3. 用A和這次作業生出來的數字進行比對
  不過我在step2就遇到問題了,我是使用lab8的File byte array這part,因為riscv-vp不能直接輸出,所以我想說直接用複製print出來的值,再另外存成.h檔案
  不過它print出來的值太多,一次無法複製完,大概會缺少一半所以現在還在想其他方法.


## 參考網站
1.[Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/filtering.html#Gaussian_Blur_)<br>
2.EE6470課程網站<br>


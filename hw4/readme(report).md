# Homework4 

##### 109061613 黃柏凱


## Gaussian Blur with a TLM-2.0 interconnect
    基本上就是lab4為基礎然後和HW3做混和,但需要小心的是別複製錯
    最大的改動應該就是把原本在testbench.cpp裡面的out()裡面的程式碼給放到do_sobel()裡,就不需要額外寫一個void了,
    其他就跟之前或lab4差不多,lab4有些檔案甚至直接拿來用
### Run 
```
cd build
./sobel
```
* 原圖結果:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/HW3/build/lena.bmp)


* 修改後結果圖:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/HW3/build/lena_hw3.bmp)
    ![](https://github.com/twyayaya/ee6470/blob/master/hw4/hw4_result.jpg)


## 問題討論
1. 作業基本上就是上次作業HW3和lab4的混合版而已,一些地方注意修改就好了,別copy錯就好

## 參考網站
1.[Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/filtering.html#Gaussian_Blur_)<br>
2.EE6470課程網站<br>


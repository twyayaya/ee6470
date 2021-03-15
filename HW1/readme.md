# Homework1
##### 109061613 黃柏凱


## part1 : Gaussian Blur(C/C++)
    把範例還有提共網頁給的sobel kernel換成Gaussian Blur的kernel
* 原始圖片:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/HW1/part1/lena.bmp)
* sobel後的圖片:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/HW1/part1/lena_sobel.bmp)
* Gaussian Blur後的圖片:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/HW1/part1/lena_blurTest22.bmp)

## part2 : Gaussian Blur(systemC)
    我是把lab2的A Sobel Filter with FIFO interface改寫成Gaussian Blur版本的
* 原始圖片:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/HW1/part2/build/lena.bmp)
* Gaussian Blur後的圖片:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/HW1/part2/build/lena_systemCout33.bmp)
* Simulated time:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/HW1/part2/part2_.jpg)
    
## 問題與討論
1.因為時間因素,目前還沒把part2的一些C/C++的datatype修改成systemC的datatype<br>
2.因為時間因素,code上面一堆//沒刪除,看起來很亂<br>
3.我的想法是part2裡的sobelfilter只負責做convolution的;testbench則是負責input,output的部分<br>

## 參考網站
1.[Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/filtering.html#Gaussian_Blur_)<br>
2.EE6470課程網站<br>


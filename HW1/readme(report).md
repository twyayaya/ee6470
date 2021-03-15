# Homework1
##### 109061613 黃柏凱


## part1 : Gaussian Blur(C/C++)
    把範例還有提共網頁給的sobel kernel換成Gaussian Blur的kernel
    因為使用舊檔案,所以檔案名稱幾乎沒做更動
### Run 
    ```
    ./sobel
    ```
* 原始圖片:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/HW1/part1/lena.bmp)
* sobel後的圖片:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/HW1/part1/lena_sobel.bmp)
* Gaussian Blur後的圖片:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/HW1/part1/lena_blurTest22.bmp)

## part2 : Gaussian Blur(systemC)
    我是把lab2的A Sobel Filter with FIFO interface改寫成Gaussian Blur版本的
    因為使用舊檔案,所以檔案名稱幾乎沒做更動,架構也不會差太多
### Run
    ```
    cd build
    ./sobel
    ```
* 架構圖片(lab2的):<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/HW1/part2/hw1_part2_ar.jpg)
* 原始圖片:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/HW1/part2/build/lena.bmp)
* Gaussian Blur後的圖片:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/HW1/part2/build/lena_systemCout33.bmp)
* Simulated time:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/HW1/part2/part2_.jpg)
    
## 問題與討論
1.因為時間的關係,目前還沒完全把part2的一些C/C++的datatype修改成systemC的datatype<br>
2.我的想法是part2裡的sobelfilter只負責做convolution的;testbench則是負責input,output的部分<br>
3.可以看到part1和part2的sobel圖的左側有些差異,part1圖中的右側跑去最左邊了,這個可能看一下lab2的code把part1的換一下就能解決

## 參考網站
1.[Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/filtering.html#Gaussian_Blur_)<br>
2.EE6470課程網站<br>


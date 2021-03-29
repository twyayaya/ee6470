# Homework2

##### 109061613 黃柏凱


## part1 : Please implement a Gaussian blur filter with SystemC modules connected with SystemC FIFO channels.
    沿用HW1的code然後加入"cout pixels"來顯示計算pixels
### Run 
```
./sobel
```
* 計算結果:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw2/old_pixels_send_pic.jpg)

#### 問題
    有時候會程式會執行錯誤,輸出圖片結果是黑色的,但還是有計算pixels,可能和part2有關
    
##### part1 : rewrite
    我試著重新順過part1的code,但我看pixels數字還是沒什麼太大改變
    把pixel_number +=3;改成pixel_number +=9;後,數字明顯變大
    
* 計算結果:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw2/part1_rewrite/part1_rewrite_plus9.jpg)

## part2 : Please rewrite the parts related to pixel transfer at Input and Calculation processes.【有問題待解決】
    會出現"Segmentation fault"
    目前想法可能是重新寫整個code
    #
    可能是filter的int rgb 那邊有問題  3/23 07:32
    能跑,但還需要修改 3/23 07:52
    

* 目前修改結果:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw2/part2/hw2_part2.jpg)

## 問題討論
1. pixels數字差不多,照理來講part2的數字要較少,應該要很明顯
2. part1改成+9,也就是conv一次run 3*3後數字應該是會和part2相差九倍()

## 參考網站
1.[Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/filtering.html#Gaussian_Blur_)<br>
2.EE6470課程網站<br>


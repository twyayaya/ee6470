# Homework1
##### 109061613 黃柏凱


## part1 : Please implement a Gaussian blur filter with SystemC modules connected with SystemC FIFO channels.
    沿用HW1的code然後加入"cout pixels"來顯示計算pixels
### Run 
```
./sobel
```
* 計算結果:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw2/old_pixels_send_pic.jpg)

####問題
    有時候會程式會執行錯誤,輸出圖片結果是黑色的,但還是有計算pixels,可能和part2有關

## part2 : Please rewrite the parts related to pixel transfer at Input and Calculation processes.【有問題待解決】
    一直出現"Segmentation fault"
    目前想法可能是重新寫整個code
    


## 參考網站
1.[Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/filtering.html#Gaussian_Blur_)<br>
2.EE6470課程網站<br>

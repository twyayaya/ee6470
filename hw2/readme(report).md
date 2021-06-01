# Homework2

##### 109061613 黃柏凱


## part1 : Please implement a Gaussian blur filter with SystemC modules connected with SystemC FIFO channels.
    沿用HW1的code然後加入"cout pixels"來顯示計算pixels
### Run 
```
./sobel
```
* 舊的計算結果,新的在下面:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw2/old_pixels_send_pic.jpg)

    
##### part1 : rewrite
    把pixel_number +=9;改成pixel_number +=3;換到171行
    2021/06/02
    
* 舊的計算結果,新的在下面:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw2/part1_rewrite/part1_rewrite_plus9.jpg)

## part2 : Please rewrite the parts related to pixel transfer at Input and Calculation processes.
    part1的就只是單純3*3讀取pixel,會有很大部分重複送
    part2則不會,只會讀取新的一列
   ![](https://github.com/twyayaya/ee6470/blob/master/hw2/hw2_neww.jpg)

    2021/06/02
    

* 目前修改結果比較(2021/06/02):<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw2/hw2_new_pic.jpg)

## 問題討論
1. pixels數字差不多,照理來講part2的數字要較少,應該要很明顯
2. 相差快10倍(2021/06/02)

## 參考網站
1.[Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/filtering.html#Gaussian_Blur_)<br>
2.EE6470課程網站<br>


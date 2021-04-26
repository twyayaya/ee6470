# Homework5 

##### 109061613 黃柏凱


## High level synthesis of Gaussian Blur
  大概就是把原本用scfifo的地方換成stratus HLS的方式傳送<br>
  用#ifndef來區別<br>
  part1是通道沒分開和lab6差不多,rbg<24>綁在一起傳送接收<br>
  part2則是把r<8>, g<8>, b<8>分開來傳送接收<br>
  檔案都放在stratus資料夾裡,所以run的動作都一樣<br>
  
### Run 
```
cd stratus
make sim_B
make sim_V_BASIC
make sim_V_DPA
```
* 原圖結果:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw5/hw5_part2/stratus/lena.bmp)


* 修改後結果圖:<br>
    ![](https://github.com/twyayaya/ee6470/blob/master/hw5/hw5_part2/stratus/lena_hw5_part2_test1.bmp)

## 討論
*part1
*part2

## 問題討論
1. 

## 參考網站
1.[Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/filtering.html#Gaussian_Blur_)<br>
2.EE6470課程網站<br>


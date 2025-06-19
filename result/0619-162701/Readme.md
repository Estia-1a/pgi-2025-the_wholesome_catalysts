# Daily Evaluation 19/06 - 16:27:01
You can find below how you did for each feature. 
 You should merge the pull request to keep the eval and automatically close and open the issues you have finished!
# Milestone  Tutorial
Score : 20/23 :  86%
## Detail by Feature
| Feature     | Score       | Missed tests                                                                              | Stdout                            |
| :---------- | :---------- | :---------------------------------------------------------------------------------------- | :-------------------------------- |
| dimension   | 4/4 :  100% |                                                                                           |                                   |
| first_pixel | 5/5 :  100% |                                                                                           |                                   |
| tenth_pixel | 5/5 :  100% |                                                                                           |                                   |
| second_line | 5/5 :  100% |                                                                                           |                                   |
| print_pixel | 1/4 :  25%  | Print Pixel (2,3) : 20,30,26<br>Print Pixel (3,2) : 30,20,19<br>Print Pixel (7,7) : 0,0,0 | print_pixel (2, 3): 0, 40, 32<br… |

# Milestone  statistiques
Score : 26/26 :  100%
## Detail by Feature
| Feature         | Score       | Missed tests | Stdout |
| :-------------- | :---------- | :----------- | :----- |
| max_pixel       | 4/4 :  100% |              |        |
| min_pixel       | 4/4 :  100% |              |        |
| min_component R | 3/3 :  100% |              |        |
| min_component G | 3/3 :  100% |              |        |
| min_component B | 3/3 :  100% |              |        |
| max_component R | 3/3 :  100% |              |        |
| max_component G | 3/3 :  100% |              |        |
| max_component B | 3/3 :  100% |              |        |

# Milestone  colors
Score : 25/35 :  71%
## Detail by Feature
| Feature              | Score       | Missed tests                                                                                                                                         | Stdout           |
| :------------------- | :---------- | :--------------------------------------------------------------------------------------------------------------------------------------------------- | :--------------- |
| color_red            | 5/5 :  100% |                                                                                                                                                      |                  |
| color_blue           | 5/5 :  100% |                                                                                                                                                      |                  |
| color_green          | 5/5 :  100% |                                                                                                                                                      |                  |
| color_gray           | 5/5 :  100% |                                                                                                                                                      |                  |
| color_invert         | 0/5 :  0%   | Invert red image<br>Invert blue image<br>Invert green Image<br>Invert white Image<br>Invert black Image                                              | <br><br><br><br> |
| color_gray_luminance | 5/5 :  100% |                                                                                                                                                      |                  |
| color_desaturate     | 0/5 :  0%   | Convert red image to GRAY<br>Convert blue image to GRAY<br>Convert green Image to GRAY<br>Convert white Image to GRAY<br>convert black Image to GRAY | <br><br><br><br> |

# Milestone  transform
Score : 11.68/15 :  77%
## Detail by Feature
| Feature           | Score         | Missed tests                              | Stdout                            |
| :---------------- | :------------ | :---------------------------------------- | :-------------------------------- |
| rotate_cw         | 3/3 :  100%   |                                           |                                   |
| rotate_acw        | 1.34/3 :  44% | rotate square image<br>rotate large image | Image rotated 90° clockwise and … |
| mirror_horizontal | 3/3 :  100%   |                                           |                                   |
| mirror_vertical   | 1.34/3 :  44% | mirror square image<br>mirror high image  | <br>                              |
| mirror_total      | 3/3 :  100%   |                                           |                                   |

# Milestone  resize
Score : 0/60 :  0%
## Detail by Feature
| Feature        | Score      | Missed tests                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           | Stdout                            |
| :------------- | :--------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------- |
| scale_nearest  | 0/20 :  0% | scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3                                                                                 | <br><br><br><br><br><br><br><br>… |
| scale_bilinear | 0/20 :  0% | scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12                               | <br><br><br><br><br><br><br><br>… |
| scale_crop     | 0/20 :  0% | scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10 | Image cropped around (0, 0) to 1… |


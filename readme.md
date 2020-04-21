# **软件工程第四次作业**

小学四则运算自动生成程序，要求：

- 能够自动生成四则运算练习题

- 可以定制题目数量

- 用户可以选择运算符

- 用户设置最大数（如十以内、百以内等）

- 用户选择是否有括号、是否有小数

- 用户选择输出方式（如输出到文件、打印机等）

- 最好能提供图形用户界面（根据自己能力选做，以完成上述功能为主）

  

思路：

​	前端：H5（可能实现）

​	程序以c++为主，不封装

​	如果说不用前段的话直接用数字判断输入的状态即可，需要判断的内容有是否继续（0退出1整数2小数），题目的数量（N），选择运算符（一个size==4的数组，开始全至1，询问输入的数字，），判断是否有括号（1,0），判断最大数（10,100），判断输出方式（0公屏打印，1txt输出）

​	随机数生成->1~4加减乘除、%100 or %10、小数*0.01、

​	
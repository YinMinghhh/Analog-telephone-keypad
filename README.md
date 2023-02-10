# Analog telephone keypad
- 河海大学 2020级 通信微机原理与接口 课程设计  
- 作者 : 朱星宇  
- 时间 : 2023年初  
- 基于 普中A5 开发板  

|设备       |信息       |
|:----:     |:----:     |
|CPU        |STC89C51RC |
|language   |C          |
|software   |keil C51   |

---  
## 题目三
    把
    S207、S206、S205；
    S217、S216、S215；
    S227、S226、S225；
    S237、S236、S235；按键分别当作电话按键的 123456789*0#。当拨打电话时，电话号
    码显示在动态 LED 上（相当于手机的显示屏）。当按下 S204 键 Call 电话时，电话号码通过
    串口发送到 PC 上，通过串口调试助手可以观察。（相当于把号码发给基站）
    提示：掌握动态 led 显示和逐行扫描键盘原理。
    提高：模拟电话不通时，每隔 1 分钟自动重拨一次。
    其他：自行发挥，表现自己对题目的理解和完善。  

## 矩阵键盘配置
|   |P14-列1|P15-列2|P16-列3|P17-列4|
|:-:|:-:|:-:|:-:|:-:|
|P10-行1|1  |2  |3  |拨号   |
|P11-行2|4  |5  |6  |挂断   |
|P12-行3|7  |8  |9  |退格   |
|P13-行4|*  |0  |#  |重拨   |

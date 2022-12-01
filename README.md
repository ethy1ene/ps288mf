# PS288MF

A simple Arduino-based PS/2 to PC-8801F/M keyboard adapter.

PC-8801FH以降用のPS2キーボードアダプター 

Need PS2keyAdvanced library.

# Default pinout

|PS/2 keyboard|Arduino|PC-8801 host|
|:-----------:|:-----:| :---------:|
|+5v|+5v|+5v|
|   |D6|Rx|
|DATA|D4||
|CLK|D3||
|GND|GND|GND|

PC-88MA side pinout:

![avatar](http://www.maroon.dti.ne.jp/youkan/pc88/kbd2.gif)

# Keymap

![avatar](https://pbs.twimg.com/media/Fi4tBBcVQAAHEnP?format=png&name=900x900)

# Usage

Just buy a Arduino Nano, upload the codes, connect the cables as above. :)

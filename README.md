# PS288MF

A simple Arduino-based PS/2 to PC-8801M/F keyboard adapter.

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

# Usage

Just buy a Arduino Nano, upload the codes, connect the cables as above. :)

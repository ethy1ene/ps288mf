#include <avr/io.h>         //avr library for timer
#include <avr/interrupt.h>
#include <PS2KeyAdvanced.h> 
#define TXPIN 6             //pc88keyboard tx pin
#define DATAPIN 4           //ps2 data pin
#define IRQPIN  3           //ps2 clock pin
PS2KeyAdvanced keyboard;
uint16_t c;
unsigned int buff=0;
const unsigned int K[120]={0xFFC0, 0xFFA0, 0xFF60, 0xFEE0, 0xFDE0, 0xFBE0, 0xF7E0, 0xEFE0,
                           0xDFC2, 0xDFA2, 0xDF62, 0xDEE2, 0xDDE2, 0xDBE2, 0xD7E2, 0xCFE2,
                           0xDFC4, 0xDFA4, 0xDF64, 0xDEE4, 0xDDE4, 0xDBE4, 0xD7E4, 0xCFE4,
                           0xFFC6, 0xFFA6, 0xFF66, 0xFEE6, 0xFDE6, 0xFBE6, 0xF7E6, 0xEFE6,
                           0xDFC8, 0xDFA8, 0xDF68, 0xDEE8, 0xDDE8, 0xDBE8, 0xD7E8, 0xCFE8,
                           0xFFCA, 0xFFAA, 0xFF6A, 0xFEEA, 0xFDEA, 0xFBEA, 0xF7EA, 0xEFEA,
                           0xFFCC, 0xFFAC, 0xFF6C, 0xFEEC, 0xFDEC, 0xFBEC, 0xF7EC, 0xEFEC,
                           0xDFCE, 0xDFAE, 0xDF6E, 0xDEEE, 0xDDEE, 0xDBEE, 0xD7EE, 0xCFEE,
                           0xDFD0, 0xDFB0, 0xDF70, 0xDEF0, 0xDDF0, 0xDBF0, 0xD7F0, 0xCFF0,
                           0xFFD2, 0xFFB2, 0xFF72, 0xFEF2, 0xFDF2, 0xFBF2, 0xF7F2, 0xEFF2,
                           0xFFD4, 0xFFB4, 0xFF74, 0xFEF4, 0xFDF4, 0xFBF4, 0xF7F4, 0xEFF4,
                           0xDFD6, 0xDFB6, 0xDF76, 0xDEF6, 0xDDF6, 0xDBF6, 0xD7F6, 0xCFF6,
                           0xFFD8, 0xFFB8, 0xFF78, 0xFEF8, 0xFDF8, 0xFBF8, 0xF7F8, 0xEFF8,
                           0xDFDA, 0xDFBA, 0xDF7A, 0xDEFA, 0xDDFA, 0xDBFA, 0xD7FA, 0xCFFA,
                           0xDFDC, 0xDFBC, 0xDF7C, 0xDEFC, 0xDDFC, 0xDBFC, 0xD7FC, 0xCFFC};   //pc88 code array
                           
const unsigned int KO[120]={0x30,  0x31,  0x32,  0x33,  0x34,  0x35,  0x36,  0x37,
                            0x38,  0x39,  0x2E,  0x2C,  0x5F,  0x3B,  0x3D,  0x11E,
                            0x2F,  0x41,  0x42,  0x43,  0x44,  0x45,  0x46,  0x47,
                            0x48,  0x49,  0x4A,  0x4B,  0x4C,  0x4D,  0x4E,  0x4F,
                            0x50,  0x51,  0x52,  0x53,  0x54,  0x55,  0x56,  0x57,
                            0x58,  0x59,  0x5A,  0x5D,  0x5C,  0x5E,  0x16C,  0x3C,
                            0x20,  0x21,  0x22,  0x23,  0x24,  0x25,  0x26,  0x27,
                            0x28,  0x29,  0x3A,  0x5B,  0x3B,  0x3D,  0x3E,  0x2D,
                            0x111, 0x117, 0x116, 0x104, 0x90A, 0x2109, 0x4106,  0x2108,
                            0x16B, 0x161, 0x162, 0x163, 0x164, 0x165, 0x11F, 0x11B,
                            0x11D, 0x118, 0x115, 0x30D, 0x10E, 0x3C,  0x3E,  0x1103,
                            0x113, 0x114, 0x30,  0x30,  0x30,  0x30,  0x30,  0x30,
                            0x166, 0x167, 0x168, 0x169, 0x16A, 0x11C, 0x119, 0x11A,
                            0x30C, 0x50B, 0x112, 0x40,  0x30,  0x30,  0x30,  0x30,
                            0x11E, 0x2B,  0x4106,  0x4107,  0x30,  0x30,  0x30,  0x30};       //ps2 code array

const unsigned int BRK[15]={0xDFE0, 0xFFE2 ,0xFFE4 ,0xDFE6 ,0xFFE8 ,0xDFEA ,0xDFEC ,0xFFEE ,
                            0xFFF0, 0xDFF2, 0xDFF4, 0xFFF6, 0xDFF8, 0xFFFA, 0xFFFC};                 //break code array
char a=0,p=0,q=0;
bool brkflag=0;
void SENDKEY(int bitvar)       //key sending func
{
  a=0;
  buff=bitvar;  //load keycode
  TCCR1A = 0;  // set Timer register to 0
  TCCR1B = 0;  
  OCR1A = 763;                          // 768 in theory,acutually 763 is the best
  TCCR1B |= (1 << WGM12);               // turn on CTC mode: 
  TIMSK1 |= (1 << OCIE1A);              // enable timer compare interrupt:
  TCCR1B |= (1 << CS10);                // Set  mode  
  while(a<15)                           //wait the sending finish
  {
    digitalWrite(LED_BUILTIN, HIGH);    //light up the LED when sending
    digitalWrite(LED_BUILTIN, LOW);
 
  }
  TCCR1B &= ~(1 << CS10);    //stop the timer clock
  TIMSK1 &= ~(1 << OCIE1A);  //stop the timer interrupt
  delay(36);                 //slightly high input latency when fast typing,
                             //but codes with the same row number must be sent after 35ms , dont know why
}

ISR(TIMER1_COMPA_vect) //ISR func
{ 
  
    digitalWrite(TXPIN,bitRead(buff,a));//send 1bit
    a++;
  
}



void setup() {
  keyboard.begin( DATAPIN, IRQPIN );  //PS2Keyboard service
  pinMode(TXPIN,OUTPUT);              //Tx pin init
  digitalWrite(TXPIN, HIGH);
  SENDKEY(BRK[0]);                    //reset fix freezing
  SENDKEY(BRK[1]);
  SENDKEY(BRK[2]);
  SENDKEY(BRK[3]);
  SENDKEY(BRK[4]);
  SENDKEY(BRK[5]);
  SENDKEY(BRK[6]);
  SENDKEY(BRK[7]);
  SENDKEY(BRK[8]);
  SENDKEY(BRK[9]);
  SENDKEY(BRK[10]);
  SENDKEY(BRK[11]);
  SENDKEY(BRK[12]);
  SENDKEY(BRK[13]);
  SENDKEY(BRK[14]);
}


void loop() {

  if( keyboard.available() )              //read when buffer available
  {
    c=keyboard.read();                    //read next code
    brkflag=bitRead(c,15);                //break code or not
    switch (brkflag)
    {
    case 0:                               //make code
    for (p=0;p<120;p++)
     {
      if ((c&0x00ff)==(KO[p]&0x00ff))     //code compare
      {
        if(p==102)                        //extend keys INS
        {
          SENDKEY(K[102]);
          SENDKEY(K[70]);
          SENDKEY(K[67]);
        }
        else if (p<101&&p>95)             //extend keys F6-F10
        {
          SENDKEY(K[p]);
          SENDKEY(K[70]);
          SENDKEY(K[p-23]);
        }
        else if (p==101||p==103)          //extend keys BS DEL
        {
          SENDKEY(K[p]);
          SENDKEY(K[67]);
        }
        else if (p==104||p==105)          //extend keys HENKAN KETTEI
        {
          SENDKEY(K[p]);
          SENDKEY(K[78]);
        }
        else if (p==112||p==113)          //extend keys RETURN RETURN(NUMPAD)
        {
          SENDKEY(K[p]);
          SENDKEY(K[15]);
        }
        else if (p==114||p==115)          //extend keys LSHIFT RSHIFT
        {
          SENDKEY(K[p]);
          SENDKEY(K[70]);
        }
        else 
        SENDKEY(K[p]);                    //normal keys
        break;
        }
     }
     break;
     case 1:                              //break code
     for (p=0;p<120;p++)
     {
      if ((c&0x00ff)==(KO[p]&0x00ff))     //same as make
      {
        if(p==102)
        {
          SENDKEY(BRK[12]);
          SENDKEY(BRK[8]);
          SENDKEY(BRK[8]);
        }
        else if (p<101&&p>95)
        {
          SENDKEY(BRK[12]);
          SENDKEY(BRK[9]);
          SENDKEY(BRK[8]);
        } 
        else if (p==101||p==103)
        {
          SENDKEY(BRK[12]);
          SENDKEY(BRK[8]);
        }
        else if (p==104||p==105)
        {
          SENDKEY(BRK[13]);
          SENDKEY(BRK[9]);
        }
        else if (p==112||p==113)
        {
          SENDKEY(BRK[14]);
          SENDKEY(BRK[1]);
        }
        else if (p==114||p==115)
        {
          SENDKEY(BRK[14]);
          SENDKEY(BRK[8]);
        }
        else
        SENDKEY(BRK[p/8]);
        break;
        }
     }
    }
  }

  
}





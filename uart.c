#include"uart.h"
#include<msp430.h>
void bt_str(char *str){
    unsigned int i=0;
    while(str[i]!='\0'){
        bt_char(str[i++]);
    }
}
void bt_char(char c){
    while((UCA0IFG&UCTXIFG)==0);
    UCA0TXBUF =c;
}
void led_VM(){
    P1OUT|=BIT0;
}
void led_vm(){
    P1OUT&=~BIT0;
}
void led_vd(){
    P4OUT&=~BIT7;
}

void led_VD(){
    P4OUT|=BIT7;
}
void leds_config(){
    P1DIR|=BIT0; P1OUT&=~BIT0;
    P4DIR|=BIT7;P4OUT&=~BIT7;
}
void config(){
    UCA0CTL1 = UCSWRST;
    UCA0CTL0 =0;
    UCA0BRW =6;
    UCA0MCTL = UCBRF_13|UCOS16;
    P3SEL|=BIT4|BIT3;
    UCA0CTL1 = UCSSEL_2;
}

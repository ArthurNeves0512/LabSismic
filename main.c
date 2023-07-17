#include <msp430.h> 
#include"uart.h"
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	char cmdo;
	config();
	leds_config();
	while(1){
	    while((UCA0IFG&UCRXIFG)==0);
	    cmdo=UCA0RXBUF;
	    switch (cmdo) {
            case '1':
                led_VD();
                bt_str("verde acesso");
                break;
            case '2':
                led_vd();
                bt_str("verde apado");
                break;
            case '3':
                led_VM();
                bt_str("vermelho acesso");
                break;
            case '4':
                led_vm();
                bt_str("vermelho apagado");
                break;
            default:
                break;
        }
	}
	return 0;
}

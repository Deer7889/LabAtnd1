#include "mbed.h"


Serial pc(USBTX, USBRX); // tx, rx
PwmOut led(LED1);       //Sets LED1 for Pulse With Modulation for brightness as 'led'

float brightness = 0.0; //Sets inital led brightness to 0 and lables it as 'brightness'

int main() {   //start main program
 printf("Press 'u' to turn LED1 brightness up, 'd' to turn it down\n");//user instructions sent to terminal

  while (1) {  //program loop
    char c = pc.getc(); //get keyboard character from terminal
    if ((c == 'u') && (brightness < 0.5)) {  //if u is pressed LED brightness increases, start of if block 
      brightness += 0.01; //PWM increase size
      led = brightness; //sets PWM for led equal to brightness 
    pc.putc('^'); //send ^ to terminal
    } //end of this if block

    if ((c == 'd') && (brightness > 0.0)) { //if d is pressed LED brightness increases, start of if block
      brightness -= 0.01; //PWM decrease size
      led = brightness;  //sets PWM for led equal to brightness
    pc.putc('v');//send v to terminal screen
    } //end of this if block
  }   // end of while loop
}     //end of main program
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#include "inc/lm3s1165.h"

#ifdef DEBUG
void __error__(char *pcFilename, unsigned long ulLine)
{
}
#endif




int main(void)
{
    // Enable the GPIO module.
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_8MHZ);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlDelay(100);

    // Configure PE3 as an output.
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_0);
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_4);
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_5);
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_3);
    SysCtlDelay(100);

    // Loop forever.
    while(1)
    {
        // Set the GPIO high.
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_0, 0);
        GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 255);
        GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 255);
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 0);
        SysCtlDelay(1000000);

        // Set the GPIO low.
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_0, 255);
        GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 0);
        GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0);
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 255);
        SysCtlDelay(1000000);
    }
}

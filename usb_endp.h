#ifndef __USB_ENDP_H
#define __USB_ENDP_H

#include "ch554_platform.h"
uint8_t USB_EP_HALT_SET(uint8_t ep);
uint8_t USB_EP_HALT_CLEAR(uint8_t ep);

// EP0
#define EP0_ADDR 0x0000
extern_xdatabuf(EP0_ADDR, Ep0Buffer);
void USB_EP0_SETUP(void);
void USB_EP0_IN(void);
void USB_EP0_OUT(void);

// EP1
#define EP1_ADDR 0x0050
extern_xdatabuf(EP1_ADDR, Ep1Buffer);
#define EP1_SIZE 64
#define EP1_RX_BUF (Ep1Buffer)
#define EP1_TX_BUF (Ep1Buffer + EP1_SIZE)
void USB_EP1_IN(void);
void USB_EP1_OUT(void);

void NOP_Process(void);

// Out
#define EP0_OUT_Callback USB_EP0_OUT
#define EP1_OUT_Callback USB_EP1_OUT
#define EP2_OUT_Callback NOP_Process
#define EP3_OUT_Callback NOP_Process
#define EP4_OUT_Callback NOP_Process
		
// SOF
#define EP0_SOF_Callback NOP_Process
#define EP1_SOF_Callback NOP_Process
#define EP2_SOF_Callback NOP_Process
#define EP3_SOF_Callback NOP_Process
#define EP4_SOF_Callback NOP_Process
		
// IN
#define EP0_IN_Callback USB_EP0_IN
#define EP1_IN_Callback USB_EP1_IN
#define EP2_IN_Callback NOP_Process
#define EP3_IN_Callback NOP_Process
#define EP4_IN_Callback NOP_Process
		
// SETUP
#define EP0_SETUP_Callback USB_EP0_SETUP
#define EP1_SETUP_Callback NOP_Process
#define EP2_SETUP_Callback NOP_Process
#define EP3_SETUP_Callback NOP_Process
#define EP4_SETUP_Callback NOP_Process

#endif /*__USB_ENDP_H*/

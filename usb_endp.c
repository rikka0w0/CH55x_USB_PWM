#include "usb_endp.h"

#include "ch554_platform.h"

// The buffer (Tx and Rx) must have an even address, size: 64*2
xdatabuf(EP1_ADDR, Ep1Buffer, EP1_SIZE*2+4);

uint8_t USB_EP_HALT_SET(uint8_t ep) {
	switch (ep) {
	case 0x82:
		UEP2_CTRL = UEP2_CTRL & (~bUEP_T_TOG) | UEP_T_RES_STALL;
		return 0;
	case 0x02:
		UEP2_CTRL = UEP2_CTRL & (~bUEP_R_TOG) | UEP_R_RES_STALL;
		return 0;
	case 0x83:
		UEP3_CTRL = UEP3_CTRL & (~bUEP_T_TOG) | UEP_T_RES_STALL;
		return 0;
	case 0x03:
		UEP3_CTRL = UEP3_CTRL & (~bUEP_R_TOG) | UEP_R_RES_STALL;
		return 0;	
	case 0x81:
		UEP1_CTRL = UEP1_CTRL & (~bUEP_T_TOG) | UEP_T_RES_STALL;
		return 0;
	default:
		return 0xFF;
	}
}

uint8_t USB_EP_HALT_CLEAR(uint8_t ep) {
	switch (ep)
	{
	case 0x82:
		UEP2_CTRL = UEP2_CTRL & ~(bUEP_T_TOG | MASK_UEP_T_RES) | UEP_T_RES_NAK;
		return 0;
	case 0x02:
		UEP2_CTRL = UEP2_CTRL & ~(bUEP_R_TOG | MASK_UEP_R_RES) | UEP_R_RES_ACK;
		return 0;
	case 0x83:
		UEP3_CTRL = UEP3_CTRL & ~(bUEP_T_TOG | MASK_UEP_T_RES) | UEP_T_RES_NAK;
		return 0;
	case 0x03:
		UEP3_CTRL = UEP3_CTRL & ~(bUEP_R_TOG | MASK_UEP_R_RES) | UEP_R_RES_ACK;
		return 0;	
	case 0x81:
		UEP1_CTRL = UEP1_CTRL & ~(bUEP_T_TOG | MASK_UEP_T_RES) | UEP_T_RES_NAK;
		return 0;
	default:
		return 0xFF;
	}
}

void USB_EP1_IN(void) {
	UEP1_T_LEN = 0;
	UEP1_CTRL = UEP1_CTRL & ~MASK_UEP_T_RES | UEP_T_RES_NAK;	// No data to send
}


void USB_EP1_OUT(void) {
	uint8_t i;
	if (U_TOG_OK) {	// Discard unsynchronized packets
		for (i = 0; i < USB_RX_LEN; i++)
			//EP1_TX_BUF[i] = EP1_RX_BUF[i] ^ 0xFF;		// Invert bits and Tx to host (for validation)
			EP1_TX_BUF[i] = EP1_RX_BUF[i] + 1;

		UEP1_T_LEN = USB_RX_LEN;
		UEP1_CTRL = UEP1_CTRL & ~MASK_UEP_T_RES | UEP_T_RES_ACK;	// Enable Tx
	}
}

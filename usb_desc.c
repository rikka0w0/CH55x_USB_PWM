#include "usb_desc.h"

#include "ch554_platform.h"

// Device Descriptor
code const usb_device_descriptor DevDesc = {
		USB_UINT8(bLength, USB_DESCSIZE_DEVICE),
		USB_UINT8(bDescriptorType, USB_DESCR_TYP_DEVICE),	// Type: Device Descriptor
		USB_UINT16(bcdUSB, 0x0110),				// USB Spec., 0x0110 -> USB 1.1
		USB_UINT8(bDeviceClass, 0),				// Device defined at interface level
		USB_UINT8(bDeviceSubClass, 0),
		USB_UINT8(bDeviceProtocol, 0),
		USB_UINT8(bMaxPacketSize0, 8),			// Max packet size of EP0
		USB_UINT16(idVendor, 0x413d),			// VID
		USB_UINT16(idProduct, 0x2107),			// PID
		USB_UINT16(bcdDevice, 0x0000),			// Device release number in BCD
		USB_UINT8(iManufacturer, 4),			// Manufactor, index of string descriptor
		USB_UINT8(iProduct, 3),					// Product string descriptor ID
		USB_UINT8(iSerialNumber, 0),			// Serial number (String descriptor ID)
		USB_UINT8(bNumConfigurations, 1),		// Number of available configurations
};

// Configuration Descriptor and Interface Descriptor
code const uint8_t CfgDesc[] =
{
	// Configuration Descriptor
	9,					// Length of the descriptor
	0x02,				// Type: Configuration Descriptor
	// Total length of this and following descriptors
	USB_DESCSIZE_CONFIG_L, USB_DESCSIZE_CONFIG_H,
	USB_INTERFACES,		// Number of interfaces
	0x01, 				// Value used to select this configuration
	0x00,				// Index of corresponding string descriptor
	0x80,				// Attributes, D7 must be 1, D6 Self-powered, D5 Remote Wakeup, D4-D0=0
	0x32,				// Max current drawn by device, in units of 2mA

	// Interface descriptor (Vendor-defined)
	9,					// Length of the descriptor
	0x04,				// Type: Interface Descriptor
	0x00,				// Interface ID
	0x00,				// Alternate setting
	0x02,				// Number of Endpoints
	0x03,				// Interface class code
	0x01,				// Subclass code 0=No subclass, 1=Boot Interface subclass
	0x00,				// Protocol code 0=None, 1=Keyboard, 2=Mouse
	0x01,				// Index of corresponding string descriptor (On Windows, it is called "Bus reported device description")

	// HID descriptor (Vendor-defined)
	9,					// Length of the descriptor
	0x21,				// Type: HID Descriptor
	0x10, 0x01,			// bcdHID: HID Class Spec release number
	0x00,				// bCountryCode: Hardware target country
	0x01,				// bNumDescriptors: Number of HID class descriptors to follow
	0x22,				// bDescriptorType
	// wItemLength: Total length of Report descriptor
	USB_HIDREPSIZE_VENDORDEF, 0,

	// Endpoint descriptor (Vendor-defined)	// EP2, IN
	7,					// Length of the descriptor
	0x05,				// Type: Endpoint Descriptor
	0x81,				// Endpoint: D7: 0-Out 1-In, D6-D4=0, D3-D0 Endpoint number
	0x03,				// Attributes:
							// D1:0 Transfer type: 00 = Control 01 = Isochronous 10 = Bulk 11 = Interrupt
							// 			The following only apply to isochronous endpoints. Else set to 0.
							// D3:2 Synchronisation Type: 00 = No Synchronisation 01 = Asynchronous 10 = Adaptive 11 = Synchronous
							// D5:4	Usage Type: 00 = Data endpoint 01 = Feedback endpoint 10 = Implicit feedback Data endpoint 11 = Reserved
							// D7:6 = 0
	0x40,0x00,			// Maximum packet size can be handled
	0x01,				// Interval for polling, in units of 1 ms for low/full speed

	// Endpoint descriptor (Vendor-defined)	// EP2, OUT
	7,					// Length of the descriptor
	0x05,				// Type: Endpoint Descriptor
	0x01,				// Endpoint: D7: 0-Out 1-In, D6-D4=0, D3-D0 Endpoint number
	0x03,				// Attributes:
							// D1:0 Transfer type: 00 = Control 01 = Isochronous 10 = Bulk 11 = Interrupt
							// 			The following only apply to isochronous endpoints. Else set to 0.
							// D3:2 Synchronisation Type: 00 = No Synchronisation 01 = Asynchronous 10 = Adaptive 11 = Synchronous
							// D5:4	Usage Type: 00 = Data endpoint 01 = Feedback endpoint 10 = Implicit feedback Data endpoint 11 = Reserved
							// D7:6 = 0
	0x40,0x00,			// Maximum packet size can be handled
	0x01	    		// Interval for polling, in units of 1 ms for low/full speed
};

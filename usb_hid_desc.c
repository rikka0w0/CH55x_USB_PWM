#include "ch554_platform.h"
#include "usb_desc.h"


//gliethttp
code const uint8_t VendorDefDesc[] = {
		0x06,	0xA0,	0xFF,	// Usage Page(FFA0h, vendor defined)
		0x09, 0x01,				// Usage(vendor defined)
		0xA1, 0x01,				// Collection(Application)
		0x09, 0x02 ,			// Usage(vendor defined)
			0xA1, 0x00,				// Collection(Physical)
			0x06,0xA1,0xFF,		// Usage Page(vendor defined)

			// Input Report
			0x09, 0x03 ,	// Usage(vendor defined)
			0x09, 0x04,		// Usage(vendor defined)
			0x15, 0x80,		// Logical Minimum(0x80 or -128)
			0x25, 0x7F,		// Logical Maximum(0x7F or 127)
			0x35, 0x00,		// Physical Minimum(0)
			0x45,	0xFF,		// Physical Maximum(255)
			0x75, 0x08,		// Report size(8 Bits, 1 Byte)
			0x95, 0x40,		// Report count(64 fields)
			0x81, 0x02,		// Input(data, variable, absolute)
			// Output Report
			0x09, 0x05,		// Usage(vendor defined)
			0x09, 0x06,		// Usage(vendor defined)
			0x15, 0x80,		// Logical Minimum(0x80 or -128)
			0x25, 0x7F,		// Logical Maximum(0x7F or 127)
			0x35, 0x00,		// Physical Minimum(0)
			0x45,0xFF,		// Physical Maximum(255)
			0x75,0x08,		// Report size(8 Bits, 1 Byte)
			0x95, 0x40,		// Report count(64 fields)
			0x91, 0x02,		// Output(data, variable, absolute)
			0xC0,					//End Collection(Physical)
		0xC0				//End Collection(Application)
};

uint8_t* USB_HID_GetReportDesc(uint8_t interface) {
	switch (interface){
		case 0:	// Interface 0
			return VendorDefDesc;
		default:
			return 0;
	}
}

uint8_t USB_HID_GetReportDesc_Length(uint8_t interface) {
	switch (interface){
		case 0:	// Interface 0
			return USB_HIDREPSIZE_VENDORDEF;
		default:
			return 0xFF;	// Unsupported
	}
}

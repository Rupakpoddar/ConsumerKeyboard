// ConsumerKeyboard.cpp
#include "ConsumerKeyboard.h"

#if defined(_USING_HID)

static const uint8_t _hidConsumerReportDescriptor[] PROGMEM = {
    // Consumer Control only
    0x05, 0x0C,                    // USAGE_PAGE (Consumer Devices)
    0x09, 0x01,                    // USAGE (Consumer Control)
    0xA1, 0x01,                    // COLLECTION (Application)
    0x85, 0x03,                    // REPORT_ID (3)
    0x15, 0x00,                    // LOGICAL_MINIMUM (0)
    0x26, 0xFF, 0x03,             // LOGICAL_MAXIMUM (1023)
    0x19, 0x00,                    // USAGE_MINIMUM (0)
    0x2A, 0xFF, 0x03,             // USAGE_MAXIMUM (1023)
    0x75, 0x10,                    // REPORT_SIZE (16)
    0x95, 0x01,                    // REPORT_COUNT (1)
    0x81, 0x00,                    // INPUT (Data,Ary,Abs)
    0xc0                           // END_COLLECTION
};

ConsumerKeyboard_::ConsumerKeyboard_(void)
{
    static HIDSubDescriptor node(_hidConsumerReportDescriptor, sizeof(_hidConsumerReportDescriptor));
    HID().AppendDescriptor(&node);
}

void ConsumerKeyboard_::begin(void)
{
}

void ConsumerKeyboard_::sendReport(uint16_t k)
{
    HID().SendReport(3, &k, sizeof(k));
}

size_t ConsumerKeyboard_::press(uint16_t k)
{
    sendReport(k);
    return 1;
}

size_t ConsumerKeyboard_::release(void)
{
    sendReport(0);
    return 1;
}

ConsumerKeyboard_ ConsumerKeyboard;

#endif
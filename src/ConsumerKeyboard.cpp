#include "ConsumerKeyboard.h"

#if defined(_USING_HID)

static const uint8_t _hidConsumerReportDescriptor[] PROGMEM = {
    0x05, 0x0C,                    // USAGE_PAGE
    0x09, 0x01,                    // USAGE
    0xA1, 0x01,                    // COLLECTION
    0x85, 0x03,                    // REPORT_ID
    0x15, 0x00,                    // LOGICAL_MINIMUM
    0x26, 0xFF, 0x03,              // LOGICAL_MAXIMUM
    0x19, 0x00,                    // USAGE_MINIMUM
    0x2A, 0xFF, 0x03,              // USAGE_MAXIMUM
    0x75, 0x10,                    // REPORT_SIZE
    0x95, 0x01,                    // REPORT_COUNT
    0x81, 0x00,                    // INPUT
    0xc0                           // END_COLLECTION
};

ConsumerKeyboard_::ConsumerKeyboard_(void)
{
    static HIDSubDescriptor node(_hidConsumerReportDescriptor, sizeof(_hidConsumerReportDescriptor));
    HID().AppendDescriptor(&node);
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

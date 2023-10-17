#include <STM32duinoBLE.h>
#include <STM32duinoBLE.h>

#if defined(ARDUINO_STEVAL_MKBOXPRO)
/* STEVAL-MKBOXPRO */
SPIClass SpiHCI(PA7, PA6, PA5);
HCISpiTransportClass HCISpiTransport(SpiHCI, BLUENRG_LP, PA2, PB11, PD4, 1000000, SPI_MODE3);
#if !defined(FAKE_BLELOCALDEVICE)
BLELocalDevice BLEObj(&HCISpiTransport);
BLELocalDevice &BLE = BLEObj;
#endif
#elif defined(ARDUINO_STEVAL_MKSBOX1V1)
/* STEVAL-MKSBOX1V1 */
SPIClass SpiHCI(PC3, PD3, PD1);
HCISpiTransportClass HCISpiTransport(SpiHCI, SPBTLE_1S, PD0, PD4, PA8, 1000000, SPI_MODE1);
#if !defined(FAKE_BLELOCALDEVICE)
BLELocalDevice BLEObj(&HCISpiTransport);
BLELocalDevice &BLE = BLEObj;
#endif
#elif defined(ARDUINO_B_L475E_IOT01A) || defined(ARDUINO_B_L4S5I_IOT01A)
/* B-L475E-IOT01A1 or B_L4S5I_IOT01A */
SPIClass SpiHCI(PC12, PC11, PC10);
HCISpiTransportClass HCISpiTransport(SpiHCI, SPBTLE_RF, PD13, PE6, PA8, 8000000, SPI_MODE0);
#if !defined(FAKE_BLELOCALDEVICE)
BLELocalDevice BLEObj(&HCISpiTransport);
BLELocalDevice &BLE = BLEObj;
#endif
#elif defined(ARDUINO_NUCLEO_WB15CC) || defined(ARDUINO_P_NUCLEO_WB55RG) || \
    defined(ARDUINO_STM32WB5MM_DK) || defined(P_NUCLEO_WB55_USB_DONGLE)
HCISharedMemTransportClass HCISharedMemTransport;
#if !defined(FAKE_BLELOCALDEVICE)
BLELocalDevice BLEObj(&HCISharedMemTransport);
BLELocalDevice &BLE = BLEObj;
#endif
#else
/* Shield IDB05A2 with SPI clock on D3 */
SPIClass SpiHCI(D11, D12, D3);
HCISpiTransportClass HCISpiTransport(SpiHCI, BLUENRG_M0, A1, A0, D7, 8000000, SPI_MODE0);
#if !defined(FAKE_BLELOCALDEVICE)
BLELocalDevice BLEObj(&HCISpiTransport);
BLELocalDevice &BLE = BLEObj;
#endif
/* Shield IDB05A2 with SPI clock on D13 */
// #define SpiHCI SPI
// HCISpiTransportClass HCISpiTransport(SpiHCI, BLUENRG_M0, A1, A0, D7, 8000000, SPI_MODE0);
// #if !defined(FAKE_BLELOCALDEVICE)
// BLELocalDevice BLEObj(&HCISpiTransport);
// BLELocalDevice& BLE = BLEObj;
// #endif
/* Shield IDB05A1 with SPI clock on D3 */
// SPIClass SpiHCI(D11, D12, D3);
// HCISpiTransportClass HCISpiTransport(SpiHCI, SPBTLE_RF, A1, A0, D7, 8000000, SPI_MODE0);
// #if !defined(FAKE_BLELOCALDEVICE)
// BLELocalDevice BLEObj(&HCISpiTransport);
// BLELocalDevice& BLE = BLEObj;
// #endif
/* Shield IDB05A1 with SPI clock on D13 */
// #define SpiHCI SPI
// HCISpiTransportClass HCISpiTransport(SpiHCI, SPBTLE_RF, A1, A0, D7, 8000000, SPI_MODE0);
// #if !defined(FAKE_BLELOCALDEVICE)
// BLELocalDevice BLEObj(&HCISpiTransport);
// BLELocalDevice& BLE = BLEObj;
// #endif
/* Shield BNRG2A1 with SPI clock on D3 */
// SPIClass SpiHCI(D11, D12, D3);
// HCISpiTransportClass HCISpiTransport(SpiHCI, BLUENRG_M2SP, A1, A0, D7, 1000000, SPI_MODE1);
// #if !defined(FAKE_BLELOCALDEVICE)
// BLELocalDevice BLEObj(&HCISpiTransport);
// BLELocalDevice& BLE = BLEObj;
// #endif
/* Shield BNRG2A1 with SPI clock on D13 */
// #define SpiHCI SPI
// HCISpiTransportClass HCISpiTransport(SpiHCI, BLUENRG_M2SP, A1, A0, D7, 1000000, SPI_MODE1);
// #if !defined(FAKE_BLELOCALDEVICE)
// BLELocalDevice BLEObj(&HCISpiTransport);
// BLELocalDevice& BLE = BLEObj;
// #endif
#endif
BLEService myService("fff0");
BLEIntCharacteristic myCharacteristic("fff1", BLERead | BLEBroadcast);

// Advertising parameters should have a global scope. Do NOT define them in 'setup' or in 'loop'
const uint8_t manufactData[4] = {0x01, 0x02, 0x03, 0x04};
const uint8_t serviceData[3] = {0x00, 0x01, 0x02};

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!BLE.begin()) {
    Serial.println("failed to initialize BLE!");
    while (1);
  }

  myService.addCharacteristic(myCharacteristic);
  BLE.addService(myService);

  // Build scan response data packet
  BLEAdvertisingData scanData;
  // Set parameters for scan response packet
  scanData.setLocalName("Test enhanced advertising");
  // Copy set parameters in the actual scan response packet
  BLE.setScanResponseData(scanData);

  // Build advertising data packet
  BLEAdvertisingData advData;
  // Set parameters for advertising packet
  advData.setManufacturerData(0x004C, manufactData, sizeof(manufactData));
  advData.setAdvertisedService(myService);
  advData.setAdvertisedServiceData(0xfff0, serviceData, sizeof(serviceData));
  // Copy set parameters in the actual advertising packet
  BLE.setAdvertisingData(advData);

  BLE.advertise();
  Serial.println("advertising ...");
}

void loop() {
  BLE.poll();
}

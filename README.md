# Watchular (ESP32-C3 based modular watch)

### Name origin:
* watch + modular

### Bill Of Materials
|Component  |Quantity |Link   |
|-----      |-----    |-----  |
|ESP32-C3   |1        |[digikey](https://www.digikey.se/en/products/detail/espressif-systems/ESP32-C3-MINI-1-N4-A/15817506) |
|or with embedded flash (ESP32-C3FN4)   |1        |[digikey](https://www.digikey.se/en/products/detail/espressif-systems/ESP32-C3FH4/14115592) |
|Battery charger|1        |[digikey](https://www.digikey.se/en/products/detail/microchip-technology/MCP73832T-2DCI-OT/1223150) |
|Battery connector|1        |[digikey](https://www.digikey.se/en/products/detail/w%C3%BCrth-elektronik/665102131822/5047757?s=N4IgTCBcDaIGxwKwEYAMZkGZkA4wQF0BfIA) |
|Button|2        |[digikey](https://www.digikey.se/en/products/detail/e-switch/TL3301AF260QG/378995?s=N4IgTCBcDaICoBkDMSAMBGAggMTANlQEUBxEAXQF8g) |
|Ceramic antenna (chip antenna)|1        |[digikey](https://www.digikey.se/en/products/detail/johanson-technology-inc/2450AT18A100E/1560676) |
|Ceramic capacitor 100nF 0402 |4        |[digikey](https://www.digikey.se/en/products/detail/taiyo-yuden/EMK105B7104KV-F/1004039) |
|Ceramic capacitor 1pF 0402 |1        |[digikey](https://www.digikey.se/en/products/detail/walsin-technology-corporation/0402N1R0B500CT/9354767) |
|Ceramic capacitor 1uF 0603 |2        |[digikey](https://www.digikey.se/en/products/detail/taiyo-yuden/EMK107BJ105KA-T/930603) |
|Ceramic capacitor 2.2uF 0603 |2        |[digikey](https://www.digikey.se/en/products/detail/taiyo-yuden/EMK107BJ225KA-T/1004018) |
|Ceramic capacitor 4.7uF 0402 |1        |[digikey](https://www.digikey.se/en/products/detail/murata-electronics/GRT155R60J475ME13J/13904800) |
|Ceramic capacitor 4.7uF 0603 |2        |[digikey](https://www.digikey.se/en/products/detail/taiyo-yuden/JMK107BJ475KA-T/1169922) |
|Ceramic capacitor 8pF 0402 |2        |[digikey](https://www.digikey.se/en/products/detail/taiyo-yuden/UMK105CH080DVHF/6563655) |
|Ceramic inductor 2.7nH |1        |[digikey](https://www.digikey.se/en/products/detail/johanson-technology-inc/L-07C2N7SV6T/1830166?s=N4IgTCBcDaIDIFoAMB2AwmAcigygNQDYAVEAXQF8g) |
|Ceramic inductor 3.9nH |1        |[digikey](https://www.digikey.se/en/products/detail/johanson-technology-inc/L-07C3N9SV6T/1915227) |
|Crystal 16MHz|1        |[digikey](https://www.digikey.se/en/products/detail/txc-corporation/8Y-16-000MAHQ-T/6130681) |
|FLASH 4MBIT   |1        |[digikey](https://www.digikey.se/en/products/detail/winbond-electronics/W25Q16JVSSIM/12143335) |
|LDO 3.3V 600mA|1        |[digikey](https://www.digikey.se/en/products/detail/diodes-incorporated/AP7366-33W5-7/9867322) |
|LED Orange 0402|1        |[digikey](https://www.digikey.se/en/products/detail/sunled/XZMOK68W-2/4902071) |
|LED Red 0603|30        |[digikey](https://www.digikey.se/en/products/detail/liteon/LTST-C191KRKT/386837) |
|Male Header 16 positions (1 row)|2        |[digikey](https://www.digikey.se/en/products/detail/adam-tech/PH1-16-UA/9830344) |
|N-channel MOSFET|4        |[digikey](https://www.digikey.se/en/products/detail/toshiba-semiconductor-and-storage/T2N7002AK-LM/5298028) |
|P-channel MOSFET|1        |[digikey](https://www.digikey.se/en/products/detail/diodes-incorporated/DMP2004K-7/1774201) |
|Resistor 0 ohm 0402   |1        |[digikey](https://www.digikey.se/en/products/detail/yageo/RC0402JR-070RP/4935294) |
|Resistor 100k 0402   |1        |[digikey](https://www.digikey.se/en/products/detail/yageo/RC0402JR-07100KL/726416) |
|Resistor 10k 0402   |4        |[digikey](https://www.digikey.se/en/products/detail/yageo/RC0402JR-0710KL/726418) |
|Resistor 1k 0402   |5        |[digikey](https://www.digikey.se/en/products/detail/delta-electronics-cyntec/PFR05S-102-JNH/9761533) |
|Resistor 2k 0402   |1        |[digikey](https://www.digikey.se/en/products/detail/yageo/RC0402JR-072KL/726434) |
|Resistor 5.1k 1% 0402   |2        |[digikey](https://www.digikey.se/en/products/detail/yageo/RC0402FR-135K1L/14286364) |
|Resistor 560 0402   |9        |[digikey](https://www.digikey.se/en/products/detail/yageo/RC0402JR-07560RL/726492) |
|Schottky|1        |[digikey](https://www.digikey.se/en/products/detail/smc-diode-solutions/DSS16U/8341861) |
|USB-C|1        |[digikey](https://www.digikey.se/en/products/detail/gct/USB4105-GF-A/11198441) |
|ESD-protector|1        |[digikey](https://www.digikey.se/en/products/detail/smc-diode-solutions/SR05/10820120) |

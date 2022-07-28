# Watchular (ESP32-C3 based modular watch)

### Name origin:
* watch + modular

### Bill Of Materials
|Component  |Quantity |Link   |
|-----      |-----    |-----  |
|ESP32-C3   |1        |[digikey](https://www.digikey.se/en/products/detail/espressif-systems/ESP32-C3/14115579) |
|or with embedded flash (ESP32-C3FN4)   |1        |[digikey](https://www.digikey.se/en/products/detail/espressif-systems/ESP32-C3FN4/14115581) |
|Ceramic antenna (chip antenna)|1        |[digikey](https://www.digikey.se/en/products/detail/johanson-technology-inc/2450AT18A100E/1560676) |
|Ceramic capacitor 4.7uF 0603 |2        |[digikey](https://www.digikey.se/en/products/detail/taiyo-yuden/JMK107BJ475KA-T/1169922) |
|Ceramic capacitor 4.7uF 0402 |1        |[digikey](https://www.digikey.se/en/products/detail/taiyo-yuden/JMK105BBJ475MV-F/2573874) |
|Ceramic capacitor 2.2uF 0603 |2        |[digikey](https://www.digikey.se/en/products/detail/taiyo-yuden/EMK107BJ225KA-T/1004018) |
|Ceramic capacitor 100nF 0402 |4        |[digikey](https://www.digikey.se/en/products/detail/taiyo-yuden/EMK105B7104KV-F/1004039) |
|Ceramic capacitor 8pF 0402 |2        |[digikey](https://www.digikey.se/en/products/detail/taiyo-yuden/UMK105CH080DVHF/6563655) |
|Ceramic capacitor 1pF 0402 |1        |[digikey](https://www.digikey.se/en/products/detail/walsin-technology-corporation/0402N1R0B500CT/9354767) |
|Schottky|1        |[digikey](https://www.digikey.se/en/products/detail/smc-diode-solutions/DSS16U/8341861) |
|LED Orange 0402|1        |[digikey](https://www.digikey.se/en/products/detail/sunled/XZMOK68W-2/4902071) |
|LED Orange 0603|30        |[digikey](https://www.digikey.se/en/products/detail/harvatek-corporation/B1911USD-20D000114U1930/15519991) |
|USB-C|1        |[digikey](https://www.digikey.se/en/products/detail/gct/USB4105-GF-A/11198441) |
|Battery connector|1        |[digikey](https://www.digikey.se/en/products/detail/w%C3%BCrth-elektronik/665102131822/5047757?s=N4IgTCBcDaIGxwKwEYAMZkGZkA4wQF0BfIA) |
|Male Header 16 positions (1 row)|2        |[digikey](https://www.digikey.se/en/products/detail/adam-tech/PH1-16-UA/9830344) |
|Ceramic inductor 2.7nH |1        |[digikey](https://www.digikey.se/en/products/detail/johanson-technology-inc/L-07C2N7SV6T/1830166?s=N4IgTCBcDaIDIFoAMB2AwmAcigygNQDYAVEAXQF8g) |
|Ceramic inductor 3.9nH |1        |[digikey](https://www.digikey.se/en/products/detail/johanson-technology-inc/L-07C3N9SV6T/1915227) |
|P-channel MOSFET|1        |[digikey](https://www.digikey.se/en/products/detail/diodes-incorporated/DMP2004K-7/1774201) |
|N-channel MOSFET|4        |[digikey](https://www.digikey.se/en/products/detail/toshiba-semiconductor-and-storage/T2N7002AK-LM/5298028) |
|Resistor 5.1k 1% 0402   |2        |[digikey](https://www.digikey.se/en/products/detail/yageo/RC0402FR-135K1L/14286364) |
|Resistor 1k 0402   |5        |[digikey](https://www.digikey.se/en/products/detail/delta-electronics-cyntec/PFR05S-102-JNH/9761533) |
|Resistor 10k 0402   |4        |[digikey](https://www.digikey.se/en/products/detail/yageo/RC0402JR-0710KL/726418) |
|Resistor 2k 0402   |1        |[digikey](https://www.digikey.se/en/products/detail/yageo/RC0402JR-072KL/726434) |
|Resistor 100k 0402   |1        |[digikey](https://www.digikey.se/en/products/detail/yageo/RC0402JR-07100KL/726416) |
|Resistor 0 ohm 0402   |1        |[digikey](https://www.digikey.se/en/products/detail/yageo/RC0402JR-070RP/4935294) |
|Resistor 560 0402   |9        |[digikey](https://www.digikey.se/en/products/detail/yageo/RC0402JR-07560RL/726492) |
|Battery charger|1        |[digikey](https://www.digikey.se/en/products/detail/microchip-technology/MCP73832T-2DCI-OT/1223150) |
|LDO 3.3V 600mA|1        |[digikey](https://www.digikey.se/en/products/detail/diodes-incorporated/AP7366-33W5-7/9867322) |


|FLASH 4MBIT   |1        |[digikey](https://www.digikey.se/en/products/detail/winbond-electronics/W25Q16JVSSIM/12143335) |
|resistor 10k 0402   |1        |[digikey](https://www.digikey.se/en/products/detail/yageo/RC0402FR-0710KP/4935264) |
|LED red 0603|30        |[digikey](https://www.digikey.se/en/products/detail/osram-opto-semiconductors-inc/LS-Q976-NR-1/1227986) |
|LED transistor driver |4        |[digikey](https://www.digikey.se/en/products/detail/micro-commercial-co/MMBT5550-TP/10054662) |
|Ceramic capacitor 1pF |1        |[digikey](https://www.digikey.se/en/products/detail/johanson-technology-inc/500R07S1R0BV4T/1561521?s=N4IgTCBcDaIKwAYECUEHYDKBGVAhAagCwAqIAugL5A) |
|Ceramic capacitor 10nF |1        |[digikey](https://www.digikey.se/en/products/detail/tdk-corporation/CGA2B2X5R1E103M050BA/3949410) |
|Ceramic capacitor 100nF |1        |[digikey](https://www.digikey.se/en/products/detail/tdk-corporation/CGA2B1X7R1C104M050BC/3949478) |
|Ceramic capacitor 1uF |1        |[digikey](https://www.digikey.se/en/products/detail/kyocera-avx/04023D105KAT2A/13557232) |
|Button|2        |[digikey](https://www.digikey.se/en/products/detail/e-switch/TL3301AF260QG/378995?s=N4IgTCBcDaICoBkDMSAMBGAggMTANlQEUBxEAXQF8g) |


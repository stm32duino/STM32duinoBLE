# STM32duinoBLE

This library is a fork of ArduinoBLE library to add the support of SPBTLE-RF, SPBTLE-1S, BLUENRG-M2SP, BLUENRG-LP and BLUENRG-M0 BLE modules.

It was successfully tested with the [X-NUCLEO-IDB05A2] or [X-NUCLEO-IDB05A1] or [X-NUCLEO-BNRG2A1] expansion board and a [NUCLEO-F401RE] or [NUCLEO-L476RG] or [NUCLEO-L053R8], with [B-L475E-IOT01A], [B-L4S5I-IOT01A], [STEVAL-MKSBOX1V1], [STEVAL-MKBOXPRO] and with [STM32L562E-DK].

 - In order to use this library with [STEVAL-MKSBOX1V1], you need to update the firmware of the SPBTLE-1S BLE module mounted on that board as described in the following wiki page:

https://github.com/stm32duino/Arduino_Core_STM32/wiki/STM32duinoBLE#stm32duinoble-with-steval_mksbox1v1

- In order to use this library with X-NUCLEO-BNRG2A1, you need to update the firmware of the BLUENRG-M2SP BLE module mounted on that expansion board as described in the following wiki page:

https://github.com/stm32duino/Arduino_Core_STM32/wiki/STM32duinoBLE#stm32duinoble-with-x-nucleo-bnrg2a1

For more information about ArduinoBLE library please visit the official web page at:
https://www.arduino.cc/en/Reference/ArduinoBLE

## License

```
Copyright (c) 2019 STMicroelectronics. All rights reserved.
Copyright (c) 2019 Arduino SA. All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
```

[B-L475E-IOT01A]: https://www.st.com/en/evaluation-tools/b-l475e-iot01a.html
[B-L4S5I-IOT01A]: https://www.st.com/en/evaluation-tools/b-l4s5i-iot01a.html
[NUCLEO-F401RE]: https://www.st.com/en/evaluation-tools/nucleo-f401re.html
[NUCLEO-L053R8]: https://www.st.com/en/evaluation-tools/nucleo-l053r8.html
[NUCLEO-L476RG]: https://www.st.com/en/evaluation-tools/nucleo-l476rg.html
[STEVAL-MKSBOX1V1]: https://www.st.com/en/evaluation-tools/steval-mksbox1v1.html
[STEVAL-MKBOXPRO]: https://www.st.com/en/evaluation-tools/steval-mkboxpro.html
[STM32L562E-DK]: https://www.st.com/en/evaluation-tools/stm32l562e-dk.html
[X-NUCLEO-BNRG2A1]: https://www.st.com/en/ecosystems/x-nucleo-bnrg2a1.html
[X-NUCLEO-IDB05A2]: https://www.st.com/en/ecosystems/x-nucleo-idb05a2.html
[X-NUCLEO-IDB05A1]: https://www.st.com/en/ecosystems/x-nucleo-idb05a1.html
# Stop_Watch_Embedded_Systems

 **Stop Watch** system with the specifications listed below:

1. **ATmega 32** Microcontroller with frequency **1Mhz**.
2. Configuring **Timer1** in ATmega 32 with **CTC** mode to count the Stop Watch time.
3. Using six **Common Anode** 7 - segments.
4. Connecting the six 7-segments in the project using the **multiplexed technique**.
    We can connect more than one 7 - segment display by using the Multiplexing method. In
    this method, at a time one 7 - segment display is driven by the Microcontroller and the rest
    are OFF. It keeps switching the displays using transistors. Due to the persistence of vision,
    it appears as a normal display.
     Using **one 7447 decoder** for all 7-segments and control the enable/disable for each 7-segement
     using a **NPN BJT** transistor connect to one of the MCU pins.
     Like the below image:

  ![Mini Project 2](https://github.com/YoussefGobran/Stop_Watch_Embedded_Systems-/assets/132088403/194c6a57-d1a5-4463-ba21-f0fce133c49f)



5. Connect 7447 decoder 4-pins to the first 4-pins in PORTC.
6. Use first 6-pins in PORTA as the enable/disable pins for the six 7-segments.
7. Stop Watch counting should start once the power is connected to the MCU.
8. Configure **External Interrupt INT0** with **falling edge**. Connect a push button with the
    internal pull-up resistor. If a falling edge detected the **Stop Watch time should be**
    **reset**.
9. Configure **External Interrupt INT 1** with **raising edge**. Connect a push button with the
    external pull-down resistor. If a raising edge detected the **Stop Watch time should be**
    **paused**.
10. Configure **External Interrupt INT 2** with **falling edge**. Connect a push button with the
    internal pull-up resistor. If a falling edge detected the **Stop Watch time should be**
    **resumed**.



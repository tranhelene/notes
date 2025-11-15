/*

| Feature     | UART                | I2C     | SPI                       |
| ----------- | ------------------- | ------- | ------------------------- |
| Wires       | 2                   | 2       | 4+                        |
| Devices     | 2                   | Many    | Few (needs CS per device) |
| Speed       | Slow                | Medium  | Fast                      |
| Full duplex | Yes                 | No      | Yes                       |
| Clock line  | No                  | Yes     | Yes                       |
| Good for    | Debug, simple comms | Sensors | High-speed data           |


I2C
    summary:
        - 2 wires to share a bus with many devices, each with an address

    wires:
        - SDA (data)
        - SCL (clock)

    characteristics:
        - synchronous (uses clock line)
        - supports multiple devices
        - each device has an address
        - master-slave protocol

    pros:
        - only 2 wires
        - can have many devices on same bus
        - very common in sensors

    cons:
        - slower than SPI
        - more complex (ACK, addressing)
        - sensitive to noise (good for short PCB distances only)

    used for:
        - temperature sensors
        - accelerometers/ IMUs
        - EEPROM
        - small peripherals


SPI
    summary:
        - fast protocol with separate data lines and a chip select for each device

    wires:
        - MOSI (master out, slave in)
        - MISO (master in, slave out)
        - SCLK (clock)
        - CS (chip select, one per device)

    characteristics:
        - very fast
        - full duplex (send and receive simultaneously)
        - master controls clock

    pros:
        - much faster than I2C/ UART
        - very reliable
        - good for streaming data

    cons:
        - requires more wires
        - not ideal for many devices
        - no built in addressing

    used for:
        - external flash memory
        - displays
        - high speed sensors
        - ADCs/ DACs


UART
    summary:
        - 2 wires sending bytes back and forth at an agreed upon speed

    wires:
        - TX (transmit)
        - RX (receive)

    characteristics:
        - asynchronous (no clock wire)
        - point to point (only 2 devices)
        - simple but slow

    pros:
        - very easy to use
        - good for debugging/ logging
        - only 2 wires

    cons:
        - not good for many devices
        - not very fast
        - can lose sync if baud rates mismatch

    used for:
        - GPS modules
        - bluetooth modules
        - debug prints (printf over serial)





CAN

ETH protocol/ busses

RTOS

Bit manipulation

Communication protocol


*/



//Leetcode practice:

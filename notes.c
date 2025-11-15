/*

| Feature     | UART                | I2C     | SPI                       |
| ----------- | ------------------- | ------- | ------------------------- |
| Wires       | 2                   | 2       | 4+                        |
| Devices     | 2                   | Many    | Few (needs CS per device) |
| Speed       | Slow                | Medium  | Fast                      |
| Full duplex | Yes                 | No      | Yes                       |
| Clock line  | No                  | Yes     | Yes                       |
| Good for    | Debug, simple comms | Sensors | High-speed data           |


I2C (Inter-Intergrated Circuit)
    summary:
        - 2 wires to share one bus with many devices, each with an address

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


SPI (Serial Peripheral Interface)
    summary:
        - fast protocol with separate data lines and a chip select for each device
        - very fast information with dedicated wires

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


UART (Universal Asynchronous Receiver/ Transmitter)
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

*/

/*

| Feature               | CAN                               | Ethernet                           |
| --------------------- | --------------------------------- | ---------------------------------- |
| Bandwidth             | Low (~1-8 Mbps)                   | High (100 Mbps - 1 Gbps)           |
| Use case              | Control messages, safety-critical | High-bandwidth data (video, radar) |
| Reliability           | Very high                         | High but less deterministic        |
| Message Size          | Small                             | Large                              |
| Topology              | Single shared bus                 | Switched network                   |
| Real-time suitability | Yes                               | Usually no                         |


CAN (Controller Area Network)
    summary:
        - a robust communication bus designed for cars, where many ECUs share one bus and messages have priorities
        - nervous system of a car: robust, small, critical messages

    wires:
        - CAN-H
        - CAN-L

    characteristics:
        - multi master bus
        - every node can talk
        - arbitration system decides which message wins
        - very reliable and fault tolerant
        - used for real time control in vehicles

    pros:
        - extremely robust
        - works in noisy environments
        - determins priority automatically
        - many devices can share 1 bus
        - small fixed size messages (8 bytes) (predictable timing)

    cons:
        - lower bandwidth (1 Mbps) (classic CAN)
        - messages are small
        - requires tight timing rules

    used for:
        - powertrain ECUs
        - braking systems
        - steering
        - battery management systems
        - vehicle control networks


ETH (Automotive Ethernet)
    summary:
        - provides high speed communication for cameras, sensors, ADAS, infotainment, and high bandwidth modules
        - internet inside tha car: huge amounts of data, fast

    characteristics:
        - much faster than CAN
        - used for data-heavy systems
        - supports structured networks (switches/ routing)
        - standard speeds: 100 Mbps, 1 Gbps, and up

    pros:
        - extremely high bandwidth
        - good for cameras and sensors
        - supports complex topologies
        - future proof

    cons:
        - more power consumption
        - more complex hardware/ software
        - not ideal for real time control (higher latency than CAN)

    used for:
        - autonomous drving sensors
        - cameras
        - radar/ LiDAR
        - infotainment
        - OTA updates

*/

/*

RTOS (Real Time Operating System)


Communication protocol


*/


// Bit manipulation



// Leetcode practice:

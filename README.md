A basic TCP server implementation includes:

- Connection Establishment

  A three-way handshake used to establish the connection betwen the server and client.

  1. Client sends a `SYN` packet
  2. Server send back a `SYN-ACK` packet
  3. Client sends an `ACK` packet

- Connection states

  - `LISTEN`
  - `SYN-SENT`
  - `SYN-RECEIVED`
  - `ESTABLISHED`
  - `FIN-WAIT-1`
  - `FIN-WAIT-2`
  - `CLOSE-WAIT`
  - `CLOSING`
  - `LAST-ACK`
  - `TIME-WAIT`

- Data transmission

  TCP transmits data as internat datagrams that contain:

    - Sequence number: position of segment in the stream of data
    - Acknowledgement number: indicates the position of the next segment
    - Flow control: uses a window size to indicate the send/receive data limit

- Connection termination

  Typically uses a four-way handshake:
  
    1. Sender sends `FIN` packet
    2. Receiver sends `ACK` packet
    3. Receiver sends `FIN` packet
    4. Sender sends `ACK` packet
  
  Either the sender or receiver can initiate the termination.

- TCP Header

```
       0                   1                   2                   3
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |          Source Port          |       Destination Port        |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                        Sequence Number                        |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                    Acknowledgment Number                      |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |  Data |           |U|A|P|R|S|F|                               |
   | Offset| Reserved  |R|C|S|S|Y|I|            Window             |
   |       |           |G|K|H|T|N|N|                               |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |           Checksum            |         Urgent Pointer        |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                    Options                    |    Padding    |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                             data                              |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
```
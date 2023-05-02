A basic TCP server implementation includes:
  
- Three-way handshake

  Used to establish the connection betwen the server and client.

  1. Client sends an SYN packet
  2. Server send back a SYN-ACK packet
  3. Client sends an ACK packet

- Connection states

  - LISTEN
  - SYN-SENT
  - SYN-RECEIVED
  - ESTABLISHED
  - FIN-WAIT-1
  - FIN-WAIT-2
  - CLOSE-WAIT
  - CLOSING
  - LAST-ACK
  - TIME-WAIT 

- Data transmission

  TCP transmits in data in segments that contain:

    - Sequence number: position of segment in the stream of data
    - Acknowledgement number: indicates the position of the next segment

- Flow control

  TCP uses a window size to indicate the amount of data that the sender
  is allowed to send and the amount the receiver can received. It is
  agreed upon during the three-way handshake.

- Connection termination

  Typically uses a four-way handshake:
  
    1. Sender sends FIN packet
    2. Receiver sends ACK packet
    3. Receiver sends FIN packet
    4. Sender sends ACK packet
  
  Either the sender or receiver can initiate the termination.

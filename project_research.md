# Project Research
---

## Unix Signals

*Unix Signals are software interrupts that are used to communicate between
processes on a system. They can be used to preocess information or data, and
notify of the termination of a process, request the termination of a process, or
the sending or receiving of data.* 

⚠️  **Sending a signal to a process will have the Kernel interrupt that process,
which will in turn call the handler registered to that process.**

⚠️  **Only signals SIGSUR1 and SIGSUR2 are allowed for communication, so data
transfer will have to rely on binary info.**

➡️  *As soon as a signal is received, start listening and send data one byte at a
time, with either SIGSUR1 or SIGSUR2 defined as 0 or 1. A specific* **kill
byte** *is specified which marks the end of the signal having been transmitted.
For practical purpouses this could be terminating NULL byte at the end of a
string*

---

## Goals

- Server must list all messages
- Server must list messages rapidly
- Server must be able to list the messages of multiple clients sequentially
- Messages are sent to the server from a client program
- Client is called each time a message is sent and does not run continuously

## Constraints

- Communication between programs can only be achieved through Unix signals
- Only the SIGSUR1 and SIGSUR2 signals are allowed to be used.

---

## Messenging Protocol

1. Server waits for SIGSUR1 or SIGSUR2 signal from client.
2. Client sends over message one byte at a time to the server.
3. If another client sends a message, queu it instead.
4. Server confirms message reception.
5. Client can now send new messages.

### Message Hash

| _ _ _ _ _ _ _ _ | | _ _ _ _ _ _ _ _ |
     
    CLIENT BYTE         DATA BYTE

- *Client Byte is a PID hash over 256 values*
- *Data Byte containts the actual data being sent*

➡️  This allows to differenciate between different clients when receiving
multiple messages.

ℹ️  Alternitevely, can just use PID as client identifier

---

## Specifications

- max message length: 2058
- message buffer length: 256
- max username length: 24

## Project structure

include
 |-- ...
 |
src
 |--server
 |    |--Rakefile
 |
 |--client
 |    |--Rakefile
 |
 |--comms
 |    |-- ...
 |
 vendor
 |--libft
 |    |-- ...

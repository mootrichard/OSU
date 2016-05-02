Programming Assignment #1
Author: Richard Moot
Description: Chat Server & Client for communicating over a socket in a back and forth manner
Date: May 1, 2016

Instructions for compiling:

1. Run "make" (run "make clean" to remove object files and program after done)

Instructions for running:

1. Run "./chatserve [PORT NUMBER]" (port number optional)
2. Run "python chatclient.py [server IP] [port]" in another terminal or on another client

The default port number is 33221 if you do not specify one.

This project took a lot of influence from "Beej's Guide to Network Programming"
(http://beej.us/guide/bgnet/output/html/multipage/index.html) and "LinuxHowtos"
(http://www.linuxhowtos.org/C_C++/socket.htm).

The chat has to be initiated by the client after creating a username. Once that has been created
the client will connect and can send a message. When the server receives a message, it will be
displayed and allow the server user to respond. This will continue until one party quits (typing "\quit") or
terminates their session. The server will remain running until it receives a SIGINT (Ctrl+C works).

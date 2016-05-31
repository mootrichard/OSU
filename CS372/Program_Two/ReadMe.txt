Programming Assignment #2
Author: Richard Moot
Description: FTP Server & Client for retrieving files from a remote server
Date: May 30, 2016

Instructions for compiling:

1. Run "make" (run "make clean" to remove object files and program after done)

Instructions for running:

1. Run "./ftpserver [PORT NUMBER]" (port number required)
2. Run "python client.py [server IP] [server port] [-l | -g filename] [data port]" in another terminal or on another client

This project took a lot of influence from "Beej's Guide to Network Programming"
(http://beej.us/guide/bgnet/output/html/multipage/index.html) and "LinuxHowtos"
(http://www.linuxhowtos.org/C_C++/socket.htm).

The FTP Server runs in a directory where you plan on allowing access to files. It will send all files that exist within that directory if a -l (list) commend is received. If -g (get) request is received it will send the specified file along to the client over the data port that the client has determined.

A lot of the error handling is at the validation for the client to prevent incorrect arguments being used with the client. Any other error handling should be apparent in the console of either the client or the server, depending on the nature of the error.

Sources:
  https://docs.python.org/2/library/os.path.html
  https://docs.python.org/2/library/struct.html
  http://www.afterhoursprogramming.com/tutorial/Python/Writing-to-Files/
  http://beej.us/guide/bgnet/output/html/singlepage/bgnet.html
  http://www.linuxhowtos.org/C_C++/socket.htm

#
# Author: Richard Moot
# Description: Chat Client for communicating over a socket in a back and forth manner
# Date: May 1, 2016
#

from socket import *
import sys
import signal

# Used to notify of chat client terminating
def signal_handler(signal, frame):
    print("Connection closed...")
    clientSocket.send("\quit")
    sys.exit(0)

# Registering event for signaling SIGINT
signal.signal(signal.SIGINT, signal_handler)

#Check if user provided correct format for server IP and port
if(len(sys.argv) != 3):
    print("Wrong format, please add \"<server ip> <port number>\"")
    sys.exit(0)
else:
    ip_address = sys.argv[1]
    port = int(sys.argv[2])

clientSocket = socket(AF_INET, SOCK_STREAM)

# Attempt to connect to the provided IP and Port
try:
    clientSocket.connect((ip_address,port))
except:
    print "Failured to connect to: " + ip_address
    sys.exit()

# Hooray! We have connected to the server
print "Success! Connected to: " + ip_address + "at port: " + str(port)

# Requesting the client's desired username
while True:
    username = raw_input("What's your username? (10 characters or less): ")
    if((len(username) < 11) and ((' ' in username) == False)):
        break
    else:
        print "Name must be less than 10 characters without whitespaces"

# Starting chat with server
while True:
    sentence = raw_input(str(username) + ":> " )

	# Checking if client has decided to quit
    if sentence == "\\quit":
        clientSocket.send(sentence)
        print "Chat ended"
        clientSocket.close()
        break

	# Sending desired message to the server
    sentence = username + ":> " + sentence
    clientSocket.send(sentence)

	# Receiving message from the server
    newReceived = ''
    newReceived = clientSocket.recv(1024)

	# Checking of the message is a quit command
    if newReceived[:5] == "\\quit":
        print "Chat ended"
        clientSocket.close()
        break
    else: # Writing message out to console
        sys.stdout.write(newReceived)

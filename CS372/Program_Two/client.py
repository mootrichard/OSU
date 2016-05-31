#
# Author: Richard Moot
# Date: May 29, 2016
# Description:
#   Client program for interacting with FTP server. Works in single executions of commands
#   -l for listing the directory and -g for getting a file
#

import sys
import signal
import socket
import os.path
import time

from socket import (
    socket,
    gethostname,
    gethostbyname,
    AF_INET,
    SOCK_STREAM,
    SOL_SOCKET,
    SO_REUSEADDR,
    ntohs,
    htons
)
import struct
from struct import pack, unpack # Structured binary data

def main():
    verifyArguments()

    # Arguments used for establishing communcation connections
    serverHost = sys.argv[1]
    serverPort = int(sys.argv[2])
    command = sys.argv[3]

    # Need to handle assignment differently for different commands
    if command == "-g":
        fileName = sys.argv[4]
        dataPort = int(sys.argv[5])

    # List command requires less arguments so we don't need a filename
    if command == "-l":
        dataPort = int(sys.argv[4])

    # Connection client socket to command port of the server
    clientSocket = connectSocket(serverHost, serverPort)
    print "SUCCESS: Connected to server at " + serverHost + ":" + str(serverPort) + " ..."

    # Sending command to the server
    sendCommand(clientSocket, command)

    # If getting files, we need to also send the filename to the server
    if command == "-g":
        sendCommand(clientSocket, fileName)

    # Sending specified data port to the server
    sendCommand(clientSocket, str(dataPort))

    # Need to pause here since it is processing the previous connection before it should open the data connection
    time.sleep(2)

    # Connecting over data port to the server
    print "Establishing data connection to specified port..."
    dataSocket = connectSocket(serverHost, dataPort)
    print "Data socket connected at " + serverHost + ":" + str(dataPort) + "..."

    # Getting file from data port
    if command == "-g":
        retrieveFile(dataSocket, fileName)

    # Getting directory from the server over the data port
    if command == "-l":
        retrieveDir(dataSocket)

    print "SUCCESS: Operation complete"
    print

    # All done closing out open sockets
    dataSocket.close()
    clientSocket.close()
    return

#
#   Verifies that the provided arugments are correct
#

def verifyArguments():
    usage = "\tUsage: <server host> <server port> < -l | -g filename> <data port>\n"

    if len(sys.argv) not in (5, 6):
        sys.stderr.write("Invalid number of arguements\n")
        sys.stderr.write(usage)
        exit(1)

    if len(sys.argv) == 6:
        if sys.argv[3] == "-l":
            sys.stderr.write("Invalid arguements: Filename not required on -l \n")
            sys.stderr.write(usage)
            exit(1)

    if len(sys.argv) == 5:
        if sys.argv[3] == "-g":
            sys.stderr.write("Invalid arguements: Filename not provided after -g \n")
            sys.stderr.write(usage)
            exit(1)

    return

#
#   Connects to the provided IP and port
#   @sockIP     destined IP for connecting to
#   @sockPort   destined Port for connecting to
#   returns     new connected socket
#
def connectSocket(sockIP, sockPort):

    newSocket = socket(AF_INET, SOCK_STREAM)
    newSocket.connect((sockIP, sockPort))

    return newSocket

#
#   Sends command from client to the server specifying what they want to do
#   @incSocket  socket for sending the command over
#   @command    command to be executed by the server
#
def sendCommand(incSocket, command):

    commandSize = 2 + len(command)

    outCommand = pack(">H", commandSize)
    outCommand += command

    incSocket.sendall(outCommand)

    return

#
#   Received all data in raw form from the given socket without losing anything
#   @incSocket  socket for receiving data from
#   @n          size of the data being received
#
def recvAllData(incSocket, n):

    data = ''
    while len(data) < n:
        message = incSocket.recv(n - len(data))
        if not message:
            return None
        data += message
    return data

#
#   Receives data from a socket to be returned from recvAllData
#   @incSocket  socket for retrieving data from
#   returns     data from the socket using recvAllData
#
def recvData(incSocket):

    rawdata = recvAllData(incSocket, 4)
    if not rawdata:
        return None
    dataLen = struct.unpack('=I', rawdata)[0]
    dataLen = ntohs(dataLen)

    return recvAllData(incSocket, (dataLen - 4))

#
#   Retrieves the specified file from the server
#   @incSocket  socket for retrieving the file from
#   @fileName   name of the file to be retrieved
#
def retrieveFile(incSocket, fileName):

    fileData = recvData(incSocket)

    if fileData == "NOT FOUND":
        print "ERROR File doesn't exist"
    elif fileData == "FILE FOUND":

        fileData = recvData(incSocket)

        if fileData == "FILE ERROR":
            print "ERROR: " + fileName + "couldn't be opened"
        else:
            fileSize = int(fileData)
            fileAll = recvData(incSocket)

            while os.path.isfile(fileName):
                print("Duplicate filename. Enter new name")
                fileName = raw_input(":")

            newLocalFile = open(fileName, "w")
            newLocalFile.write(fileAll)
            newLocalFile.close()

    return

#
#   Retrieves the directory from the server
#   @incSocket  socket for getting the server directory from
#
def retrieveDir(incSocket):
    directorySize = recvData(incSocket)
    print "============"
    for i in range(0, int(directorySize)):
        oneFile = recvData(incSocket)
        print oneFile
    print "============"
    return

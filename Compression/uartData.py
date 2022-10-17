from fileinput import filename
from tokenize import Double
import serial
import codecs
import subprocess
import time
import os

num_batchs = 0 
data = []
line = ""
filename = "data.txt"
fil =  codecs.open(filename,"a","utf-8")
ser = serial.Serial()
ser.timeout = 5
ser.port = 'COM6'
ser.baudrate =38400
ser.open()

#getting data from stm
while num_batchs!=3:
    for i in range(20):
        line = ser.readline().decode('utf-8','ignore')
        print(line)# COM16
        fil.write(line)
        line = line.strip()
        line = line.replace("\\", "\\\\")  
    num_batchs+=1


##############
## Script listens to serial port and writes contents into a file
##############
## requires pySerial to be installed 
import serial
import datetime
import pandas as pd
serial_port = '/dev/cu.usbmodem141201'
baud_rate = 9600; #In arduino, Serial.begin(baud_rate)
write_to_file_path = "record_sheet.csv";

# output_file = open(write_to_file_path, "w+")
ser = serial.Serial(serial_port, baud_rate)
df =pd.DataFrame(["default"],columns=["name"])
# df["name"] = "HELLO"
# print(df)
i=0
while True:
    line = ser.readline()
    line = line.decode("utf-8") #ser.readline returns a binary, convert to string
    pos =repr(line).find(",")
    line = repr(line).replace("'","").replace(r"\r","").replace(r"\n","")
    print(line)
    name = line[:pos-1]
    temp =line[pos:]
    print(name)
    df.loc[i] = name
    df["temp"] =temp
    # output_file.write(line)
    i+=1
    
    if (i%10==0):
        df["DateTime"] = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        df.to_csv(write_to_file_path)
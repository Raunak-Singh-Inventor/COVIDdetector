########################
# Python script to receive and record the data
# by Raunak Singh
########################

## requires pySerial to be installed 
import serial
import datetime
import pandas as pd

# change the serial port to the one of your arduino
serial_port = '/dev/cu.usbmodem141201'
baud_rate = 9600; # set as serial monitor baud rate
# data will be written to this csv file
write_to_file_path = "record_sheet.csv";

# define serial with port and baud rate
ser = serial.Serial(serial_port, baud_rate)
# define a new dataframe with one column
df =pd.DataFrame(["default"],columns=["name"])

i=0 # counter
# while input is coming
while True: 
    line = ser.readline() # read the line from the serial port
    line = line.decode("utf-8") #s er.readline returns a binary, convert to string
    pos =repr(line).find(",") # find comma in the line and mark it's position
    line = repr(line).replace("'","").replace(r"\r","").replace(r"\n","") # clean the string of unwanted characters
    print(line) # debugging code
    name = line[:pos-1] # select the name of user
    temp =line[pos:] # select temperarure value of user
    print(name) # debugging code
    df.loc[i] = name # insert name in name column
    df["temp"] =temp # insert temp in new temp column
    i+=1 # increase counter by 1
    
    # show  th ecode after every 10 lines
    if (i%10==0):
        # record the time when input recieved
        df["DateTime"] = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        # write all of this data to record_sheet.csv
        df.to_csv(write_to_file_path)
#____DONE_____#
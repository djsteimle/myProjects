import sys
import os
import datetime
import platform
PingCnt = 0
ipAddr = ["130.38.4.37", "130.38.251.42", "130.38.251.46", "130.38.4.254"]
ipFail = [0, 0, 0, 0]
retVal = 0
PingMax = 50
#PingMax = 10
opSystem = platform.system()

# determine if running on a Linux or Winddows machine
def setOpSys():
   opSystem = platform.system()
#   print(opSystem)
   if opSystem != "Linux":
     opSystem = "Windows"
     return opSystem

# based on system type, build and send a ping to an address
def pingAddr(cnt, addr):
   myCnt = 20
   if opSystem == "Linux":
     myCmd = "ping -c %s -s 1500 %s > /dev/null"%(cnt,addr)
#     myCmd = "ping -c %s -s 1500 %s > /dev/null"%(myCnt,addr)
   else:
#     myCmd = "ping /n %s /l 1500 %s > temp.txt"%(cnt,addr)
     myCmd = "ping /n %s /l 1500 %s > temp.txt"%(myCnt,addr)
   retVal = os.system(myCmd)
   return retVal

# trace the route to the address provided
def traceRt(addr):
   myCmd = "traceroute %s"%(addr)
   os.system(myCmd)
   return

# format and print a ping filure message
def printFail(addr, failCnt, pingCnt):
   curTime = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
   print(curTime, ": Failed to ping ", addr, " ", failCnt, " times on try ", pingCnt)
   return

# format the current data and time into a string
def getCurTime():
    curTime = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    return curTime

#curTime = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
#curTime = getCurTime()
#print(curTime)
while PingCnt < PingMax:
    PingCnt = PingCnt+1
    for ip in range(len(ipFail)):
        print(getCurTime(), " Interation ", PingCnt, ". Pinging ", ipAddr[ip])
        retVal = pingAddr(PingCnt,ipAddr[ip])
        if retVal != 0:
           ipFail[ip] = ipFail[ip] + 1
           printFail(ipAddr[ip], ipFail[ip], PingCnt)
#curTime = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
#curTime = getCurTime()
#print(curTime)

for ip in range(len(ipFail)):
    print("Failed to ping ", ipAddr[ip], " ", ipFail[ip], " times out of ", PingCnt, " attempts. Ratio ", ipFail[ip]/PingCnt)
#traceRt(PingAddrWS)
#traceRt(PingAddrRT)
#traceRt(PingAddrRT2)
#traceRt(PingAddrSW)

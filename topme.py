#!/usr/bin/python3

import sys
import  os as unix

if __name__ == "__main__":

    names = {}

    for arg in sys.argv:
        arg = arg.strip()
        F = unix.popen("ps -ely | grep "+str(arg), "r", 128 * 1024)

        fstream = F.read()
        mapped = fstream.splitlines()

        for k in mapped:
            spl = k.split(" ")
            if arg in spl:
                print(arg)
                unix.system("top -H -p "+str(spl[3]))

#!/usr/bin/python

import sys
import time

"""
시작 시간
"""
START_DAY = 23
START_HOUR = 21
START_MIN = 00

"""
종료 시간
"""
END_DAY = 26
END_HOUR = 6
END_MIN = 00

UNIT_SECOND = 1

if __name__ == "__main__":
        
        try:
                # Until start time
                while True:
                        now = time.localtime()
                        print("Wait please... current time is %02d:%02d:%02d" % (now.tm_hour, now.tm_min, now.tm_sec))
                        time.sleep(UNIT_SECOND)

                        if now.tm_hour == START_HOUR and now.tm_min == START_MIN and now.tm_mday == START_DAY:
                                break

                print("Main work will be started")

                # Until end time
                while True:

                        // do something...

                        now = time.localtime()
                        print("End time is %02d:%02d (current: %02d:%02d:%02d)" % (END_HOUR, END_MIN, now.tm_hour, now.tm_min, now.tm_sec))

                        if now.tm_hour == END_HOUR and now.tm_min == END_MIN and now.tm_mday == END_DAY:
                                break
        except Exception as e:
                file = open("error.log", "a")
                file.write("%02d:%02d " % (now.tm_hour, now.tm_min) + str(sys.exc_info()[0]) + "\n")
                file.write(str(e))
                file.close()

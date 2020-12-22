import sys

from datetime import datetime

length = len(sys.argv)
if length < 2:
	print("시작 시간 입력")
	sys.exit(1)
elif length > 3:
	print("인수가 많습니다")
	sys.exit(1)

start_h = int(sys.argv[1].split(":")[0])
start_m = int(sys.argv[1].split(":")[1])

if length == 3:
	minus_h = int(sys.argv[2].split(":")[0])
	minus_m = int(sys.argv[2].split(":")[1])

now = datetime.now()

sum = now.hour * 60 + now.minute
sum -= (start_h * 60 + start_m)
if length == 3:
	sum -= (minus_h * 60 + minus_m)

print(int(sum / 60), sum % 60)

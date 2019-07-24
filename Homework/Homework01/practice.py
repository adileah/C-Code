names = []
import random
with open('names.txt', 'r') as fp:
    line = fp.readline().rstrip()
    while(line):
        names.append(line)
        line = fp.readline().rstrip()

print names
random.shuffle(names)
groupsize = input()
for i in range(len(names)):
    if i % groupsize == 0:
        print "\n\n\n"
    print i, names[i]

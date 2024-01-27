import add_c
import os, psutil

def GetContainer():
    c = add_c.Container()
    c.Count = 80
    return c



for i in range(1000000):
    if i % 100000 == 0:
        process = psutil.Process()
        print(i, ":", process.memory_info().rss)

    t = GetContainer()


process = psutil.Process()
print(1000000, ":",  process.memory_info().rss)
import matplotlib.pyplot as plt
import os
import math
import sys


plt.ion()
fig = plt.figure()
ax = fig.add_subplot(1,1,1)

import matplotlib.pyplot as plt

def save(name='', fmt='png'):
    pwd = os.getcwd()
    iPath = "pic"
    if not os.path.exists(iPath):
        os.mkdir(iPath)
    os.chdir(iPath)
    plt.savefig('{}.{}'.format(name, fmt), fmt='png')
    os.chdir(pwd)
    #plt.close()

def getKm():
    km = []

    for line in open("data.csv").readlines():
        index = line.index(',')
        tmp = line[:index]
        try:
            tmp = float(tmp) / 1000
        except ValueError:
            tmp = tmp
        km.append(tmp)
    km = km[1:]
    return (km)

def getPrice():
    price = []

    for line in open("data.csv").readlines():
        index = line.index(',')
        tmp = line[index + 1: -1]
        try:
            tmp = float(tmp) / 1000
        except ValueError:
            tmp = tmp
        price.append(tmp)
    price = price[1:]
    return (price)

def makeGraph(theta0, theta1):
    fig = plt.figure()
    i = 300000.0
    # Добавление на рисунок прямоугольной (по умолчанию) области рисования
    while i > 0:
        scatter1 = plt.scatter(i, theta0 + theta1*i, color='#000000')
        i = i-250
    km = []
    price = []
    km = getKm()
    price = getPrice()
    for i in range (0, len(km)):
        scatter1 = plt.scatter(km[i]*1000, price[i]*1000, color='#00FF00', linewidth=3.0)
    text1 = plt.text(0, 1000, 'Km')
    # print('Text: ', type(text1))
    text1 = plt.text(-50000, 9000, 'Price')
    # print('Text: ', type(text1))

    grid1 = plt.grid(True)   # линии вспомогательной сетки

    save(name='pic_2_1', fmt='pdf')
    save(name='pic_2_1', fmt='png')

    plt.show()

def main():
    i = 0
    for line in open("output.linpreg").readlines():
        if i == 0:
            theta0 = float(line)
        if i == 1:
            theta1 = float(line)
        i+=1
    makeGraph(theta0, theta1)
main()
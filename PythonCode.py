import re
import string
import os.path
from os import path

def CountAll():

    text = open("input.txt", "r")

    dictionary = dict()

    for line in text:

        line = line.strip()

        word = line.lower()

        if word in dictionary:

            dictionary[word] = dictionary[word] + 1
        else:

            dictionary[word] = 1

    for key in list (dictionary.keys()):
        print(key.capitalize(), ":", dictionary[key])

    text.close()

def CountInstances(searchTerm):

    searchTerm = searchTerm.lower()

    text = open("input.txt", "r")


    wordCount = 0

    for line in text:

        line = line.strip()

        word = line.lower()

        if word == searchTerm:

            wordCount += 1

    return wordCount

    text.close()

def CollectData():

    text = open("input.txt", "r")

    frequency = open("frequency.dat", "w")

    dictionary = dict()


    for line in text:

        line = line.strip()

        word = line.lower()

        if word in dictionary:

            dictionary[word] = dictionary[word] + 1
        else:

            dictionary[word] = 1

    for key in list (dictionary.keys()):

        frequency.write(str(key.capitalize()) + " " + str(dictionary[key]) + "\n")

    text.close()
    frequency.close()
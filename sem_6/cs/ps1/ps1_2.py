# -*- coding: utf-8 -*-
"""
Created on Tue Dec 21 10:54:09 2021

@author: 19pw33
"""

from collections import OrderedDict
from string import ascii_lowercase
from types import coroutine

def generate_key_table(key):
    alphabets = list(ascii_lowercase)
    alphabets.remove('j')
    key_table = [[0 for i in range(5)] for i in range(5)]
    key_list = "".join(OrderedDict.fromkeys(key.lower().replace('j', 'i')))
    i = 0
    j = 0

    for key in key_list:
        key_table[i][j] = key
        j += 1
        if j == 5:
            j = 0
            i += 1

    for alphabet in alphabets:
        if (alphabet not in key_list):
            key_table[i][j] = alphabet  
            j += 1
            if j == 5:
                j = 0
                i += 1
    
    return key_table
 
def generate_diagraph(text):
    plain_text = list()
    for character in text.lower():
        if character in ascii_lowercase:
            plain_text.append(character)
    
    diagraph = list()
    i=0
    while(i < len(plain_text)):
        if i == len(plain_text)-1 and plain_text[i] == 'z':
            plain_text.append("x")

        elif i == len(plain_text)-1:
            plain_text.append("z")

        if plain_text[i] == plain_text[i+1]:
            diagraph.append(plain_text[i] + "x")
        else:
            diagraph.append(plain_text[i] + plain_text[i+1])
            i += 1
        
        i += 1

    return diagraph

# print(generate_diagraph("jaz"))


# print(generate_key_table("athens"))

def search_key_table(key_table, key):
    for i in range(5):
        for j in range(5):
            if key_table[i][j] == key:
                return i, j

def encipher(text, key):
    key_table = generate_key_table(key)
    ciphertext = ""
    diagraph = generate_diagraph(text)
    for word in diagraph:
        row0, col0 = search_key_table(key_table, word[0])
        row1, col1 = search_key_table(key_table, word[1])

        if col0 == col1:
            ciphertext += key_table[(row0 + 1) % 5][col0] + key_table[(row1 + 1) % 5][col1]
        
        elif row0 == row1:
            ciphertext += key_table[row0][(col0 + 1) % 5] + key_table[row1][(col1 + 1) % 5]

        elif (row0 < row1 and col0 < col1) or (row0 > row1 and col0 > col1):
            ciphertext += key_table[row0][col1] + key_table[row1][col0]

        elif (row0 < row1 and col0 > col1) or (row0 > row1 and col0 < col1):
            ciphertext += key_table[row1][col0] + key_table[row0][col1]

    return ciphertext

print(encipher("instruments", "monarchy"))
# -*- coding: utf-8 -*-
"""
Created on Tue Dec 21 10:54:09 2021

@author: 19pw33
"""

from collections import OrderedDict
from string import ascii_lowercase

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
            plaintext.append(character)
    
    diagraph = list()
    for i in range(len(plain_text)):
        if plain_text[i] == plain_text[i+1]:
            diagraph.append(plain_text[i] + "x")
        else:
            

// print(generate_key_table("athens"))

def search_key_table(key_table, key):
    for i in range(5):
        for j in range(5):
            if key_table[i][j] == key:
                return i, j

def encipher(text, key):
    key_table = generate_key_table(key)
    ciphertext = ""
    diagraph = list()
    
# -*- coding: utf-8 -*-
"""
Created on Tue Feb 22 11:14:43 2022

@author: 19pw33
"""

class PermutationCipher:
    
    def __init__(self, col_size: str):
        self.col_size = col_size
        
    def encipher(self, plain_text: str) -> str:
        if len(plain_text) % self.col_size != 0:
            raise Exception("Incompatible column size")

        perm = list()
        row = list()
        for index in range(len(plain_text)):
            row.append(plain_text[index])
            if len(row) == self.col_size or index == len(plain_text) - 1:
                perm.append(row)
                row = list()
            
        cipher_text = ""
        for i in range(self.col_size):
            for j in range(len(perm)):
                cipher_text += perm[j][i]
                
        return cipher_text

    
    def decipher(self, cipher_text: str) -> str:
        if len(cipher_text) % self.col_size != 0:
            raise Exception("Incompatible column size")
            
        perm = list()
        row = list()
        col_size = int(len(cipher_text) /  self.col_size)
        for index in range(len(cipher_text)):
            row.append(cipher_text[index])
            if len(row) == col_size or index == len(cipher_text) - 1:
                perm.append(row)
                row = list()
            
        plain_text = ""
        for i in range(col_size):
            for j in range(len(perm)):
                plain_text += perm[j][i]
                
        return plain_text
            

if __name__ == "__main__":
    plain_text = "cryptography"
    permutation_cipher = PermutationCipher(4)
    cipher_text = permutation_cipher.encipher(plain_text)
    retreived_plain_text = permutation_cipher.decipher(cipher_text)
    print(cipher_text, retreived_plain_text)
        
    
from Crypto.Cipher import AES

f = open('file1','r')
data = bytes(f.read(), 'utf-8')
f.close()

key = b'11111111111111111111111111111111'
cipher = AES.new(key, AES.MODE_EAX)
nonce = cipher.nonce
ciphertext, tag = cipher.encrypt_and_digest(data)

f = open('file2','wb+')
f.write(ciphertext)
f.close()
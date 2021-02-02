import sys

sc="shellcode like \xfc\xe8\x89\x00\x00\x00\x60\x89\xe5\x31\xd2\x64\x8b\x52\x30\x8b....."
try:
    key=sys.argv[1]
    spl=sys.argv[2]
except:
    print('''/*help:python xor_shellcode.py your_key split_str
             your_key is a word make your encdata more special
             split_str is a word that split each byte of encdata
             you can do like this :"python xor_shellcode.py apple \ "*/''')
encdata=""

def xor(sc,key):
    global encdata
    k=0
    for i in sc:
        tmp=ord(sc[k])
        for j in key:
            tmp^=ord(j)
        encdata+=str(tmp)+spl
        k=k+1

xor(sc,key)
print(encdata)

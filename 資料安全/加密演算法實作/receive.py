from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from Crypto.Protocol.KDF import PBKDF2
import hashlib
from Crypto.Util.Padding import unpad
# 固定的 salt
salt = b'\xd0\x18\xa7QM\xd6\x9b\xebxu\xe4\xed\xa8\x83\xf6\xa3/\x01\x9c\x9e\x86n\xda;\x10EdD\xf7\x932\xcc'

inputFile = 'my_massage.txt'
inputFile2 = 'mac.txt'
line=""

# 從檔案讀取初始向量與密文
with open(inputFile,'r') as f:
 line = f.readline()

s = hashlib.sha256()#雜湊函數
data=line
data = str.encode(data)#將訊息轉為byte
s.update(data)#更新雜湊對象
h = s.hexdigest()#回傳雜湊值
print("從訊息產生的訊息摘要:",h)
#print(h)
h=str.encode(h)#將資料型態轉為byte
#print(h)

#-------------------------------
with open('key.txt','r') as f:#讀取金鑰
  keyline = f.readline()


#print(keyline)  
while True:
    password =input("輸入加密金鑰:")
    while keyline!=password :#確認輸入金鑰值是否一致
        password =input("重新輸入加密金鑰:")
    with open('key.txt','r') as f:#讀取金鑰
      keyline = f.readline()
    with open(inputFile,'r') as f:
     line = f.readline()
    s = hashlib.sha256()#雜湊函數
    data=line
    data = str.encode(data)#將訊息轉為byte
    s.update(data)#更新雜湊對象
    h = s.hexdigest()#回傳雜湊值
    h=str.encode(h)#將資料型態轉為byte
    #password =input("輸入加密金鑰:")
    #while keyline!=password :#確認輸入金鑰值是否一致
    #    password =input("重新輸入加密金鑰:")

#print(password)
    key = PBKDF2(password, salt, dkLen=32)#將輸入金鑰放入AES函數產生真正的金鑰
    with open(inputFile2, "rb") as f:
        iv = f.read(16)         # 讀取 16 位元組的初始向量
        cipheredData = f.read() # 讀取其餘的密文

# 以金鑰搭配 CBC 模式與初始向量建立 cipher 物件
    cipher = AES.new(key, AES.MODE_CBC, iv=iv)

# 解密後進行 unpadding
    originalData = unpad(cipher.decrypt(cipheredData), AES.block_size)

# 輸出解密後的資料
    print("解密後的訊息摘要:",originalData)    
    print("從訊息產生的訊息摘要:",h)

    if h!=originalData:#確認是否遭竄改
        print("遭竄改")
    else:
        print("未遭竄改")    
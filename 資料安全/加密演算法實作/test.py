from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from Crypto.Protocol.KDF import PBKDF2
import hashlib
from Crypto.Util.Padding import unpad
# 固定的 salt
salt = b'\xd0\x18\xa7QM\xd6\x9b\xebxu\xe4\xed\xa8\x83\xf6\xa3/\x01\x9c\x9e\x86n\xda;\x10EdD\xf7\x932\xcc'

mag=""
for i in range(1,345):
    mag+="A"
for i in range(1,340):
    mag+='a'
for i in range(1,305):
    mag+='1'    

s = hashlib.sha256()
#print(hashlib.algorithms_available)
data = mag
data = str.encode(data)
s.update(data)
h = s.hexdigest()

h=str.encode(h)
print(h)

# 密碼
password = 'my#password'
outputFile='mac.txt'
# 根據密碼與 salt 產生金鑰
key = PBKDF2(password, salt, dkLen=32)
print(key)

cipher = AES.new(key, AES.MODE_CBC)

# 將輸入資料加上 padding 後進行加密
cipheredData = cipher.encrypt(pad(h, AES.block_size))

# 將初始向量與密文寫入檔案
with open(outputFile, "wb") as f:
    f.write(cipher.iv)
    f.write(cipheredData)

inputFile = 'mac.txt'

# 從檔案讀取初始向量與密文
with open(inputFile, "rb") as f:
    iv = f.read(16)         # 讀取 16 位元組的初始向量
    cipheredData = f.read() # 讀取其餘的密文

# 以金鑰搭配 CBC 模式與初始向量建立 cipher 物件
cipher = AES.new(key, AES.MODE_CBC, iv=iv)

# 解密後進行 unpadding
originalData = unpad(cipher.decrypt(cipheredData), AES.block_size)

# 輸出解密後的資料
print(originalData)    
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from Crypto.Protocol.KDF import PBKDF2
import hashlib
from Crypto.Util.Padding import unpad
import random 

mag=""#產生訊息
# 固定的 salt
salt = b'\xd0\x18\xa7QM\xd6\x9b\xebxu\xe4\xed\xa8\x83\xf6\xa3/\x01\x9c\x9e\x86n\xda;\x10EdD\xf7\x932\xcc'
message = '' 
chars = 'AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789' 
length = len(chars) - 1 
# 隨機產生訊息
for i in range(1000): 
 mag += chars[random.randint(0, length)] 
print("訊息:", mag) 




print(mag)
Upper = 0 
Lower = 0 
digital = 0 
for i in mag: 
 # 統計英文大寫
 if ord(i) >= 65 and ord(i) <= 90: 
  Upper += 1 
 # 統計英文小寫
 elif ord(i) >= 97 and ord(i) <= 122: 
  Lower += 1 
 # 統計數字
 else: 
  digital += 1 
print("英文大寫共有:", Upper) 
print("英文小寫共有:", Lower) 
print("數字共有:", digital) 
print("共有:", Upper+Lower+digital, "個字") 

f = open('my_massage.txt','w')#寫入訊息
f.write(mag)
f.close()

s = hashlib.sha256()#產生雜湊物件
#print(hashlib.algorithms_available)
data = mag
data = str.encode(data)#將訊息轉為byte
s.update(data)#更新雜湊對象
h = s.hexdigest()#回傳雜湊值
#print(h)
password =input("輸入加密金鑰:")

f = open('key.txt','w')#寫入金鑰
f.write(password)
f.close()

h=str.encode(h)#將資料型態轉為byte
print("產生訊息摘要:",h)
#print(h)

# 密碼
#password = 'my#password'
outputFile='mac.txt'
# 根據密碼與 salt 產生金鑰
key = PBKDF2(password, salt, dkLen=32)
print("加密金鑰:",key)

cipher = AES.new(key, AES.MODE_CBC)

# 將輸入資料加上 padding 後進行加密
cipheredData = cipher.encrypt(pad(h, AES.block_size))
print("加密訊息摘要:",cipheredData)
#print(cipheredData)
# 將初始向量與密文寫入檔案
with open(outputFile, "wb") as f:
    f.write(cipher.iv)
    f.write(cipheredData)




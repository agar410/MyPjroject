import base64
from pyDes import *
Des_Key = "BHC#@*UM" # Key
Des_IV = "\x22\x33\x35\x81\xBC\x38\x5A\xE7" # 自定IV向量
def DesEncrypt(str):
  k = des(Des_Key, CBC, Des_IV, pad=None, padmode=PAD_PKCS5)
  EncryptStr = k.encrypt(str)
  return base64.b64encode(EncryptStr) #轉base64編碼返回

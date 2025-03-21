import pandas as pd
from datetime import datetime
import time
import numpy as np

def enctry(s):
    k = 'djq%5cu#-jeq15abg$z9_i#_w=$o88m!*alpbedlbat8cr74sd'
    encry_str = ""
    for i,j in zip(s,k):
        # i為字元，j為祕鑰字元
        temp = str(ord(i)+ord(j))+'_' # 加密字元 = 字元的Unicode碼 + 祕鑰的Unicode碼
        encry_str = encry_str + temp
    return encry_str

# 解密
def dectry(p):
    k = 'djq%5cu#-jeq15abg$z9_i#_w=$o88m!*alpbedlbat8cr74sd'
    dec_str = ""
    for i,j in zip(p.split("_")[:-1],k):
        # i 為加密字元，j為祕鑰字元
        temp = chr(int(i) - ord(j)) # 解密字元 = (加密Unicode碼字元 - 祕鑰字元的Unicode碼)的單位元組字元
        dec_str = dec_str+temp
    return dec_str

def now_time():#紀錄時間
    date=datetime.now()
    t=datetime.strftime(date, '%Y-%m-%d %H:%M') 
    return t

def Sign_out(local_):#登入
    data = pd.read_excel("A_P.xls",index_col="User_Id") 
    data.loc[local_,"Login_Status"]=0
    data =data.to_excel("A_P.xls",na_rep=True)    

def Check_Login_Status(local_):#檢查登入狀態
    data = pd.read_excel("A_P.xls",index_col="User_Id") 
    if data.loc[local_,"Login_Status"]>0:
        print("重複登入，上次登入時間為",data.loc[local_,"Login_Time"])
        data.loc[local_,"Login_Time"]=now_time()
        data =data.to_excel("A_P.xls",na_rep=True)

    else:
        print("成功登入，上次登入時間為",data.loc[local_,"Login_Time"])
        data.loc[local_,"Login_Status"]+=1
        data.loc[local_,"Login_Time"]=now_time()
        data =data.to_excel("A_P.xls",na_rep=True)



def updatePassWord(oldPassWord,local_):#更新密碼
    data = pd.read_excel("A_P.xls",index_col="User_Id") 
    Decrypt_PassWord=dectry(data.loc[local_,"User_Password"])
    if oldPassWord == Decrypt_PassWord:
        newPassWord =input("輸入新密碼")
        check_new_passWord=input("輸入新密碼")
        if check_new_passWord == newPassWord:
            data.loc[local_,"User_Password"]=enctry(newPassWord)
            data =data.to_excel("A_P.xls",na_rep=True)
        else:
            Error_PassWord=0
            while Error_PassWord==0:
                newPassWord =input("重新輸入新密碼")
                check_new_passWord=input("重新輸入新密碼")
                if check_new_passWord == newPassWord:
                    Error_PassWord=1
            data.loc[local_,"User_Password"]=enctry(newPassWord) 
            data =data.to_excel("A_P.xls",na_rep=True)
    else:
        PassWord =input("輸入舊密碼")
        Decrypt_PassWord=dectry(data.loc[local_,"User_Password"])
        if PassWord != Decrypt_PassWord:
            oldPassWord_statue=0
            while oldPassWord_statue==0:
                PassWord =input("輸入舊密碼")
                if PassWord == Decrypt_PassWord:
                    oldPassWord_statue=1
        else:
            newPassWord =input("輸入新密碼")
            check_new_passWord=input("輸入新密碼")
            if check_new_passWord == newPassWord:
                data.loc[local_,"User_Password"]=enctry(newPassWord) 
                data =data.to_excel("A_P.xls",na_rep=True)
            else:  
                Error_PassWord=0  
                while Error_PassWord==0:
                    newPassWord =input("重新輸入新密碼")
                    check_new_passWord=input("重新輸入新密碼")
                    if check_new_passWord == newPassWord:
                        Error_PassWord=1
                data.loc[local_,"User_Password"]=enctry(newPassWord)    
                data =data.to_excel("A_P.xls",na_rep=True)      

def Sign_in():#登入
    Error_time=0
    data = pd.read_excel("A_P.xls",index_col="User_Id")
    print("*-----*------*")
    Account=input("輸入帳號:")
    PassWord=input("輸入密碼:")
    bool_=data["User_Account"].isin([Account])
    for i in range(0,bool_.shape[0]):
        if bool_[i]==True:
            Account_status=1
            local_=i
            break
        else:
            Account_status=0
    if Account_status==0:
        while Account_status==0:
            Error_time+=1
            if Error_time ==3:
                print("Error_time ==",Error_time)
                exit()
            print("帳號密碼錯誤，請重新輸入:")
            Account=input("請重新輸入帳號:")
            PassWord=input("請重新輸入密碼:")
            bool_=data["User_Account"].isin([Account])
            for i in range(0,bool_.shape[0]):
                if bool_[i]==True:
                    Account_status=1
                    local_=i
                    break
                else:
                     Account_status=0
        print("---*")
    if data.loc[local_,"User_Password"]==enctry(PassWord):
        #登入時間寫入
        data.loc[local_,"Login_Time"]=now_time()
        data =data.to_excel("A_P.xls",na_rep=True)    
        #print("登入成功")
        Check_Login_Status(local_)
        #P_U_D=input("是否要更新密碼(n/y):")
        return Account,PassWord
    else:
        PassWord_status=0
        while PassWord_status==0:
            Error_time+=1
            if Error_time ==3:
                print("Error_time ==",Error_time)
                exit()

            print("密碼錯誤，請重新輸入:")
            PassWord=input("請重新輸入密碼:")
            if data.loc[local_,"User_Password"]==enctry(PassWord):
                PassWord_status=1
        #登入時間寫入  
        data.loc[local_,"Login_Time"]=now_time()
        data =data.to_excel("A_P.xls",na_rep=True)    
        #print("登入成功")
        Check_Login_Status(local_)
        #P_U_D=input("是否要更新密碼(n/y):")
        return Account,PassWord

#讀取資料庫
data = pd.read_excel("A_P.xls",index_col="User_Id") 

lower_status=0
upper_status=0
digit_status=0
len_status=0
Account_status=0

YN=input("是否建立帳號(y/n):")#註冊帳戶
if YN=="y":
    Account=input("建立帳號:")
    bool_=data["User_Account"].isin([Account])
    for i in range(0,bool_.shape[0]):
        if bool_[i]==True:
            Account_status=1
            break
        else:
            Account_status=0 
    print("----",Account_status)
    if Account_status==1:
        while Account_status==1:
           Account=input("帳號重複，請重新輸入:")
           bool_=data["User_Account"].isin([Account])
           for i in range(0,bool_.shape[0]):
               if bool_[i]==True:
                   Account_status=1
                   break
               else:
                   Account_status=0 
        print("----------*",Account) 

    PassWord=input("輸入密碼:")
#密碼格式檢查
    for i in PassWord:
         if i.islower():
             lower_status=1
             break   
         else:
             lower_status=0

    for i in PassWord:
         if i.isupper():
             upper_status=1
             break
         else:
             upper_status=0
    for i in PassWord:
         if i.isdigit():
             digit_status=1
             break 
         else:
             digit_status=0

    if len(PassWord)>=8:
        len_status=1
    else:
        len_status=0
    check_passWord=1
    if lower_status==0 or upper_status==0 or digit_status==0  or len_status==0:
        while check_passWord==1:
            PassWord=input("格式錯誤，請重新輸入密碼:")
            for i in PassWord:
                if i.islower():
                    lower_status=1
                    break
                else:
                    lower_status=0
#---------------------------
            for i in PassWord:
                if i.isupper():
                    upper_status=1
                    break
                else:
                    upper_status=0
#---------------------------
            for i in PassWord:
                if i.isdigit():
                    digit_status=1
                    break
                else:
                    digit_status=0     
#---------------------------
            if len(PassWord)>=8:
                len_status=1
            else:
                len_status=0 
            if lower_status==1 and upper_status==1 and digit_status==1 and len_status==1:
                check_passWord=0    
            else:
                check_passWord=1
            #print("lower_status=",lower_status, " upper_status=",upper_status," digit_status=",digit_status,"  len_status=", len_status,len(PassWord),check_passWord)        
        #print("註冊成功,是否要登入帳號(y/n):") 
        #寫入data要做
        date=datetime.now()
        t=datetime.strftime(date, '%Y-%m-%d %H:%M')
        encryption_PassWord=enctry(PassWord)
        data.loc[data.index.size]=[Account,encryption_PassWord,t,0,0]#寫入資料庫
        data =data.to_excel("A_P.xls",na_rep=True)
        data = pd.read_excel("A_P.xls",index_col="User_Id")
        LG=input("是否要登入帳號(y/n):")               
    else:
        #print("註冊成功,是否要登入帳號(y/n):")
        #寫入data要做
        date=datetime.now()
        t=datetime.strftime(date, '%Y-%m-%d %H:%M')
        encryption_PassWord=enctry(PassWord)
        data.loc[data.index.size]=[Account,encryption_PassWord,t,0,0]  #寫入資料庫
        data =data.to_excel("A_P.xls",na_rep=True)    
        data = pd.read_excel("A_P.xls",index_col="User_Id")
        LG=input("是否要登入帳號(y/n):")       
else:
   #print("是否要登入帳號(y/n):")
   data =data.to_excel("A_P.xls",na_rep=True)
   data = pd.read_excel("A_P.xls",index_col="User_Id")
   LG=input("是否要登入帳號(y/n):")       
   #print("帳號:",Account,"密碼:",PassWord)

Error_time=0#失敗次數記錄
#登入帳戶
if LG == "y":
   print("y")
   Account=input("輸入帳號:")
   PassWord=input("輸入密碼:")
   bool_=data["User_Account"].isin([Account])
   for i in range(0,bool_.shape[0]):
       if bool_[i]==True:
           Account_status=1
           local_=i
           break
       else:
           Account_status=0
   if Account_status==0:
       while Account_status==0:
           Error_time+=1
           if Error_time ==3:
               print("Error_time ==",Error_time)
               exit()
           print("帳號密碼錯誤，請重新輸入:")
           Account=input("請重新輸入帳號:")
           PassWord=input("請重新輸入密碼:")
           bool_=data["User_Account"].isin([Account])
           for i in range(0,bool_.shape[0]):
               if bool_[i]==True:
                   Account_status=1
                   local_=i
                   break
               else:
                    Account_status=0
       print("---*")
   if data.loc[local_,"User_Password"]== enctry(PassWord):
       #登入時間寫入
       data.loc[local_,"Login_Time"]=now_time()
       data =data.to_excel("A_P.xls",na_rep=True)    
       #print("登入成功")
       Check_Login_Status(local_)
       P_U_D=input("是否要更新密碼(n/y):")
   else:
       PassWord_status=0
       while PassWord_status==0:
           Error_time+=1
           if Error_time ==3:
               print("Error_time ==",Error_time)
               print("以失敗3次，結束登入")
               exit()

           print("密碼錯誤，請重新輸入:")
           PassWord=input("請重新輸入密碼:")
           if data.loc[local_,"User_Password"]==enctry(PassWord):
               PassWord_status=1
       #登入時間寫入  
       data.loc[local_,"Login_Time"]=now_time()
       data =data.to_excel("A_P.xls",na_rep=True)    
       #print("登入成功")
       Check_Login_Status(local_)
       P_U_D=input("是否要更新密碼(n/y):")


else:
   print("n")

if LG=="y" and P_U_D=="y":
    print("y")
    oldPassWord=input("請輸入舊密碼:")#更新密碼
    updatePassWord(oldPassWord,local_)
    Sign_out(local_)
    print("以登出，請重新登入")
    #Account=input("輸入帳號:")
    #PassWord=input("輸入密碼:")
    Account,PassWord = Sign_in()#重新登入
    #print("y",Account,PassWord)
else:
    print("n")
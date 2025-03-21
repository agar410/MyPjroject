import requests
import time
import json
from bs4 import BeautifulSoup


PTT_URL = 'https://www.ptt.cc'


def get_web_page(url):
    resp = requests.get(
        url=url,
        cookies={'over18': '1'}  # 告知Server已回答過滿18歲的問題
    )
    if resp.status_code != 200:
        print('Invalid url:', resp.url)
        return None
    else:
        return resp.text


def get_articles(dom, date):
    soup = BeautifulSoup(dom, 'html5lib')

    # 取得上一頁的連結
    paging_div = soup.find('div', 'btn-group btn-group-paging')
    prev_url = paging_div.find_all('a')[1]['href']
    #check_Mon=['3','2']
    articles = []  # 儲存取得的文章資料
    divs = soup.find_all('div', 'r-ent')
    for d in divs:
        mon=d.find('div', 'date').text.strip().split("/", 1)
        #if  mon[0] == '3' or mon[0]=='2':  # 發文日期正確
        if  mon[0] == '3' or mon[0]=='4' :  # 發文日期正確            
            # 取得推文數
            push_count = 0
            push_str = d.find('div', 'nrec').text
            if push_str:
                try:
                    push_count = int(push_str)  # 轉換字串為數字
                except ValueError:
                    # 若轉換失敗，可能是'爆'或 'X1', 'X2', ...
                    # 若不是, 不做任何事，push_count 保持為 0
                    if push_str == '爆':
                        push_count = 99
                    elif push_str.startswith('X'):
                        push_count = -10

            # 取得文章連結及標題
            if d.find('a') :  # 有超連結，表示文章存在，未被刪除
                Issue_date =d.find('div', 'date').text.strip()
                href = d.find('a')['href']
                title = d.find('a').text
                author = d.find('div', 'author').text if d.find('div', 'author') else ''
                articles.append({
                    'title': title,
                    'href': href,
                    'push_count': push_count,
                    'author': author,
                    'Issue_date':Issue_date
                })
    return articles, prev_url


def get_author_ids(posts, pattern):
    ids = set()
    for post in posts:
        if pattern in post['author']:
            ids.add(post['author'])
    return ids


if __name__ == '__main__':
    current_page = get_web_page(PTT_URL + '/bbs/KoreaDrama/index.html')
    if current_page:
        articles = []  # 全部的今日文章
        today = time.strftime("%m").lstrip('0')  # 今天日期, 去掉開頭的 '0' 以符合 PTT 網站格式
        current_articles, prev_url = get_articles(current_page, today)  # 目前頁面的今日文章
        while current_articles:  # 若目前頁面有今日文章則加入 articles，並回到上一頁繼續尋找是否有今日文章
            articles += current_articles
            current_page = get_web_page(PTT_URL + prev_url)
            current_articles, prev_url = get_articles(current_page, today)


        # 印出所有不同的 5566 id
        # print(get_author_ids(articles, '5566'))
        check_list=['薛西弗斯的神話','怪物']
        num_list = {'薛西弗斯的神話': 0 , '怪物':0 , 'Penthouse/上流戰爭': 0 }
        # 儲存或處理文章資訊
        print('3~4月有', len(articles), '篇文章')
        threshold = 50
        print('搜尋文章關鍵字:',check_list,'Penthouse/上流戰爭')
        for a in articles:
            Issue_Date=a['Issue_date'].split("/", 1)
            for i in check_list:
               if i in a['title']  and Issue_Date[0]=='3':
                #print(a)
                num_list[i]+=a['push_count']
                if  a['push_count']>=99:
                  print('標題: ',a['title'],'作者',a['author'],'日期:',a['Issue_date'],'推文數:',a['push_count'])

        for a_3 in articles:
            Issue_Date_3=a_3['Issue_date'].split("/", 1)
            if 'Penthouse' in a_3['title'] and Issue_Date_3[0]=='3'  or '上流戰爭' in a_3['title']  and Issue_Date_3[0]=='3':
                #print(a)
                num_list['Penthouse/上流戰爭']+=a_3['push_count']
                if  a_3['push_count']>=99:
                 print('標題: ',a_3['title'],'作者',a_3['author'],'日期:',a_3['Issue_date'],'推文數:',a_3['push_count'])        
        
        sum=0
        for a_2 in articles:
            Issue_Date_2=a_2['Issue_date'].split("/", 1)
            #print('3月有',Issue_Date_2[0])
            if  Issue_Date_2[0]=='3':
                sum+=1
        print('3月有', sum, '篇文章')
        with open('gossiping.json', 'w', encoding='utf-8') as f:
            json.dump(articles, f, indent=2, sort_keys=True, ensure_ascii=False)

        rank_list=sorted(num_list.items(),key = lambda item:item[1])
       # print ('人氣統計: ',sorted(num_list.items(),key = lambda item:item[1]))
        print ('人氣統計: ')
    for k in range(0,3):
        print (k+1,rank_list[2-k])

        
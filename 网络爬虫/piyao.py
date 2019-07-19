from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options
import requests
import time
import os
import re
import platform
from lxml import etree
from datetime import datetime


chrome_options = Options()
chrome_options.add_argument('--headless')
# chrome_options.add_argument('--disable-gpu')
driver = webdriver.Chrome(chrome_options=chrome_options, \
    executable_path= "chromedriver.exe")


#加载界面
driver.get("http://piyao.sina.cn/")
time.sleep(3)


#逐渐滚动浏览器窗口，令ajax逐渐加载
for i in range(0,40):
    driver.execute_script('window.scrollTo(0, document.body.scrollHeight)')
    i += 1
    time.sleep(4)


#获取网页代码
html = driver.page_source

driver.quit()


# 解析源码，获取需要数据
Ohtml = etree.HTML(html)

total_yaoyan_lis = list()

index = 0
while True:
    index = index+1
    date = Ohtml.xpath('//body/div[1]/div[1]/div[3]/div[1]/div[%s]/div[1]/text()'%str(index))
    titles = Ohtml.xpath('//body/div[1]/div[1]/div[3]/div[1]/div[%s]/ul/li/a/div/div[1]/text()'%str(index))
    comments = Ohtml.xpath('//body/div[1]/div[1]/div[3]/div[1]/div[%s]/ul/li/a/div/div[2]/div[2]/text()'%str(index))
    likes = Ohtml.xpath('//body/div[1]/div[1]/div[3]/div[1]/div[%s]/ul/li/a/div/div[2]/div[4]/text()'%str(index))

    # 可修改 这里是获取5月至当前月的辟谣新闻信息
    if date[0][7]=='4':
        print(date)
        break

    titles = [i[4:] for i in titles]
    comments = [int(i) for i in comments]
    likes = [int(i) for i in likes]

    length = len(titles)

    yaoyan = zip(date*length,titles,comments,likes)
    yaoyan = [i for i in yaoyan]
    
    total_yaoyan_lis.extend(yaoyan)


# 按照点赞数和评论数高低排序
high_comments = sorted(total_yaoyan_lis, key=lambda x : x[2], reverse = True)
high_likes = sorted(total_yaoyan_lis, key=lambda x : x[3], reverse = True)


# 输出结果
print("\n\n\n\n\n\n近三个月评论数前十：\n")
for x in high_comments[:10]:
    print("日期： ", x[0], '\t', "标题： ",x[1], '\t',"评论数： ", x[2], '\t', "评论数： ", x[3])

print("\n\n\n\n\n\n近三个月点赞数前十：\n")
for x in high_likes[:10]:
    print("日期： ", x[0], '\t', "标题： ", x[1], '\t',"评论数： ", x[2], '\t',"评论数： ", x[3])

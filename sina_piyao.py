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
for i in range(0,4):
    driver.execute_script('window.scrollTo(0, document.body.scrollHeight)')
    i += 1
    time.sleep(4)

html = driver.page_source

driver.quit()

Ohtml = etree.HTML(html)
dates = Ohtml.xpath('//body/div[1]/div[1]/div[3]/div[1]/div/div[1]/text()')
titles = Ohtml.xpath('//body/div[1]/div[1]/div[3]/div[1]/div/ul/li/a/div/div[1]/text()')
opinions = Ohtml.xpath('//body/div[1]/div[1]/div[3]/div[1]/div/ul/li/a/div/div[2]/div[2]/text()')
likes = Ohtml.xpath('//body/div[1]/div[1]/div[3]/div[1]/div/ul/li/a/div/div[2]/div[4]/text()')

titles = [i[4:] for i in titles]
opinions = [int(i) for i in opinions]
likes = [int(i) for i in likes]

opinions_and_likes = zip(titles,opinions,likes)
opinions_and_likes = [i for i in opinions_and_likes]

# print(opinions_and_likes)

high_likes = sorted(opinions_and_likes, key=lambda x : x[2], reverse = True)
high_opinions = sorted(opinions_and_likes, key=lambda x : x[1], reverse = True)

print("\n\n\n\n\n\n点赞数前十：\n")
for x in high_likes[:10]:
    print(x[0], '\t', x[1],'\t', x[2])
print("\n\n\n\n\n\n评论数前十：\n")
for x in high_opinions[:10]:
    print( x[0], '\t', x[1],'\t', x[2])

# print(dates)
# print(titles)
# print(opinions)
# print(likes)

# print(len(dates))
# print(len(titles))
# print(len(opinions))
# print(len(likes))
/html/body/div[1]/div[1]/div[3]/div[1]/div[3]/div[1]
/html/body/div[1]/div[1]/div[3]/div[1]/div[3]/ul/li[1]/a/div[1]/div[1]


/html/body/div[1]/div[1]/div[3]/div[1]
                                新闻总体div
/html/body/div[1]/div[1]/div[3]/div[1]      /div[2]
                                            # 整个日期div
/html/body/div[1]/div[1]/div[3]/div[1]      /div[2]     /div[1]
                                                        #日期div
/html/body/div[1]/div[1]/div[3]/div[1]      /div[2]     /ul/li[1]/a    /div[1]           /div[1]
                                                        #当日新闻列表   #当前新闻的div   #当前新闻标题的div
/html/body/div[1]/div[1]/div[3]/div[1]      /div[2]     /ul/li[1]/a    /div[1]           /div[2]                     /div[2]
                                                                                        #当前新闻评论和点赞的总div    #当前新闻评论数
/html/body/div[1]/div[1]/div[3]/div[1]      /div[2]     /ul/li[1]/a    /div[1]           /div[2]                     /div[4]
                                                                                                                    #当前新闻点赞数

/html/body/div[1]/div[1]/div[3]/div[1]/div[2]/div[i]

/html/body/div[1]/div[1]/div[3]/div[1]      /div[3]/div[1]

$x('//div[@class="zy_day" and position()=2]/div[@class="day_date"]/following-sibling::ul//div[@class="left_title"]')
#coding=utf-8

import requests

ssid=input("search id?")
response = requests.get("http://www.baidu.com/s?wd="+ssid)

print(response.content.decode(encoding='utf-8',errors='ignore'))


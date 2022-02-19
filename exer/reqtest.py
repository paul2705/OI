import requests
from bs4 import BeautifulSoup

cookies = {
    'Hm_lpvt_aec699bb6442ba076c8981c6dc490771': '1631770139',
    'Hm_lvt_aec699bb6442ba076c8981c6dc490771': '1631240527,1631770139',
    'BDORZ': 'FFFB88E999055A3F8A630C64834BD6D0',
    'BDSVRTM': '0',
    'BD_UPN': '143254',
    'H_PS_645EC': '7dd0sWD1kUvIAuYL2w6jvd91u0TvHsZiux7j8Ayx%2FagiF%2FgGv8KgTNnI%2BVSqDDAjee%2BkiA',
    'H_PS_PSSID': '34650_34447_31254_34655_33848_34599_34585_34092_34517_26350_34423_34555_34691_34670',
    'ispeed_lsm': '2',
    '__yjs_duid': '1_0e6ea08694e3465ee897e2709c5e2ba31631197101301',
    'BAIDUID': '3C0B37799EF15C4EDA07E6E18C0509DC:FG=1',
    'BIDUPSID': '0B0C6DF920F7864624E13891D3685A6C',
    'PSTM': '1631196428',
}

headers = {
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
    'Host': 'www.baidu.com',
    'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_4) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/13.1 Safari/605.1.15',
    'Accept-Language': 'en-us',
    'Accept-Encoding': 'gzip, deflate, br',
    'Connection': 'keep-alive',
}

ssid=input("Type your ssid:")

response = requests.get('https://www.baidu.com/s?wd='+ssid, headers=headers, cookies=cookies)

doc=response.content

html_doc=doc.decode(encoding='utf-8',errors='ignore')
soup=BeautifulSoup(html_doc, 'html.parser' )
allwanted=soup.find_all('h3')
for s in allwanted:
    print(s.get_text().strip())

#with open("test.html","wb") as ff:
#	ff.write(doc)

#NB. Original query string below. It seems impossible to parse and
#reproduce query strings 100% accurately so the one below is given
#in case the reproduced version is not "correct".
# response = requests.get('https://www.baidu.com/s?wd=dasd', headers=headers, cookies=cookies)


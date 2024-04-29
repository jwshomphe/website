import requests
from bs4 import BeautifulSoup
import pandas as pd

url = 'https://openrss.org/www.grailed.com/designers/rick-owens'
resp = requests.get(url)
soup = BeautifulSoup(resp.text, 'html.parser')

output = []
for entry in soup.find_all('entry'):

    item = {
        'Title': entry.find('title', {'type': 'html'}).text,
        'Pubdate': entry.find('published').text,
        'Content': entry.find('content').text,
        'Link': entry.find('link')['href']
    }

    output.append(item)


df = pd.DataFrame(output)

df.to_csv('results/results_feed01.csv', index=False)
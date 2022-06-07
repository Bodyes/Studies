#improvising in home

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options

CHROME_PATH = 'C:\Program Files\Google\Chrome\Application\chrome.exe'
CHROMEDRIVER_PATH = 'chromedriver'
WINDOW_SIZE = '1920,1080'

chrome_options = Options()
chrome_options.add_argument("--headless")
chrome_options.add_argument("--window-size=%s" % WINDOW_SIZE)
chrome_options.binary_location = CHROME_PATH

name = input("Enter username of person whose you want to check follower count: \n")

url = 'https://twitter.com/' + name

browser = webdriver.Chrome(options=chrome_options)
browser.get(url)

followers = browser.find_element(By.XPATH, value='//*[@id="react-root"]/div/div/div[2]/main/div/div/div/div[1]/div/div[2]/div/div/div/div/div[4]/div[2]/a/span[1]/span').text

print(followers + '\n')

print('Done!')

browser.close()

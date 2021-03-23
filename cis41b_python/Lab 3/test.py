
import requests 
from bs4 import BeautifulSoup
import re
import pickle
import json
import sqlite3

url = "battery-report.html"
page = requests.get(url)

self._soup = BeautifulSoup(page.content, "lxml")
# -*- coding: utf-8 -*-
from urllib.request import urlopen
from bs4 import BeautifulSoup
import sys
import os
import re

INPUT_FILE_NAME = "input.txt"
DELIMITER = "---"


def main():
    # expected url format
    # https://atcoder.jp/contests/abc275/tasks/abc275_a
    try:
        url = sys.argv[1]
    except IndexError:
        print("input problem url")
        url = input()

    html = urlopen(url)

    # with open("example.html") as f:
    #     html = f.read()

    soup = BeautifulSoup(html, "html.parser")
    name = soup.find("title").contents[0].split(" ")[0]
    os.makedirs(name, exist_ok=True)

    input_example_tags = soup.find_all(True, string=re.compile(".*入力例.*"))
    with open(f"{name}/input.txt", "w") as f:
        for t in input_example_tags:
            f.write(t.next_sibling.get_text())
            f.write("\n")

    output_example_tags = soup.find_all(True, string=re.compile(".*出力例.*"))
    with open(f"{name}/output.txt", "w") as f:
        for t in output_example_tags:
            f.write(t.next_sibling.get_text())


if __name__ == '__main__':
    main()

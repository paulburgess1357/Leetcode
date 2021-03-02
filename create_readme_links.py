# Simple python script to create a readme table with links in alphabetical order
import os

BASE_FOLDER = "c:/users/paulb/desktop/git_projects/Leetcode/Leetcode/ArrayProblems/"
BASE_LINK = "https://github.com/paulburgess1357/Leetcode/blob/master/Leetcode/ArrayProblems/"
OUTPUT = "c:/users/paulb/desktop/git_projects/Leetcode/markdown_links.txt"

files = sorted(os.listdir(BASE_FOLDER))

file_links = []
for i in range(len(files)):
    link_index = "#### " + str(i + 1) + ".  "
    link_name = "[" + files[i].split(".")[0] + "]"
    full_link = BASE_LINK + "/" + files[i]
    file_links.append(link_index + link_name + "(" + full_link + ")")

with open(OUTPUT, 'w') as file:
    for link in file_links:
        file.write('%s\n' % link)









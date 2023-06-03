import os
import pathlib

python_file_path = pathlib.Path(__file__).parent
os.chdir(python_file_path)

file = open("index.html")
outfile = open("html.h", "w")
outfile.writelines("const char *html =\n")
for line in file:
    formated = line.replace("\"", "\\\"").replace("\n", "\\n")
    outfile.writelines(f"    \"{formated}\"\n")
outfile.writelines(";")

file.close()
outfile.close()

import sys, os
import re
import hashlib

def compute_sha1_modulo(string, modulo_value=10000000):
    sha1_hash = hashlib.sha1(string.encode()).hexdigest()
    decimal_hash = int(sha1_hash, 16)  # Convert hexadecimal hash to decimal
    result = decimal_hash % modulo_value
    return str(result)

def read_file_to_string(file_path):
    try:
        with open(file_path, 'r') as file:
            file_content = file.read()
        return file_content
    except FileNotFoundError:
        return "File not found."
    except Exception as e:
        return f"An error occurred: {str(e)}"

def replace_inline(input_string):
    #if re.match("叏", input_string) != None:
    new_string = re.sub(r"\\inline\{((?:\\\}|[^}])*)\}", r"叏\1叏", input_string)
    return new_string

def move_code(input_string):
    cpps = re.findall(r"\\begin\{C\+\+\}([\s\S]*?)\\end\{C\+\+\}", input_string)
    for text in cpps:
        #print(text)
        #path = input("Which section/subsection should this code be in? e.g. BasicDataStructure/Intro ")
        #fullpath = os.path.join(content_path,path, compute_sha1_modulo(text) + ".cpp")
        fullpath = os.path.join(content_path, compute_sha1_modulo(text) + ".cpp")

        with open(fullpath, 'w+') as file:
            file.write(text)
    def rep_function(match):
        capture_group = compute_sha1_modulo(match.group(1))  # Get the captured group
        replacement = f"\\begin{{C++}}{capture_group}\\end{{C++}}"
        return replacement
    new_string = re.sub(r"\\begin\{C\+\+\}([\s\S]*?)\\end\{C\+\+\}", rep_function,input_string)
    return new_string


if __name__ == "__main__":
    file_path = sys.argv[1]
    main_path = sys.argv[2] #path to nocodenolife-handout directory
    #content_path = os.path.join(sys.argv[3], "content")
    script_dir = os.path.dirname(__file__)
    content_path = os.path.join(script_dir, "refcode")

    full_file_path = os.path.join(main_path, "content", file_path)
    content = read_file_to_string(full_file_path)
    content = replace_inline(content)
    content = move_code(content);
    
    filename = os.path.split(full_file_path)[1].removesuffix(".tex")
    tex_path = os.path.join(os.path.dirname(full_file_path), filename + "_convert.tex")
    with open(tex_path, 'w+') as file:
        file.write(content)

    main_tex = read_file_to_string(os.path.join(main_path, "main.tex"))
    conv_path = os.path.join(main_path, "convert.tex");
    print(content)

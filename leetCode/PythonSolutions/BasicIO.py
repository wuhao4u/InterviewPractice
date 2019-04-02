
def file_io():
    r_text = open("wuhao4u.txt", 'r')

    for line in r_text:
        print(line)
    r_text.close()


    with open("wuhao4u.txt", 'r') as r_file:
        with open("test.txt", 'w') as w_file:
            for line in r_file:
                w_file.write(line.strip())


def console_io():
    m_str = input()
    print(m_str)

def console_multiple_lines():
    print("Enter/Paste your content. Ctrl-D or Ctrl-Z ( windows ) to save it.")
    contents = []
    while True:
        try:
            line = input()
        except EOFError:
            print(' '.join(contents))
            break
        contents.append(line) 

def split_string(m_str):
    print(m_str.split())
    print(m_str.split(','))
    print(m_str.split("'"))

def length(whatever):
    print(len(whatever))

def two_d_arrays():
    two_d = [[]]

def cmd_line_args():
    pass


if __name__ == "__main__":
    # file_io()
    # console_io()
    # console_multiple_lines()
    # split_string("I'm a string with spaces, and comma.")
    length("length")

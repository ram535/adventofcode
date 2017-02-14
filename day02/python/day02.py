""" day02 """


def main():
    """ main """
    board = ["     ", " 123 ", " 456 ", " 789 ", "     "]
    row_coord = 1
    col_coord = 1
    code = ""

    # open the file in read mode
    the_data = open("../input.dat", "r")

    # loop one line at a time
    for line in the_data.readlines():
        j = 0
        while j < len(line):
            row_dir = 0
            col_dir = 0

            if line[j] == 'U':
                row_dir = -1
            elif line[j] == 'D':
                row_dir = 1
            elif line[j] == 'L':
                col_dir = -1
            elif line[j] == 'R':
                col_dir = 1

            if board[row_coord + row_dir][col_coord + col_dir] != ' ':
                row_coord = row_coord + row_dir
                col_coord = col_coord + col_dir
            j = j + 1

        code = code + board[row_coord][col_coord]
    print(code)


if __name__ == '__main__':
    main()

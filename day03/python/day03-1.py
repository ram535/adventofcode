""" day 1 part 1 """


def main():
    """ main """

    with open('../input.txt') as file:
        # .strip() removes all whitespace at the start and end,
        # including spaces, tabs, newlines and carriage returns.
        data = file.read().strip()

    triangles = [[int(num) for num in line.split()]
                 for line in data.split('\n')]
    counter = 0
    for triangle in triangles:
        a = triangle[0]
        b = triangle[1]
        c = triangle[2]
        if (a + b) > c and (a + c) > b and (b + c) > a:
            counter += 1

    print(counter)


if __name__ == '__main__':
    main()

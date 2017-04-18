""" day 3 part 2 """


# import pdb


def main():
    """ main """

    # pdb.set_trace()
    with open('../input.txt') as file:
        # .strip() removes all whitespace at the start and end,
        # including spaces, tabs, newlines and carriage returns.
        data = file.read().strip()

    triangles = [[int(num) for num in line.split()]
                 for line in data.split('\n')]
    counter = 0
    for j in range(3):
        for i in range(len(triangles)):
            if i % 2 == 0:
                a = triangles[i][0]
                b = triangles[i - 1][1]
                c = triangles[i - 2][2]
                if (a + b) > c and (a + c) > b and (b + c) > a:
                    counter += 1
        j = 0
    print(counter)


if __name__ == '__main__':
    main()

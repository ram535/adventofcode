""" day01 """


def main():
    """ main """
    directions = [0, 0, 0, 0]
    direction = 0

    with open('../input.dat') as file:
        data = file.read()

    tokens = data.split(', ')
    for token in tokens:
        letter = token[0]
        number = int(token[1:])
        print(number)
        if letter == 'L':
            direction -= 1
        else:
            direction += 1
        direction %= len(directions)
        directions[direction] += number

    print(abs(directions[0] - directions[2]) +
          abs(directions[1] - directions[3]))


if __name__ == '__main__':
    main()

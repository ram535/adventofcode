""" day01 part 1 """


def main():
    """ main """
    blocks_per_direction = [0, 0, 0, 0]
    compass = 0

    with open('../input.dat') as file:
        data = file.read()

    instructions = data.split(', ')
    for instruction in instructions:
        blocks = int(instruction[1:])
        if instruction[0] == 'L':
            compass -= 1
        else:
            compass += 1
        compass %= len(blocks_per_direction)
        blocks_per_direction[compass] += blocks

    print(abs(blocks_per_direction[0] - blocks_per_direction[2]) +
          abs(blocks_per_direction[1] - blocks_per_direction[3]))


if __name__ == '__main__':
    main()

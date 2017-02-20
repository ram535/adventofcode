""" day01-2 """


FACTORS = ((0, 1),   # turning right, N
           (1, 0),   # E
           (0, -1),  # S
           (-1, 0))   # W


def get_distance(data):
    """ get_distance """
    compass = 0
    # initial location
    location = (0, 0)
    memorize_location = set(location)

    instructions = data.split(', ')
    for instruction in instructions:
        if instruction[0] == 'L':
            compass -= 1
        else:
            compass += 1

        compass %= 4

        blocks = int(instruction[1:])
        for _ in range(blocks):
            location = (location[0] + FACTORS[compass][0],
                        location[1] + FACTORS[compass][1])

            if location in memorize_location:
                distance = abs(location[0]) + abs(location[1])
                return distance
            memorize_location.add(location)
            print(location)

    return "Error"


def main():
    """ main """

    with open('../input.dat') as file:
        data = file.read()
    print(get_distance(data))


if __name__ == '__main__':
    main()

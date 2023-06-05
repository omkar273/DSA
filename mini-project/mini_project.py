import random

BOARD_SIZE = 100
NUM_SNAKES = 3
NUM_LADDERS = 3


def roll_dice():
    return random.randint(1, 6)


def check_win(position):
    return position >= BOARD_SIZE


def check_snakes_ladders(position):
    snakes = {16: 6, 47: 26, 49: 11}
    ladders = {3: 22, 5: 8, 20: 29}

    if position in snakes:
        print("Oops! You got bitten by a snake.")
        position = snakes[position]

    if position in ladders:
        print("Great! You found a ladder.")
        position = ladders[position]

    return position


def initialize_board():
    board = list(range(1, BOARD_SIZE + 1))
    return board


def play_game(player1_name, player2_name):
    print("Welcome to Snake and Ladders!")
    board = initialize_board()
    player_positions = {player1_name: 0, player2_name: 0}

    while True:
        # Player 1's turn
        input(player1_name + ", press Enter to roll the dice.")
        dice_roll = roll_dice()
        print(player1_name + " rolled a", dice_roll)
        player_positions[player1_name] += dice_roll
        player_positions[player1_name] = check_snakes_ladders(
            player_positions[player1_name])
        player_positions[player1_name] = min(
            player_positions[player1_name], BOARD_SIZE)
        print(player1_name + ", you are now at position",
              player_positions[player1_name])

        if check_win(player_positions[player1_name]):
            print("Congratulations, " + player1_name + "! You won the game!")
            break

        # Player 2's turn
        input(player2_name + ", press Enter to roll the dice.")
        dice_roll = roll_dice()
        print(player2_name + " rolled a", dice_roll)
        player_positions[player2_name] += dice_roll
        player_positions[player2_name] = check_snakes_ladders(
            player_positions[player2_name])
        player_positions[player2_name] = min(
            player_positions[player2_name], BOARD_SIZE)
        print(player2_name + ", you are now at position",
              player_positions[player2_name])

        if check_win(player_positions[player2_name]):
            print("Congratulations, " + player2_name + "! You won the game!")
            break


# Main program
print("Snake and Ladders Game")
player1_name = input("Enter the name of Player 1: ")
player2_name = input("Enter the name of Player 2: ")
play_game(player1_name, player2_name)

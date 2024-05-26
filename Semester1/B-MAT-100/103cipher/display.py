##
## EPITECH PROJECT, 2022
## B-MAT-100-STG-1-1-103cipher-florent.guittre
## File description:
## display
##

def display_key(key):
    key_len = len(key)
    print("Key matrix:")
    for i in range(key_len):
        for j in range(key_len):
            if (key[i][j] - 100 < 0 and key[i][j] - 10 < 0 and j != 2):
                print(key[i][j], end='      ')
            elif (key[i][j] - 100 < 0 and key[i][j] - 10 >= 0 and j != 2):
                print(key[i][j], end='     ')
            elif (j != 2):
                print(key[i][j], end='    ')
            else:
                print(key[i][j], end='')
        print()

def display_key_float(key):
    key_len = len(key)
    print("Key matrix:")
    for i in range(key_len):
        for j in range(key_len):
            if (key[i][j] - 100 < 0 and key[i][j] - 10 < 0 and j != 2 and key[i][j] != 0 and key[i][j] > 0):
                print(f"{key[i][j]:.3f}", end='   ')
            elif (key[i][j] - 100 < 0 and key[i][j] - 10 >= 0 and j != 2 and key[i][j] != 0 and key[i][j] > 0):
                print(f"{key[i][j]:.3f}", end='  ')
            elif (j != 2 and key[i][j] != 0 and key[i][j] > 0):
                print(f"{key[i][j]:.3f}", end=' ')
            elif (key[i][j] != 0 and key[i][j] > 0):
                print(f"{key[i][j]:.3f}", end='')
            elif (key[i][j] == 0):
                print("0.0", end='     ')
            else:
                print(f"{key[i][j]:.3f}", end='')
                if (j != 2):
                    print("  ", end='')
        print()

def display_new_message(message, flag):
    offset = 0
    if (flag == 0):
        print("Encrypted message:")
    else:
        print("Decrypted message:")
    for i in range(len(message) - offset):
        if (i == len(message) - offset - 1):
            if (flag == 1):
                message[i] = chr(int(message[i]))
            else:
                message[i] = int(message[i])
            print(message[i], end='\n')
        else:
            if (flag == 1):
                message[i] = chr(int(message[i]))
            else:
                message[i] = str(int(message[i])) + " "
            print(message[i], end='')

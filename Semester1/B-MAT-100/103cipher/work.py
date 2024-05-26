##
## EPITECH PROJECT, 2022
## B-MAT-100-STG-1-1-103cipher-florent.guittre
## File description:
## encrypt_decrypt
##

import display
import matrice
import sys

def encrypt(message, key):
    key_buffer = matrice.fill_key_buffer(key, len(key))
    message_buffer = matrice.fill_message_buffer(message, len(message), len(key_buffer), 0)
    final_matrix_arr = matrice.multiply_matrices(message_buffer, key_buffer)
    display.display_key(key_buffer)
    print()
    display.display_new_message(final_matrix_arr, 0)
def decrypt(encrypted_message, key):
    key_buffer = matrice.fill_key_buffer(key, len(key))
    inverted_matrix = matrice.invert_matrix(key_buffer)
    display.display_key_float(key_buffer)
    print()
    encrypted_message = encrypted_message.split(' ')
    for i in range(len(encrypted_message)):
        try:
            encrypted_message[i] = int(encrypted_message[i])
        except:
            sys.exit(84)
    message_buffer = matrice.fill_message_buffer(encrypted_message, len(encrypted_message), len(key_buffer), 1)
    final_matrix_arr = matrice.multiply_matrices(message_buffer, inverted_matrix)
    display.display_new_message(final_matrix_arr, 1)

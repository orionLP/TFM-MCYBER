
def get_signed_int(number: int, original_bytes_lenght: int):
    if original_bytes_lenght == 1:
        if number >= 0x80:
            return (0x100 - number) * (-1)
        else:
            return number
    elif original_bytes_lenght == 2:
        if number >= 0x8000:
            return (0x10000 - number) * (-1)
        else:
            return number
    elif original_bytes_lenght == 4:
        if number >= 0x80000000:
            return (0x100000000 - number) * (-1)
        else:
            return number
    raise ValueError('get_signed_int has been given a original_bytes_length it does not support')
